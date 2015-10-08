#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#define err_sys(msg) \
	do { perror(msg); exit(EXIT_FAILURE); } while (0)
#define err_dump(msg) \
	do { perror(msg); exit(EXIT_FAILURE); } while (0)


static void sig_quit(int);

int main(void)
{
	sigset_t newmask, oldmask, pendmask;

	if (signal(SIGQUIT, sig_quit) == SIG_ERR)
	{
		err_sys("can't catch SIGQUIT");
	}
	/*
	 * Block SIGQUIT and save current signal mask;
	 */
	sigemptyset(&newmask);
	sigaddset(&newmask, SIGQUIT);
	if (sigprocmask(SIG_BLOCK, &newmask, &oldmask))
		err_sys("SIG_BLOCK error");
	sleep(5);  /*SIGQUIT here will remain pending*/
	
	if (sigpending(&pendmask) < 0)
		err_sys("sigpending error");
	if (sigismember(&pendmask, SIGQUIT))
		printf("\nSIGQUIT pending\n");
	/*
	 * Restore signal mask which unblocks SIGQUIT
	 */
	if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
		err_sys("SIG_SETMASK error");
	printf("SIGQUIT unblocked\n");
	sleep(5);
	exit(0);

}


static void sig_quit(int signo)
{
	printf("caught SIGQUIT\n");
	if (signal(SIGQUIT, SIG_DFL) == SIG_ERR)
		err_sys("can't reset SIGQUIT");
}
