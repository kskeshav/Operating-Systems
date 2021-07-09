// Name: Keshav Singhal
// Roll number: IMT2018511
// Date: May, 2021
// Description: remove the created semaphore.

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <sys/sem.h>

int main(void){
	key_t key = ftok(".", 'a');
	int semid = semget(key, 0, 0);

	if(semid == -1)
    {
		perror("semget");
		exit(EXIT_FAILURE);
	}
	semctl(semid, 0, IPC_RMID);
	printf("removed....\n");
}
