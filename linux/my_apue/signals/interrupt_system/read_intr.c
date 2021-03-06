#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

void sig_handler(int signum)
{
	printf("in handler\n");
	//sleep(1);
	printf("handler return\n");
}

int main(int argc, char **argv)
{
	char buf[100];
	int ret;
	struct sigaction action, old_action;

	action.sa_handler = sig_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	/* 版本1:不设置SA_RESTART属性
	 * 版本2:设置SA_RESTART属性 */
	action.sa_flags |= SA_RESTART;

	sigaction(SIGINT, &action, &old_action);

	bzero(buf, 100);

	// 设置自动重启时 read不返回
	// 不自动重启，read返回 -1 
	ret = read(0, buf, 100);
	printf("ret: %d \n", ret);
	if (ret == -1) {
		printf("errno: %d", errno);
		perror("read");
	}
	printf("errno: %d\n", errno);

	printf("read %d bytes:\n", ret);
	printf("%s\n", buf);

	return 0;
}
