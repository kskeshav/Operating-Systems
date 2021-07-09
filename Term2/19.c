// Name: Keshav Singhal
// Roll number: IMT2018511
// Date: May, 2021
// Description: Creation of FIFO file using different calls.

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

/*
Part A:
mknod myfifo p
Part B:
mkfifo myfifo
Part C:
strace -c mknod
strace -c mkfifo
*/

int main(){
	int fd=mknod("fifo",S_IFIFO,0);
	printf("mknod: %d\n",fd);
    
    fd=mkfifo("myfifo",0744);
	printf("mkfifo: %d\n",fd);
}