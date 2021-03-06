#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#define ERR_EXIT(m) \
        do \
        { \
                perror(m); \
                exit(EXIT_FAILURE); \
        } while(0)


typedef struct stu
{
	int age;
	char name[32];
} STU;

int main(int argc, char *argv[])
{
	int shmid;
	shmid = shmget(1234, 0, 0);
	if (shmid == -1)
		ERR_EXIT("shmget");

	STU *p;
	p = shmat(shmid, NULL, 0);
	if (p == (void*)-1)
		ERR_EXIT("shmat");

	printf("name = %s age = %d\n", p->name, p->age);
	memcpy(p, "quit", 4);

	shmdt(p);
	return 0;
}
