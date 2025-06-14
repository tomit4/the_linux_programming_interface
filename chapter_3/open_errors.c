#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int fd, cnt;
	char *buf = (char *)calloc(100, sizeof(char));

	fd = open("./gnu_fake.c", O_RDONLY);
	if (fd == -1) {
		fprintf(stderr, "System call to open gnu_fake.c failed\n");
		fprintf(stderr, "Error Number: %d\n", errno);
	} else {
		printf("open gnu_fake.c was successful\n");
	}
	if (close(fd) == -1) {
		fprintf(stderr, "System call to close gnu_fake.c failed\n");
		fprintf(stderr, "Error Number: %d\n", errno);
	} else {
		printf("close gnu_fake.c was successful\n");
	}

	cnt = read(fd, buf, 10);
	if (cnt == -1) {
		if (errno == EINTR) {
			fprintf(stderr, "read was interrupted by signal\n");
		} else {
			fprintf(stderr,
				"read was not interrupted by signal, some "
				"other error occurred: %d\n",
				errno);
		}
	}

	return 0;
}
