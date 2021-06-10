// program number: 19
// Student Name: Keshav Singhal; Register Number: IMT2018511
// Date: 25/02/2021
// Description : a program to find out time taken to execute getpid system call.
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include<time.h>

int main() 
{ 
    clock_t start,end;
    start= clock();
    getpid();
    end = clock();
    printf("Time taken: %ld\n",(end-start));

} 