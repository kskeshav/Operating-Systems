// program number: 17
// Student Name: Keshav Singhal; Register Number: IMT2018511
// Date: 25/02/2021
// Description : a program to simulate online ticket reservation.
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{

  int fd = open(argv[1], O_RDWR);
  printf("%d\n", fd);

  struct flock lock;

  int ticket_no;

  lock.l_type = F_WRLCK;
  lock.l_start = 0;
  lock.l_whence = SEEK_SET;
  lock.l_len = 0;

  int return_lock = fcntl(fd, F_SETLKW, &lock);
  printf("%d\n", return_lock);
  
  read(fd, &ticket_no, sizeof(int));

  printf ("Original ticket no: %d\n", ticket_no);

  ticket_no += 1;

  lseek(fd,0,SEEK_SET);

  write(fd, &ticket_no, sizeof(int));
  
  printf ("New ticket no: %d\n", ticket_no);
  
  getchar();

  lock.l_type = F_UNLCK;
  int unlock = fcntl(fd, F_SETLKW, &lock);
  printf("%d\n",unlock);

  close(fd);
  
}