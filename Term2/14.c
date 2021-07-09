// Name: Keshav Singhal
// Roll number: IMT2018511
// Date: May, 2021
// Description: program to create a pipe, write to the pipe, read from pipe and display on the monitor.

#include<stdio.h>
#include<unistd.h>
int main(){
 
	 int pipefd[2]; //pipefd[0] - read pipefd[1] - write
	 pipe(pipefd);
	 write(pipefd[1],"Question 14\n",100);

     char read_input[100];
	 read(pipefd[0],&read_input,sizeof(read_input));
	 printf("%s",read_input);


}