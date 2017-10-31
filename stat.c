#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	struct stat sb;
	stat("stat.c", &sb);
	printf("Size of file in bytes: %ld\n", sb.st_size);
	printf("Permissions: %o\n", sb.st_mode);
	printf("%ld\n", sb.st_atim);
	printf("Access time: %s\n", ctime(&sb.st_atim));
	return 1;
}

