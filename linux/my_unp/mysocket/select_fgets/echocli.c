#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<signal.h>

#include <errno.h>

#define max(x,y) ((x) > (y) ? (x) : (y))



typedef void Sigfunc(int);
    Sigfunc *
signal(int signo, Sigfunc *func);
void handle_pipe(int sig);
ssize_t readline(int sockfd, void *buf, size_t maxline);
ssize_t writen(int fd, const void *buf, size_t count);
void str_cli(FILE *fp, int sockfd);


int main(int argc, char* argv[])
{
    signal(SIGPIPE, handle_pipe);


    int sockconn;
    struct sockaddr_in servaddr;

    if ((sockconn = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    {
        perror("socket failure");
        exit(EXIT_FAILURE);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8888);
    if(argv[1] == NULL)
    {
        argv[1] = "127.0.0.1";
    }
    if (inet_aton(argv[1], &servaddr.sin_addr) == 0)
    {
        perror("inet_aton error");
        exit(EXIT_FAILURE);
    }

    if (connect(sockconn, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("connnect error");
        exit(EXIT_FAILURE);
    }
    str_cli(stdin, sockconn);

    //close(sockconn); // 这里即使不close，在进程关闭的时候，仍然会会关闭
    return 0;
}

void str_cli(FILE *fp, int sockconn)
{
    int maxfdp1, retval;
    fd_set rset;
    char recvline[1024];
    char sendline[1024];
    FD_ZERO(&rset);
    while(1){
        FD_SET(fileno(fp), &rset);
        FD_SET(sockconn, &rset);
        maxfdp1 = max(fileno(fp), sockconn) + 1;

        fprintf(stderr, "select........\n");
        retval = select(maxfdp1, &rset, NULL, NULL, NULL);

        if (retval == -1)
        {
            perror("select()");
            exit(EXIT_FAILURE);
        }
        if (FD_ISSET(sockconn, &rset))
        {
            //  本例子的目的是为了解决，服务器关闭之后能立即收到FIN，
            // 但是不能达到目的
            fprintf(stderr, "readline........\n");
            int ret = readline(sockconn, recvline, sizeof(recvline));
            //int ret = read(linesockconn, recvline, sizeof(recvline));
            if (ret > 0)
                fputs(recvline, stdout);
            else if (ret == 0) // 已经写往服务器了，所以应该收到数据，如果返回0，说明服务器已经过早终止了
            {
                perror("str_cli: server terminated prematurely");
                exit(EXIT_FAILURE);
            }
            else
            {
                perror("read error");
                exit(EXIT_FAILURE);
            }
        }
        if (FD_ISSET(fileno(fp), &rset))
        {
            //  混合使用stdio 和 select 不能达到目的
            // 如果从文件度，这里是全缓冲的，导致 很多行被缓存在stdio中的缓冲区中，
            // 已可用的文本输入行被读入到stdio在用的缓冲区中
            // 而fgets 只返回其中的第一行，其余输入行仍在stdio缓冲区中，
            // 随后select 再次被调用以等待新的工作，而不管stdio换成区中有额外的输入行待消费
            // 究其原因在于select 不知道stdio使用了缓冲区--它只是从read系统调用的角度支出是否有数据可读，
            // 而不是从fgets之类调用的角度考虑
            fprintf(stderr, "fgets........\n");
            char * tmp = fgets(sendline, sizeof(sendline), stdin); // 键入EOF时，fgets返回一个空指针
            fprintf(stderr, "fgets from stdin........:%s\n", sendline);
            if (tmp != NULL)
            {
                int retw = 0;
                fprintf(stderr, "write........\n");
                if ((retw = write(sockconn, sendline, strlen(sendline))) < 0)
                {
                    perror("write to socket error");
                    exit(EXIT_FAILURE);
                }

                fprintf(stderr, "after write........\n");
            }
            else // 键入EOF时也返回空指针 ,程序结束
            {
                fprintf(stderr, "get EOF........\n");
                break;
            }

        }

    }

}
void handle_pipe(int sig)
{
    printf("receive pipe!\n");
}
ssize_t recv_peek(int sockfd, void *buf, size_t len)
{
    while (1)
    {
        int ret = recv(sockfd, buf, len, MSG_PEEK);
        if (ret == -1 && errno == EINTR)
            continue;
        return ret;
    }
}

ssize_t writen(int fd, const void *buf, size_t count)
{
    size_t nleft = count;
    ssize_t nwritten;
    char *bufp = (char*)buf;

    while (nleft > 0)
    {
        if ((nwritten = write(fd, bufp, nleft)) < 0)
        {
            if (errno == EINTR)
                continue;
            return -1;
        }
        else if (nwritten == 0)
            continue;

        bufp += nwritten;
        nleft -= nwritten;
    }

    return count;
}


ssize_t readn(int fd, void *buf, size_t count)
{
    size_t nleft = count;
    ssize_t nread;
    char *bufp = (char*)buf;

    while (nleft > 0)
    {
        if ((nread = read(fd, bufp, nleft)) < 0)
        {
            if (errno == EINTR)
                continue;
            return -1;
        }
        else if (nread == 0)
            return count - nleft;

        bufp += nread;
        nleft -= nread;
    }

    return count;
}

ssize_t readline(int sockfd, void *buf, size_t maxline)
{
    int ret;
    int nread;
    char *bufp = buf;
    int nleft = maxline;
    while (1)
    {
        ret = recv_peek(sockfd, bufp, nleft);
        if (ret < 0)
            return ret;
        else if (ret == 0)
            return ret;

        nread = ret;
        int i;
        for (i=0; i<nread; i++)
        {
            if (bufp[i] == '\n')
            {
                ret = readn(sockfd, bufp, i+1);
                if (ret != i+1)
                    exit(EXIT_FAILURE);

                return ret;
            }
        }

        if (nread > nleft)
            exit(EXIT_FAILURE);

        nleft -= nread;
        ret = readn(sockfd, bufp, nread);
        if (ret != nread)
            exit(EXIT_FAILURE);

        bufp += nread;
    }

    return -1;
}

    Sigfunc *
signal(int signo, Sigfunc *func)
{
    struct sigaction act, oact;

    act.sa_handler = func;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    if (signo == SIGALRM)
    {
#ifdef SA_INTERRUPT
        act.sa_flags |= SA_INTERRUPT;
#endif
    }
    else
    {
#ifdef SA_RESTART
        act.sa_flags |= SA_RESTART;
#endif
    }

    if (sigaction(signo, &act, &oact) < 0)
        return SIG_ERR;
    return oact.sa_handler;

}

