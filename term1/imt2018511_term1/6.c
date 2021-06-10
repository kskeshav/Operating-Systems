// program number: 6
// Student Name: Keshav Singhal; Register Number: IMT2018511
// Date: 25/02/2021
// Description : a program to take input from STDIN and display on STDOUT.
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include<string.h>

int main(){

    char buffer[80];
    printf("enter your data:\n");
    int n=read(0,buffer,80);
    printf("data written:\n");
    write(1,buffer,n);
}