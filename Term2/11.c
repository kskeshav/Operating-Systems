// Name: Keshav Singhal
// Roll number: IMT2018511
// Date: May, 2021
// Description: ignore a SIGINT signal then reset the default action of the SIGINT signal - use sigaction system call.
#include<stdio.h>
#include<signal.h>
#include<sys/time.h>
#include<unistd.h>

int main ( void ) {

    
    printf("Ignoring----\n");
    struct sigaction sig_action;
    sig_action.sa_handler = SIG_IGN;
    sigaction (SIGINT, &sig_action, NULL);
    sleep(5);
    printf("\nDefault----\n");
    sig_action.sa_handler = SIG_DFL;
    sigaction (SIGINT, &sig_action, NULL);
    sleep(5);
}