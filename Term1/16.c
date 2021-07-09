// program number: 16
// Student Name: Keshav Singhal; Register Number: IMT2018511
// Date: 25/02/2021
// Description : a program to perform mandatory locking.
#include<stdio.h>
#include<fcntl.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	int fd;
	struct flock lock;
	
	fd = open(argv[1],O_RDWR);
	printf("%d\n", fd);
	// memset(&lock,0,sizeof(lock));
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

	int f = fcntl(fd,F_SETLKW,&lock);

	printf("%s\n","locked");
	printf("%d\n",f);

	getchar();
	lock.l_type = F_UNLCK;
	fcntl(fd,F_SETLKW,&lock);
	printf("%s\n", "unlocked");
	
	close(fd);
	return 0;
}