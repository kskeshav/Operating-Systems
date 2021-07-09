// Name: Keshav Singhal
// Roll number: IMT2018511
// Date: May, 2021
// Description: a program to measure how much time is taken to execute 100 getppid ( )
// system call.

#include<stdio.h>
#include<sys/time.h>
#include <unistd.h>

unsigned long long rdtsc(){

    unsigned long long dst;
    __asm__ __volatile__("rdtsc":"=A"(dst));

    return dst;
}

int main(){
    long long int start, end;

    start = rdtsc();

    for(int i = 0; i < 100; i++){
        getppid();
    }

    end = rdtsc();

    printf("Time (difference) : %llu \n",end-start);
}