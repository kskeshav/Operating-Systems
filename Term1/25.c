// program number: 25
// Student Name: Keshav Singhal; Register Number: IMT2018511
// Date: 25/02/2021
// Description : a program to create three child processes. The parent should wait for a particular child.
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
	int pid1, pid2, pid3;

    pid1 = fork();

    if (pid1 == 0)
    {
		sleep(3);
        printf("1st child with pid %d and ppid %d\n", getpid(), getppid());
	}
	else
    {
		pid2 = fork();
		if (pid2 == 0){
			sleep(2);
			printf("2nd child with pid %d and ppid %d\n",getpid(), getppid());
		}
		else{
			pid3 = fork();
			if (pid3 == 0){
				printf("3rd child with pid %d and ppid %d\n",getpid(), getppid());
			}

		}
	}
	waitpid(pid1,NULL,0);  

	return 0;
}