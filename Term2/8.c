// Name: Keshav Singhal
// Roll number: IMT2018511
// Date: May, 2021
// Description: program using signal system call to catch the following signals.
// a. SIGSEGV
// b. SIGINT
// c. SIGFPE
// d. SIGALRM (use alarm system call)
// e. SIGALRM (use setitimer system call)
// f. SIGVTALRM (use setitimer system call)
// g. SIGPROF (use setitimer system call)

//uncomment the line of signal which is to be caught.

#include<stdio.h>
#include<signal.h>
#include<sys/time.h>
#include<unistd.h>

void sig_handler (int sig) {
    if(sig == SIGSEGV)  printf("Caught SIGSEGV\n");
    if(sig == SIGINT)  printf("Caught SIGINT\n");
    if(sig == SIGFPE)  printf("Caught SIGFPE\n");
    if(sig == SIGALRM)  printf("Caught SIGALRM\n");
    if(sig == SIGVTALRM)  printf("Caught SIGVTALRM\n");
    if(sig == SIGPROF)  printf("Caught SIGPROF\n");
}

int main ( void ) {

    // Part A
    // signal (SIGINT, sig_handler); 
    // sleep(5);

    // // part B
    // signal (SIGSEGV, sig_handler);
    // sleep(5);
    
    // //part C
    // signal (SIGFPE, sig_handler); 
    // sleep(5);

    // raise(SIGFPE); // raise the signal whichever u want to catch.
    
    struct itimerval value ;
    /* Interval for periodic timer */
    struct timeval it_value = {1,0};
    value.it_value = it_value;
    /* Time until next expiration */
    struct timeval it_interval = {0,0};
    value.it_interval = it_interval;
    
    int ret;
    
    //part D
    signal(SIGALRM,sig_handler);
    alarm(5);
    while(1);

    //part E
    // signal(SIGALRM,sig_handler);
    // ret = setitimer(ITIMER_REAL, &value, 0);
    // while(1);

    //part F
    // signal(SIGVTALRM,sig_handler);
    // ret = setitimer(ITIMER_VIRTUAL, &value, 0);
    // while(1);

    //part G
    // signal(SIGPROF,sig_handler);
    // ret = setitimer(ITIMER_PROF, &value, 0);
    // while(1);
    
    return 0;

}