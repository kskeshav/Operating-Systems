// program number: 26
// Student Name: Keshav Singhal; Register Number: IMT2018511
// Date: 25/02/2021
// Description : a program to execute an executable program.
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main()
{
    char *args[] = {"./execfile", "Second argument",NULL};
    execvp(args[0], args);
    
    return 0;
}