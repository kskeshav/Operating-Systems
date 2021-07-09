// Name: Keshav Singhal
// Roll number: IMT2018511
// Date: May, 2021
// Description: first program to communicate by FIFO using two way communications.

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(){

	char buff[100];
    printf("Sent from 1st user: ");
	scanf("%s",buff);
	int ret = mknod("fifo_one_to_two",S_IFIFO | 0744,0);
	int fd = open("fifo_one_to_two",O_WRONLY);
	write(fd,buff,sizeof(buff));	

    int fd_read = open("fifo_two_to_one",O_RDONLY);
    read(fd_read,buff,sizeof(buff));
    printf("Got from 2nd user: %s\n",buff);

    return 0;
	
}