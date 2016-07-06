
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<signal.h>


void handle_pipe(int sig);
int main(int argc, char* argv[])
{
    struct sigaction action;
    action.sa_handler = handle_pipe;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    sigaction(SIGPIPE, &action, NULL);
    int sockconn;
    struct sockaddr_in servaddr;
    if ((sockconn = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    {
        perror("socket failure");
        exit(EXIT_FAILURE);
    }

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
    char recvbuf[1024] = {0};
    char sendbuf[1024] = {0};
    while(1){
        memset(recvbuf, 0, sizeof(recvbuf));
        memset(sendbuf, 0, sizeof(sendbuf));
        char * tmp = fgets(sendbuf, sizeof(sendbuf), stdin); // 键入EOF时，fgets返回一个空指针
        //fputs("fget from stdin\n", stderr);
        if (tmp != NULL)
        {
            //fputs("write to socket\n", stderr);
            // 如果服务器过早终止 当服务器tcp接受到来自客户的数据时，既然先前打开的那个套接口进程已经终止
            // 于是相应以一个RST， 通过使用tcpdump，来观察分组，我们可以验证该RST确实发送了
            // 然而客户端进程看不到这个RST，因为它在调用write后立即调用read，并且服务器已发送FIN，所调用的
            // read接收到FIN，立即返回0(表示EOF),我们的客户端未预期收到EOF，所以打印..server terminated prematurely
            //if (write(sockconn, sendbuf, strlen(sendbuf)) < 0)



       		// If  sendto()  is  used  on  a connection-mode (SOCK_STREAM, SOCK_SEQPACKET) socket, the arguments dest_addr and addrlen are
       		// ignored (and the error EISCONN may be returned when they are not NULL and 0), and the error ENOTCONN is returned  when  the
       		// socket  was not actually connected.  Otherwise, the address of the target is given by dest_addr with addrlen specifying its
       		// size.  For sendmsg(), the address of the target is given by msg.msg_name, with msg.msg_namelen specifying its size.

            //if(sendto(sockconn, sendbuf, strlen(sendbuf), 0, NULL, 0) < 0) 

			// --------------给的地址错误 直接忽略了-------------------------------
    		// struct sockaddr_in servaddr1;
    		// servaddr1.sin_port = htons(8887);
            // if(sendto(sockconn, sendbuf, strlen(sendbuf), 0, (struct sockaddr*)&servaddr1, sizeof(servaddr1)) < 0) 
			// ---------------------------------------------

			// --------------地址争取的情况下-----------------------------
			//sendto(4, "ll\n", 3, 0, {sa_family=AF_INET, sin_port=htons(8888), sin_addr=inet_addr("127.0.0.1")}, 16) = 3

            if(sendto(sockconn, sendbuf, strlen(sendbuf), 0, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) 
            {
                perror("write to socket error");
                exit(EXIT_FAILURE);
            }
        }
        else // 键入EOF时也返回空指针
        {
            fputs("get EOF\n", stderr);
            break;
        }
        //fputs("read from connfd\n", stderr);
        //int ret = recv(sockconn, recvbuf, sizeof(recvbuf), 0);
        int ret = recvfrom(sockconn, recvbuf, sizeof(recvbuf), 0, NULL, 0);

       // ssize_t recv(int sockfd, void *buf, size_t len, int flags);
       //ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags,
       //                 struct sockaddr *src_addr, socklen_t *addrlen);
       //ssize_t recvmsg(int sockfd, struct msghdr *msg, int flags);

       // The  recvfrom() and recvmsg() calls are used to receive messages from a socket, and may be used to receive data on a socket
       // whether or not it is connection-oriented.

       // If src_addr is not NULL, and the underlying protocol provides the source address, this source address is filled  in.   When
       // src_addr  is  NULL, nothing is filled in; in this case, addrlen is not used, and should also be NULL.  The argument addrlen
       // is a value-result argument, which the caller should initialize before the call to the size of the  buffer  associated  with
       // src_addr,  and  modified on return to indicate the actual size of the source address.  The returned address is truncated if
       // the buffer provided is too small; in this case, addrlen will return a value greater than was supplied to the call.
        if (ret != 0)
            fputs(recvbuf, stdout);
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
    close(sockconn); // 这里即使不close，在进程关闭的时候，仍然会会关闭
    return 0;
}
void handle_pipe(int sig)
{
    printf("receive pipe!\n");
}
