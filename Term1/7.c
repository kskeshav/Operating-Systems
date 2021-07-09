// program number: 7
// Student Name: Keshav Singhal; Register Number: IMT2018511
// Date: 25/02/2021
// Description : a program to copy file1 into file2.
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include<stdlib.h>


int main(int argc, char *argv[]){
    int f1,f2;

    f1 = open(argv[1],O_RDWR);
    f2 = open(argv[2],O_RDWR);

    char buffer[1024];
    int n;
    
    n=read(f1, buffer, 1024);

    write(f2, buffer, n);
}