// Name: Keshav Singhal
// Roll number: IMT2018511
// Date: May, 2021
// Description: program is waiting to catch SIGSTOP signal.

#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void my_handler (int sig) {
    printf("Caught SIGSTOP\n");
}

int main ( void ) {
    struct sigaction sig_struct;

	sig_struct.sa_handler = my_handler;
	sigemptyset(&sig_struct.sa_mask);
	sig_struct.sa_flags = 0;

	sigaction(SIGSTOP, &sig_struct, NULL);
    printf("%d\n",getpid());
    while(1);
    return 0;
}