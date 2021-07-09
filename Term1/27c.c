// program number: 27
// Student Name: Keshav Singhal; Register Number: IMT2018511
// Date: 25/02/2021
// Description : execle
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

extern char **environ;

int main(){

    printf("execle system call\n");
    execle("/bin/ls", "ls", "-Rl", (char *)0, environ);
    return 0;
}