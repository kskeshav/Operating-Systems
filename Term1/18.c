// program number: 18
// Student Name: Keshav Singhal; Register Number: IMT2018511
// Date: 25/02/2021
// Description : a program to perform Record locking.
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    
    int fd = open("record.txt", O_WRONLY);
    int rec1 = 123;

    lseek(fd,0,SEEK_END);
    write(fd, &rec1, sizeof(int));

    int rec2 = 421;
    lseek(fd,0,SEEK_END);
    write(fd, &rec2, sizeof(int));

    int rec3 = 562;
    lseek(fd,0,SEEK_END);
    write(fd, &rec3, sizeof(int));

    return 0;
}