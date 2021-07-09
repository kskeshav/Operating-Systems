// Name: Keshav Singhal
// Roll number: IMT2018511
// Date: May, 2021
// Description: a program to wait for data to be written into FIFO within 10 seconds

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include<stdio.h>

int main(void){

    fd_set rfds;
    int fd = open("fifo",O_RDONLY);

    // Clear the rfds set
    FD_ZERO(&rfds);
     // Set the rfds to 0
    FD_SET(fd, &rfds);
    struct timeval tv;
    tv.tv_sec = 10; // wait time
    tv.tv_usec = 0;
    
    int ret = select(fd+1, &rfds, NULL, NULL, &tv);
    
    if(ret){
        printf("Received the data.\n");
        char buff[100];
        read(fd,buff,sizeof(buff));
        printf("%s\n",buff);
    }
    else{
        printf("Didn't receive the data within 10 seconds");
        exit(0); 
    }	
}	