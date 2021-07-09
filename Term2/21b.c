// Name: Keshav Singhal
// Roll number: IMT2018511
// Date: May, 2021
// Description: second program to communicate by FIFO using two way communications.

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(){

	char buff[100];
	int fd_read = open("fifo_one_to_two",O_RDONLY);
	read(fd_read,buff,sizeof(buff));
	printf("Got from 1st user: %s\n",buff);

    printf("Sent from 2nd user: ");
	scanf("%s",buff);
	int ret = mknod("fifo_two_to_one",S_IFIFO | 0744,0);
	int fd = open("fifo_two_to_one",O_WRONLY);
	write(fd,buff,sizeof(buff));	


    return 0;
}