#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
	int pid, pid1, pid2;

    pid = fork();
    printf("%d\n", pid);
    return 0;

}