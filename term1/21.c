// program number: 21
// Student Name: Keshav Singhal; Register Number: IMT2018511
// Date: 25/02/2021
// Description : a program that calls fork and prints the parent and child process id.
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>
  
int main() 
{ 
    int pid; 
    pid = fork();
    
    if (pid == 0) 
    {
        printf("Parent : %d\n",getppid());
        printf("Child : %d\n",getpid());
    } 
} 