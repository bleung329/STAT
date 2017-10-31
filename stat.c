#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	struct stat sb;
	stat("stat.c", &sb);
	printf("%d\n", sb.st_atim);
	printf("%s\n", ctime(&sb.st_atim));
	return 0;
}

