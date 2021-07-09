// Name: Keshav Singhal
// Roll number: IMT2018511
// Date: May, 2021
// Description: a program to send and receive data from parent to child vice versa using two way communication.

#include<stdio.h>
#include<unistd.h>
int main(){
	int pipefd1[2],pipefd2[2];
	pipe(pipefd1);
	pipe(pipefd2);
	char read_input[100];
    int pid = fork();
    
	if(pid != 0){
        printf("Parent Process\n");
        printf("Parent to child: ");
		scanf("%s",read_input);
		write(pipefd1[1],read_input,sizeof(read_input));
		read(pipefd2[0],&read_input,sizeof(read_input));
        printf("Got from child: %s\n",read_input);
	}
	else{
		read(pipefd1[0],&read_input,sizeof(read_input));
        printf("Got from parent: %s\n",read_input);
		printf("Child to parent: ");
		scanf("%s",read_input);
		write(pipefd2[1],read_input,sizeof(read_input));
	}
}