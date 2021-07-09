// Name: Keshav Singhal
// Roll number: IMT2018511
// Date: May, 2021
// Description: a program to create a shared memory.
// a. write some data to the shared memory
// b. attach with O_RDONLY and check whether you are able to overwrite.
// c. detach the shared memory
// d. remove the shared memory

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

void get_data(char* pointer, int size)
{
    for(int i = 0; i < size; i++)
        printf("%c ", *(pointer+i));
    printf("\n");
    return ;
}

int main()
{
    key_t key;
    int rand;
    key = ftok(".",'a');
    int size = 1024;
    int shmid = shmget(key + rand%10,size,0666|IPC_CREAT); 
    printf("shmid: %d\n", shmid);
    char *pointer = (char*) shmat(shmid,(void*)0,0);
    sleep(2);
    for(int i = 0; i < 10; i++)
        *(pointer + i) = 'a';
    printf("Data written :\n");
    get_data(pointer, size);
    char* pointer_read_only = (char*)shmat(shmid, (void*)0, 0 | SHM_RDONLY);
    printf("Attached with O_RDONLY!\n");
    printf("Attempting to overwrite...\n");
    sleep(2);
    // for(int i = 0; i < 10; i++)
    //     *(pointer_read_only + i) = 'b'; // lines for overwriting. results in seg fault.
    printf("Reading after an overwrite attempt!\n");
    get_data(pointer_read_only, size);
    int val = shmdt(pointer);
    val = shmdt(pointer_read_only);
    printf("Detached!\n");
    shmctl(shmid, IPC_RMID,NULL);
    printf("Removed!\n");
    return 0;
}