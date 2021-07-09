// program number: 12
// Student Name: Keshav Singhal; Register Number: IMT2018511
// Date: 25/02/2021
// Description : a program to find out the opening mode of a file.
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
int main(){
	
	int fd1 = open("src.txt", O_RDWR);

	int mode = fcntl(fd1, F_GETFL);
	printf("write and read = %d\n", mode);
	close(fd1);

	int fd2 = open("src.txt", O_RDONLY);
    mode = fcntl(fd2, F_GETFL);
    printf("read only = %d\n", mode);
	close(fd2);
	return 0;

}
