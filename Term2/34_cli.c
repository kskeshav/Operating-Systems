// Name: Keshav Singhal
// Roll number: IMT2018511
// Date: May, 2021
// Description: common client.

#include<unistd.h>
#include <stdio.h>
#include<sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include<arpa/inet.h>


int main(){

	struct sockaddr_in serv_addr;
	int socket_fd = socket(AF_INET,SOCK_STREAM,0);
	
	char buff[25],username[25],password[25];	

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serv_addr.sin_port = htons(5555);

	connect(socket_fd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
	write(socket_fd,"Hello from client!!\n",sizeof("Hello from client!!\n"));
    int len = read(socket_fd,buff,sizeof(buff));				
	write(1,buff,len);	
    sleep(5);

    close(socket_fd);
}