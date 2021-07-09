// program number: 9
// Student Name: Keshav Singhal; Register Number: IMT2018511
// Date: 25/02/2021
// Description : a program to print the following information about a given file.
    // a. inode
    // b. number of hard links
    // c. uid
    // d. gid
    // e. size
    // f. block size
    // g. number of blocks
    // h. time of last access
    // i. time of last modification
    // j. time of last change

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include<string.h>
#include<time.h>

int main(int argc, char *argv[]){
    struct stat buff;
    int fd,inode,hd,uid,gid,size,bs,nb,ta,tm,tc;
    fd = open(argv[1],O_RDWR);
    struct stat file_stat;
    fstat(fd,&file_stat);
    inode = file_stat.st_ino;
    hd = file_stat.st_nlink;
    uid = file_stat.st_uid;
    gid = file_stat.st_gid;
    size = file_stat.st_size;
    bs = file_stat.st_blksize;
    nb = file_stat.st_blocks;

    printf("inode :%d\n",inode);
    printf("hard links :%d\n",hd);
    printf("uid :%d\n",uid);
    printf("gid :%d\n",gid);
    printf("size :%d\n",size);
    printf("block size :%d\n",bs);
    printf("number of blocks :%d\n",nb);
    printf("LastTime of acces = %s\n",ctime(&(buff.st_atime)));
    printf("Last Modfn time = %s\n",ctime(&(buff.st_mtime)));
    printf("Last change time= %s\n",ctime(&(buff.st_ctime)));
    return 0;

}