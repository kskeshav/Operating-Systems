// Name: Keshav Singhal
// Roll number: IMT2018511
// Date: May, 2021
// Description: a program to create a message queue and print the key and message queue id.

#include<stdio.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/ipc.h>


int main(){
    // ftok to generate unique key 
	key_t key = ftok(".", 65); 

    // msgget creates a message queue 
    // and returns identifier 
    int msgid = msgget(key, 0666 | IPC_CREAT); 
	printf("Key of message queue= %d\n",key);
    printf("Message queue id = %d\n",msgid);
	return 0;
}