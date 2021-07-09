// Name: Keshav Singhal
// Roll number: IMT2018511
// Date: May, 2021
// Description: program to send some data from parent to the child process.

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	int pipefd[2];
	pipe(pipefd);
	char read_input[100];

    int pid = fork();
	if(pid != 0){
		printf("Parent Process\n");
        printf("Sent by parent: ");
		scanf("%s",read_input);
		write(pipefd[1],read_input,sizeof(read_input));
	}
	else{
        printf("\nChild Process\n");
		read(pipefd[0],&read_input,sizeof(read_input));
        printf("Received from parent: ");
		printf("%s\n",read_input);
	}
}