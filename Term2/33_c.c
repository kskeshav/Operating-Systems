// Name: Keshav Singhal
// Roll number: IMT2018511
// Date: May, 2021
// Description: a program to communicate between two machines using socket.(client)

#include <sys/types.h>          
#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <netinet/in.h>


int main()
{
    char buffer[1024] = {0};

    printf("Client!\n");
    int sd = socket(AF_INET, SOCK_STREAM, 0); // RAW Socket Descriptor

    struct in_addr inadr;
    struct sockaddr_in serv, cli;
    
    serv.sin_family = AF_INET;
    inadr.s_addr = INADDR_ANY;
    serv.sin_addr = (inadr);
    serv.sin_port = htons(5000); // setting the port no. as 5000

    connect(sd, (void*)&serv, sizeof(serv));

    char* Sent_message = "Hello From Client!\n";
    send(sd, Sent_message, strlen(Sent_message), 0);

    recv(sd, buffer, 1024, 0) <= 0;
    printf("Received Message by client: %s", buffer);
    
    return 0;

}