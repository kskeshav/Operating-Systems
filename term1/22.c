// program number: 22
// Student Name: Keshav Singhal; Register Number: IMT2018511
// Date: 25/02/2021
// Description : a program, open a file, call fork, and then write to the file by both the child as well as the
// parent processes.
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() 
{ 
    int pid,fd;
    fd = open("file.txt",O_WRONLY); 
    pid = fork(); 

    if (pid == 0) 
    { 
        printf("Writing by child process\n");
        lseek(fd,0,SEEK_END);
        write(fd,"CHILD WRITING\n",sizeof("CHILD WRITING\n"));
    } 

    else{
        printf("Writing by parent process\n");
        lseek(fd,0,SEEK_END);
        write(fd,"PARENT WRITING\n",sizeof("PARENT WRITING\n"));
    }
} 