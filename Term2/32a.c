// Name: Keshav Singhal
// Roll number: IMT2018511
// Date: May, 2021
// Description: rewrite the ticket number creation program using semaphore

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<pthread.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <fcntl.h>

int main(void){
	key_t key = ftok("./", 66);
	int semid = semget(key, 1, IPC_CREAT | IPC_EXCL | 0744);

	if(semid == -1){
		semid = semget(key, 0, 0);

		if(semid == -1){
			perror("semget");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		semid = semget(key, 0, 0);
		semctl(semid, 0, SETVAL, 1);
	}
	if(!fork()) sleep(3);
	struct sembuf buf = {0, -1, 0};
	semop(semid, &buf, 1);
	printf("Critical section....\n");
	char ticket[100];
	int fd = open("ticket.txt", O_RDWR);
	read(fd, ticket, 6);
	printf("Old Ticket number : %s\n", ticket);
	int fp = lseek(fd, 0, SEEK_SET);
	int t = atoi(ticket);
	t = t + 1;
	char new_t[100];
	sprintf(new_t, "%d", t);
	int num = write(fd, new_t, 6);
	printf("New Ticket number = %d\n", t);
	printf("Enter to unlock....\n");
	getchar();
	buf.sem_op = 1;
	semop(semid, &buf, 1);
	return 0;
}
