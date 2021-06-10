// program number: 17
// Student Name: Keshav Singhal; Register Number: IMT2018511
// Date: 25/02/2021
// Description : 
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{    
    int fd = open("ticket.txt", O_WRONLY);

    int ticket_no = 35;

    write(fd, &ticket_no, sizeof(int));
    
    return 0;
}