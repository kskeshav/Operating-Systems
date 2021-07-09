// program number: 27
// Student Name: Keshav Singhal; Register Number: IMT2018511
// Date: 25/02/2021
// Description : a program to execute ls -Rl : execl
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(){

    printf("execl system call\n");
    execl("/bin/ls", "ls", "-Rl", (char *)0);
    return 0;
}