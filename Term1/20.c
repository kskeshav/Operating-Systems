// program number: 20
// Student Name: Keshav Singhal; Register Number: IMT2018511
// Date: 25/02/2021
// Description : Find the priority of your running program. Modify the priority with nice command.
#include<time.h>
#include <stdio.h>
#include <sys/types.h>
#include<sys/resource.h>
#include <unistd.h>

int main()
{
	int pid = getpid();
	int priority = getpriority(PRIO_PROCESS,pid);
	printf("Priority : %d\n",priority);
	
	nice(5);

	priority = getpriority(PRIO_PROCESS,pid);
	printf("Priority : %d\n",priority);
	
	return 0;
}