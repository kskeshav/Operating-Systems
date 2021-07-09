// program number: 3
// Student Name: Keshav Singhal; Register Number: IMT2018511
// Date: 25/02/2021
// Description : a program to create a file and print the file descriptor value.
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>


int main(int argc, char *argv[]){
    int file;
    file = creat(argv[1],S_IRWXU);
    printf("file descriptor = %d\n",file);
    
}