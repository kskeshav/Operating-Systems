// program number: 18
// Student Name: Keshav Singhal; Register Number: IMT2018511
// Date: 25/02/2021
// Description : write lock.
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
  int fd = open(argv[1], O_RDWR);
  if(fd == -1) {
    printf("No file\n");
    exit(1);
  }

  printf("Record: ");
  int record;
  scanf("%d", &record);
  getchar();

  struct flock lock;

  lock.l_type = F_WRLCK;
  lock.l_start = sizeof(int)*(record-1);
  lock.l_whence = SEEK_SET;
  lock.l_len = sizeof(int);

  int return_lock = fcntl(fd, F_SETLK, &lock);
  printf("%d\n",return_lock);
  
  printf("Locked\n");

  getchar();
  
  lock.l_type = F_UNLCK;
  int unlock_return = fcntl(fd, F_SETLK, &lock);
  
  printf("Unlock return:%d\n",unlock_return);
}