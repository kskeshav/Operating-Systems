// program number: 15
// Student Name: Keshav Singhal; Register Number: IMT2018511
// Date: 25/02/2021
// Description : a program to display the environmental variable of the user.
#include<stdio.h>
#include<fcntl.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[], char * envp[])
{
    extern char **environ;
    for (int i = 0; environ[i] != NULL; i++)
    {    
        printf("%s\n", environ[i]);
    }
}