// Name: Keshav Singhal
// Roll number: IMT2018511
// Date: May, 2021
// Description: program will send the signal (using kill system call).

#include<stdio.h>
#include<fcntl.h>
#include<signal.h>

int main(){
	int pidno;
	scanf("%d",&pidno);
	kill(pidno,SIGSTOP);
	return 0;
}