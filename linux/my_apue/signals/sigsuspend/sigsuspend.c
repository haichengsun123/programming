#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>

#define err_sys(msg) \
	do { perror(msg); exit(EXIT_FAILURE); } while (0)

static void sig_int(int);
void pr_mask(const char *str);

int main(void)
{
	sigset_t newmask, oldmask, waitmask;
	pr_mask("program start:");
	if (signal(SIGINT, sig_int) == SIG_ERR)
	{
		err_sys("can't catch SIGINT");
	}

	sigemptyset(&waitmask);
	sigaddset(&waitmask, SIGUSR1);
	sigemptyset(&newmask);
	sigaddset(&newmask, SIGINT);


	/*
	 * Block SIGINT and save current signal mask
	 */
	if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
		err_sys("SIG_BLOCK error" );
	/*
	 * Critial region of code
	 */

	pr_mask("in critical region");
	/*
	 *  pause allowing all signals except SIGUSR1
	 */

	if (sigsuspend(&waitmask) != -1)
		err_sys("sigsuspend error" );
	pr_mask("after return from sigsuspend:");
	/*
	 * Rest signal mask which unblock SIGINT 
	 */

	if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
		err_sys("SIG_SETMASK error");
	/*
	 * And continue processing ...
	 */
	pr_mask("program exit:");

	exit(0);
}


static void sig_int(int signo)
{
	pr_mask("\nin sig_int\n");
}
void pr_mask(const char *str)
{
	sigset_t sigset;
	int      errno_save;
	errno_save = errno;  // we can be called by signal handlers
	if (sigprocmask(0, NULL, &sigset) < 0)
	{

		err_sys("sigprocmask err");
	}

	fprintf(stderr, "%s ", str);

	if (sigismember(&sigset, SIGINT))   printf("SIGINT ");
	if (sigismember(&sigset, SIGQUIT))  printf("SIGQUIT ");
	if (sigismember(&sigset, SIGUSR1))  printf("SIGUSR1 ");
	if (sigismember(&sigset, SIGALRM))  printf("SIGALRM ");

	// remaining signals can go here
	printf("\n");

	errno = errno_save;

}
