// program number: 14
// Student Name: Keshav Singhal; Register Number: IMT2018511
// Date: 25/02/2021
// Description : a program to find the type of a file.
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
  const char *filename;
  struct stat fs;
  int r;
  filename = argv[1];
  r = stat(filename,&fs); // returns 0 on success.

  if( argc<2 )
  {
      puts("Filename required");
      exit(1);
  }
  // st_mode have octal values which tells us the file type.

  switch (fs.st_mode & S_IFMT) {
  case S_IFBLK:  printf("block device\n");            break;
  case S_IFCHR:  printf("character device\n");        break;
  case S_IFDIR:  printf("directory\n");               break;
  case S_IFIFO:  printf("FIFO/pipe\n");               break;
  case S_IFLNK:  printf("symlink\n");                 break;
  case S_IFREG:  printf("regular file\n");            break;
  case S_IFSOCK: printf("socket\n");                  break;
  default:       printf("unknown?\n");                break;
  }

  printf("%d\n",r);
  exit(EXIT_SUCCESS);
  return 0;
}