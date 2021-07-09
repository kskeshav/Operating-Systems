// program number: 24
// Student Name: Keshav Singhal; Register Number: IMT2018511
// Date: 25/02/2021
// Description : a program to create an orphan process.
#include<stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
  
int main() 
{ 
    int pid = fork(); 
  
    if (pid > 0)
    {
        printf("This is parent process");
    }
    else if (pid == 0) 
    { 
        sleep(5); 
        printf("This is child process"); 
    } 
    return 0;
}