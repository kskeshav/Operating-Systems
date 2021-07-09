// program number: 8
// Student Name: Keshav Singhal; Register Number: IMT2018511
// Date: 25/02/2021
// Description : a program to open a file in read only mode, read line by line and display each line as it is read.
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
int main(){
	
	char buf[1];
	int fd1 = open("src.txt", O_RDONLY);
	int size = 0;
	size = read(fd1, buf, 1);
	while(size){
		if (buf[0] == '\n')
			printf("\n");
		else 
			printf("%s", buf);
		size = read(fd1, buf, 1);
	}
	close(fd1);
	
	return 0;

}
