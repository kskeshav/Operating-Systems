// program number: 29
// Student Name: Keshav Singhal; Register Number: IMT2018511
// Date: 25/02/2021
// Description : a program to get scheduling policy and modify the scheduling policy.
#include<stdio.h>
#include<unistd.h>
#include<sched.h>

int main(){
    int pid = getpid();
    int c_policy = sched_getscheduler(pid);
    printf("Current scheduling policy: %d\n", c_policy);

    struct sched_param sp;
    sp.sched_priority = 42;
	
	sched_setscheduler(pid,SCHED_FIFO,&sp);
    int n_policy = sched_getscheduler(pid);
    printf("New scheduling policy: %d\n", n_policy);

    return 0;
}