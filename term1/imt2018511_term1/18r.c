// program number: 18
// Student Name: Keshav Singhal; Register Number: IMT2018511
// Date: 25/02/2021
// Description : read lock.
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
    int record = 0;
    scanf("%d", &record);
    getchar();

    struct flock lock;

    lock.l_type = F_RDLCK;
    lock.l_start = sizeof(int)*(record-1);
    lock.l_whence = SEEK_SET;
    lock.l_len = sizeof(int);

    int return_lock = fcntl(fd, F_SETLK, &lock);
    printf("%d\n", return_lock);
    printf("locked\n");

    getchar();
    
    lock.l_type = F_UNLCK;
    int unlock = fcntl(fd, F_SETLK, &lock);
    
    printf("Return of unlock:%d\n",unlock);
}