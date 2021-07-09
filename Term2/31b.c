// Name: Keshav Singhal
// Roll number: IMT2018511
// Date: May, 2021
// Description: a program to create a couting semaphore and initialize value to the semaphore.

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
    semid = semget(key,1,0);
    printf("semid: %d\n",semid);
    arg.val = 2;
    semctl(semid,0,SETVAL,arg);
    return 0;
}