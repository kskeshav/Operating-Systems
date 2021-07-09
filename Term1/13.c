// program number: 13
// Student Name: Keshav Singhal; Register Number: IMT2018511
// Date: 25/02/2021
// Description : a program to wait for a STDIN for 10 seconds using select.

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
int main(void)
{
  fd_set rfds;
  struct timeval tv;
  int retval;

  // int fd = open("cfifo",O_RDWR); // if we want to give input from a file.

  FD_ZERO(&rfds);
  FD_SET(0, &rfds);

  /* Wait up to ten seconds. */

  tv.tv_sec = 10;
  tv.tv_usec = 0;

  retval = select(1, &rfds, NULL, NULL, &tv);

  if (retval == -1)
    perror("select()");
  
  else if (retval)
    printf("Data is received.\n");

  else
    printf("No data received within ten seconds.\n");

  exit(EXIT_SUCCESS);
}
