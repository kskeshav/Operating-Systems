// program number: 28
// Student Name: Keshav Singhal; Register Number: IMT2018511
// Date: 25/02/2021
// Description : a program to get maximum and minimum real time priority.
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include<sched.h>


int main(){

    // max and min priority value that can be used. same for SCHED_RR and SCHED_FIFO
    int max_p = sched_get_priority_min(SCHED_RR);
	int min_p = sched_get_priority_max(SCHED_RR);

	printf("minimum and maximum priorities are %d  %d \n",min_p,max_p);
}