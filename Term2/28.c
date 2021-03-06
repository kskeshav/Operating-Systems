// Name: Keshav Singhal
// Roll number: IMT2018511
// Date: May, 2021
// Description: a program to change the exiting message queue permission.

#include<stdio.h>
#include<sys/msg.h>
#include<sys/types.h>
#include<unistd.h>

int main(){	

	struct msqid_ds buf;
	key_t key = ftok(".",'a');
	int msgid = msgget(key,0);
	buf.msg_perm.uid= 500;
	buf.msg_perm.gid= 500;
	buf.msg_perm.mode= 0700;
	msgctl(msgid,IPC_SET,&buf);

	struct msqid_ds buf2; // to get the permissions.
	int ret = msgctl(msgid,IPC_STAT,&buf2);
	printf("uid = %d\n",buf2.msg_perm.uid);
	printf("gid = %d\n",buf2.msg_perm.gid);
	
}