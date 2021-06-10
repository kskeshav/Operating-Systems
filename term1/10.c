// program number: 10
// Student Name: Keshav Singhal; Register Number: IMT2018511
// Date: 25/02/2021
// Description : program to open a file with read write mode, write 10 bytes, move the file pointer by 10
// bytes (use lseek) and write again 10 bytes.
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include<string.h>

int main(int argc,char* argv[]){
    
	int f = open(argv[1],O_RDWR);
	
	char *buffer = argv[2];

	write(f,buffer,strlen(buffer));
	
	printf("lseek: %ld\n",lseek(f,10,SEEK_CUR));
	
	write(f,buffer,strlen(buffer));
	
}