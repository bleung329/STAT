#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
int main()
{
  struct stat sb;
  stat("WomensRights.pdf", &sb);
  off_t size = sb.st_size;
  if(size >= 1073741824)
    printf("Size of file: %ldGB\n", size/1073741824);
  else if(size >= 1048576)
    printf("Size of file: %ldMB\n", size/1048576);
  else if(size >= 1024)
    printf("Size of file: %ldKB\n", size/1024);
  else
    printf("Size of file: %ldB\n", size);
  printf("Permissions: %o\n", sb.st_mode);
  printf("%ld\n", sb.st_atim);
  printf("Access time: %s\n", ctime(&sb.st_atim));

  return 0;
}

