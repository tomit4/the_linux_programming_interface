#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int fd;
	fd = open("./gnu_fake.c", O_RDONLY);
	if (fd == -1) {
		/* prints out syscall error:
		 * open: No such file or directory*/
		perror("open");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
