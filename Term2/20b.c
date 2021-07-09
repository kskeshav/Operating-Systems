// Name: Keshav Singhal
// Roll number: IMT2018511
// Date: May, 2021
// Description: second program to communicate by FIFO using one way communication

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(){

	char buff[100];
    printf("Message sent:");
	scanf("%s",buff);
	int ret = mknod("fifo",S_IFIFO | 0744,0);
	int fd = open("fifo",O_WRONLY);
	write(fd,buff,sizeof(buff));
    return 0;
	
}