// Name: Keshav Singhal
// Roll number: IMT2018511
// Date: May, 2021
// Description: create an orphan process. Use kill system call to send SIGKILL signal to the parent process from the child process.

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	int pid = fork();
	if(pid != 0){
        printf("Running parent Process:\n");
		kill(getppid(),SIGKILL);		
		printf("Parent process is killed\n");
	}
	else{
        wait(0);
        printf("Running child Process\n");
	}
}