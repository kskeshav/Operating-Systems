// program number: 4
// Student Name: Keshav Singhal; Register Number: IMT2018511
// Date: 25/02/2021
// Description : a program to open an existing file with read write mode.
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int fd;
    fd = open(argv[1],O_EXCL | O_RDWR | O_CREAT);

    printf("file descriptor : %d\n",fd);

}