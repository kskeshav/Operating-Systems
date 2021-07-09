// Name: Keshav Singhal
// Roll number: IMT2018511
// Date: May, 2021
// Description: protect multiple pseudo resources ( may be two) using counting semaphore

#include <sys/sem.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	pid_t shmid;
	void* shm_ptr;
	key_t sem_key = ftok("./", 'a');
	key_t shm_key = ftok("./", 'b');

	int semid = semget(sem_key, 1, IPC_CREAT | IPC_EXCL | 0744);
	if(semid == -1){
		semid = semget(sem_key, 0, 0);

		if(semid == -1){
			perror("semget");
			exit(EXIT_FAILURE);
		}
	}
	else
    {
		semid = semget(sem_key, 0, 0);
		semctl(semid, 0, SETVAL, 2);
	}

	shmid = shmget(shm_key, 128, IPC_EXCL | IPC_CREAT | 0666);
	if(shmid == -1)
    {
		shmid = shmget(shm_key, 128, 0);

		if(shmid == -1){
			perror("shmget");
			exit(EXIT_FAILURE);
		}
	}
	shm_ptr = shmat(shmid, (void *)0, 0);
	*(int *)shm_ptr = 0;

	if(!fork()) sleep(3);

	struct sembuf buf = {0, -1, 0};
	semop(semid, &buf, 1);
	printf("Critical Section....\n");
	int counter = *((int *)shm_ptr);
	printf("Old memory : %d\n", counter);
	counter++;
	*(int *)shm_ptr = counter;
	printf("New memory : %d\n", counter);
	printf("Enter to unlock....\n");
	getchar();
	buf.sem_op = 1;
	semop(semid, &buf, 1);
	return 0;
}

