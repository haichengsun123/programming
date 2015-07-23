#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>           /* For O_* constants */


#define handle_error(msg) \
	do { perror(msg); exit(EXIT_FAILURE); } while (0)

	int
main(int argc, char *argv[])
{
	int i, fd;
	struct stat stat;
	unsigned char *ptr;

	if (argc != 2)
	{
		fprintf(stderr, "usage: %s <name> ", argv[0]);
		exit(1);
	}

	// open file , get szie , map 
	fd = shm_open(argv[1], O_RDWR, 0666);
	if (fd < 0)
	{
		handle_error("shm_open :");
	}
	int ret = fstat(fd, &stat);
	
	if (ret < 0)
	{
		handle_error("fstat:");
	}

	ptr = mmap(NULL, stat.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (ptr == MAP_FAILED)
	{
		handle_error("mmap:");
	}

	close(fd);

	for(i = 0; i < stat.st_size; i++)
	{
		*ptr++ = i % 256;

	}

	exit(EXIT_SUCCESS);
}
