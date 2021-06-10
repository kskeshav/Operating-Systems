// program number: 1
// Student Name: Keshav Singhal; Register Number: IMT2018511
// Date: 25/02/2021
// Description : Create the following types of a files using system call
// a. soft link (symlink system call)
// b. hard link (link system call)
// c. FIFO (mkfifo Library Function or mknod system call)

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{
    int soft = symlink("src.txt","soft_test.txt");
    printf("soft link : %d\n",soft);

    int hard = link("src.txt","hard_test.txt");
    printf("hard link : %d\n",hard);

    int fifo = mkfifo("fifo_file",S_IRWXU);
    printf("fifo : %d\n",fifo);

    return 0;	
}

