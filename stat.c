#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
int main(){
	struct stat sb;
	stat("stat.c", &sb);

	off_t size = sb.st_size;
	if(size >= 1073741824)
		printf("Size of file: %ldGB\n", size/1073741824);
	else if(size >= 1048576)
		printf("Size of file: %ldMB\n", size/1048576);
	else if(size >= 1024)
		printf("Size of file: %ldKB\n", size/1024);
	else
		printf("Size of file: %ldB\n", size);

	mode_t mode = sb.st_mode;
	printf("Permissions: %o\n", mode);
	char modes[10] = "rwxrwxrwx";
	int i;
	for(i = 0; i < 9; i++)
		if(!(mode & (1 << (8-i))))
			modes[i] = '-';
	printf("Permissions, ls -l style: %s\n", modes);

	printf("Access time: %s\n", ctime((time_t *)&sb.st_atim));

	return 0;
}