// Name: Keshav Singhal
// Roll number: IMT2018511
// Date: May, 2021
// Description: a program to print a message queue's (use msqid_ds and ipc_perm structures)
// a. access permission
// b. uid, gid
// c. time of last message sent and received
// d. time of last change in the message queue
// d. size of the queue
// f. number of messages in the queue
// g. maximum number of bytes allowed
// h. pid of the msgsnd and msgrcv

#include<stdio.h>
#include<sys/msg.h>
#include<time.h>

int main(){
    struct msqid_ds buf;
	key_t key = ftok(".",'a');
	int msgid = msgget(key,IPC_CREAT|IPC_EXCL|0744);
	int ret = msgctl(msgid,IPC_STAT,&buf);
	
	printf("Acess Permision = %o\n",buf.msg_perm.mode & 0744);
	printf("uid = %d\n",buf.msg_perm.uid);
	printf("gid = %d\n",buf.msg_perm.gid);
	printf("time of last msg sent = %s",ctime( & buf.msg_stime));
	printf("time of last msg recieved = %s",ctime( & buf.msg_rtime));
	printf("time of last change = %s",ctime( & buf.msg_ctime));
	printf("size of queue = %lu\n",buf.msg_qbytes);
	printf("number of msgs in queue = %ld\n",buf.msg_qnum);
    printf("Maximun number of bytes allowed = %lu\n",buf.msg_qbytes);
    printf("pid of last msg send = %d\n",buf.msg_lspid);
    printf("pid of last msg send = %d\n",buf.msg_lrpid);
}