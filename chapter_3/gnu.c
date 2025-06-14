#include <gnu/libc-version.h>
#include <stdio.h>

/* Returns pointer to null-terminated, statically allocated string containing
 * GNU C library version number */
/* const char *gnu_get_libc_version(void); */

int main(int argc, char *argv[])
{
	const char *gnu = gnu_get_libc_version();
	printf("Your GNU C Library Version Number is: %s\n", gnu);
	return 0;
}
