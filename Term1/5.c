// program number: 5
// Student Name: Keshav Singhal; Register Number: IMT2018511
// Date: 25/02/2021
// Description : a program to create five new files with infinite loop.
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int f1,f2,f3,f4,f5;
    f1 = creat("file1",S_IRWXU);
    f2 = creat("file2",S_IRWXU);
    f3 = creat("file3",S_IRWXU);
    f4 = creat("file4",S_IRWXU);
    f5 = creat("file5",S_IRWXU);
    printf("file descriptor = %d\n",f1);
    while(1){}
    
}