// program number: 27
// Student Name: Keshav Singhal; Register Number: IMT2018511
// Date: 25/02/2021
// Description : execv
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(){

    printf("execv system call\n");
    char* v[] = {"/bin/bash", "-c", "ls -Rl", NULL};
    execv(v[0], v);
    return 0;
}