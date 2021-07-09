// Name: Keshav Singhal
// Roll number: IMT2018511
// Date: May, 2021
// Description: a program to create a binary semaphore and initialize value to the semaphore.

#include<stdio.h>
#include<unistd.h>
#include<sys/sem.h>

union semun
{
    int val;
    struct semid_ds *buf;
    unsigned short int *array;
};

int main(){
    union semun arg;
    int key, semid;

    key = ftok(".", 'a');
    semid = semget(key,1,IPC_CREAT|0744);
    printf("semid: %d\n",semid);
    arg.val = 1; // cause binary sem.
    semctl(semid,0,SETVAL,arg);
    return 0;
}