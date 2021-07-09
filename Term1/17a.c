// program number: 17
// Student Name: Keshav Singhal; Register Number: IMT2018511
// Date: 25/02/2021
// Description : a program to open a file, store a ticket number and exit.
#include<stdio.h>
#include<fcntl.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	int fd = open(argv[1],O_RDWR);
	int var = 1234;
	write(fd, &var, sizeof(int));
	
	return 0;
}