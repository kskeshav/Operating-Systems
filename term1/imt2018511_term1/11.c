// program number: 11
// Student Name: Keshav Singhal; Register Number: IMT2018511
// Date: 25/02/2021
// Description : program to open a file, duplicate the file descriptor and append the file with both the
// descriptors and check whether the file is updated properly or not.
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
int main(){
	
	int fd1 = open("src.txt", O_RDWR);
	int fd2 = dup(fd1);
	int fd3 = dup2(fd1, 11);
	int fd4 = fcntl(fd1, F_DUPFD, 1);
	printf("oldfd %d, dup fd %d, dup2 fd %d, fcntl fd %d\n", fd1, fd2, fd3, fd4);
	
	lseek(fd1, 0, SEEK_END);
	write(fd2, "appending\n", 9);
	
	// Check if fd2 is updated
	char buf[100];
	lseek(fd1, 0, SEEK_SET);
	int size = read(fd2, buf, 100);
	write(1, buf, size);
    printf("\n");
	
	// Check if fd3 is updated
	lseek(fd1, 0, SEEK_SET);
	size = read(fd3, buf, 100);
	write(1, buf, size);
    printf("\n");
 	// Check if fd3 is updated
    lseek(fd1, 0, SEEK_SET);
    size = read(fd4, buf, 100);
    write(1, buf, size);
    printf("\n");
    
	close(fd1);
	
	return 0;

}
