// program number: 30
// Student Name: Keshav Singhal; Register Number: IMT2018511
// Date: 25/02/2021
// Description : a program to run a script at a specific time using a Daemon process.
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/time.h>
#include<sys/stat.h>

int main(){
	int pid = fork();
	if(pid == 0)
	{
		printf("child pid : %d\n",getpid());
		setsid();
		chdir("/");
		umask(0);
		while(1){
			sleep(5);
			printf("this is Daemon Process \n");
	    }
	}
	else{
		exit(0);
	}

}