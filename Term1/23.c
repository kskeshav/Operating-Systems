// program number: 23
// Student Name: Keshav Singhal; Register Number: IMT2018511
// Date: 25/02/2021
// Description : a program to create a Zombie state of the running program.
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
int main() 
{
    int pid = fork();
    if (pid > 0) 
        sleep(5);
    else        
        exit(0);
    return 0; 
} 