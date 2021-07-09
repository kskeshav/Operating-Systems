// Name: Keshav Singhal
// Roll number: IMT2018511
// Date: May, 2021
// Description: a program to ignore a SIGINT signal then reset the default action of the SIGINT signal

#include<stdio.h>
#include<signal.h>
#include<sys/time.h>
#include<unistd.h>

int main ( void ) {

    signal (SIGINT, SIG_IGN);
    printf("ignoring.....\n");
    sleep(5);

    signal (SIGINT, SIG_DFL);
    printf("default.....\n");
    sleep(5);
    return 0;

}