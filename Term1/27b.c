// program number: 27
// Student Name: Keshav Singhal; Register Number: IMT2018511
// Date: 25/02/2021
// Description : execlp
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(){

    printf("execlp system call\n");
    execlp("/bin/ls", "ls", "-Rl", (char *)0);
    return 0;
}