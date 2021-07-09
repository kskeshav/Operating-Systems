#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "definitions.h"

char* get_file(char* username){
    char* filename = (char*)malloc(BUF_SIZE*sizeof(char));
    strcpy(filename,username);
    char extension[5] = ".txt";
    strncat(filename,extension,sizeof(extension));
    return filename;
}

int sign_up(int option, char* username, char* sec_username, char* password)
{
    int fd;
    fd = open(get_file(username),O_WRONLY);
    if(fd != -1)
    {
        perror("user already exist!");
        return -1;
    }
    else
    {
        close(fd);
    }
    fd = open(get_file(username),O_WRONLY | O_CREAT,0644);
    if(fd == -1)
    {
        perror("signup"); 
        return -1;
    }
    //implement locking.
    struct user u;
    strcpy(u.username,username);
    strcpy(u.password,password);
    u.balance = 0;
    u.active = 1;
    switch(option){
        case SIGN_UP_AS_USER :
            strcpy(u.type,"normal");
            break;
        case ADD_USER :
            strcpy(u.type,"normal");
            break;
        case SIGN_UP_AS_JOINT :
            strcpy(u.type,"joint");
            strcpy(u.sec_username, sec_username);
            break;
        case SIGN_UP_AS_ADMIN :
            strcpy(u.type,"admin");
            break;
    }
    write(fd,&u,sizeof(struct user));
    close(fd);
    return 0;
}

int sign_in(int option, char* username, char* password){
    static struct flock lock;
    lock.l_type = F_RDLCK;
    lock.l_start = 0;
    lock.l_whence = SEEK_SET;
    lock.l_len = sizeof(struct user);
    lock.l_pid = getpid();

    int fd = open(get_file(username),O_RDONLY,0644);
    if(fd == -1){
        perror("signin"); return -1;
    }
    struct user u;
    if(fcntl(fd, F_SETLKW, &lock)==-1) {perror("fcntl") ; return -1;}
    // start of critical section
    lseek(fd,0,SEEK_SET);
    read(fd,&u,sizeof(struct user));
    if((strcmp(u.password,password)!=0) 
        || (option==SIGN_IN_AS_USER && (strcmp(u.type,"normal")!=0))
        || (option==SIGN_IN_AS_ADMIN && (strcmp(u.type,"admin")!=0))
        || (option==SIGN_IN_AS_JOINT && (strcmp(u.type,"joint")!=0))) return -1;

    while(1){
        lseek(fd,0,SEEK_SET);
        read(fd,&u,sizeof(struct user));
        if (u.active < 1)
        {
            break;
        }
    }
    u.active = 1;
    lseek(fd,0,SEEK_SET);
    if(write(fd,&u,sizeof(struct user))==-1) {perror("signin"); return -1;}
    // end of critical section
    lock.l_type = F_UNLCK;
    fcntl(fd,F_SETLKW,&lock);
    close(fd);
    return 0;
}

int deposit(char* username, int amt){
    static struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_start = sizeof(struct user);
    lock.l_whence = SEEK_SET;
    lock.l_len = sizeof(struct user);
    lock.l_pid = getpid();
    
    int fd = open(get_file(username),O_RDWR,0644);
    if(fd == -1){
        perror("signin"); return -1;
    }
    struct user u;
    if(fcntl(fd, F_SETLKW, &lock)==-1) {perror("fcntl") ; return -1;}
    // start of critical section
    lseek(fd,0,SEEK_SET);
    if(read(fd,&u,sizeof(struct user))==-1) {perror("read"); return -1;}
    u.balance += amt;
    lseek(fd,0,SEEK_SET);
    if(write(fd,&u,sizeof(struct user))==-1) {perror("write"); return -1;}
    // end of critical section
    lock.l_type = F_UNLCK;
    fcntl(fd,F_SETLKW,&lock);
    close(fd);
    return 0;
}

int withdraw(char* username, int amt){
    static struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_start = sizeof(struct user);
    lock.l_whence = SEEK_SET;
    lock.l_len = sizeof(struct user);
    lock.l_pid = getpid();

    int fd = open(get_file(username),O_RDWR,0644);
    if(fd == -1)
    {
        perror("signin"); 
        return -1;
    }
    struct user u;
    if(fcntl(fd, F_SETLKW, &lock)==-1) 
    {
        perror("fcntl") ; 
        return -1;
    }
    // start of critical section
    lseek(fd,0,SEEK_SET);
    if(read(fd,&u,sizeof(struct user)) == -1) 
    {
        perror("read"); 
        return -1;
    }
    u.balance -= amt;
    if(u.balance < 0) return -1;
    lseek(fd,0,SEEK_SET);
    if(write(fd,&u,sizeof(struct user))==-1) 
    {
        perror("write"); 
        return -1;
    }
    // end of critical section
    lock.l_type = F_UNLCK;
    fcntl(fd,F_SETLKW,&lock);
    close(fd);
    return 0;
}

int check_balance(char* username){
    static struct flock lock;
    lock.l_type = F_RDLCK;
    lock.l_start = sizeof(struct user);
    lock.l_whence = SEEK_SET;
    lock.l_len = sizeof(struct user);
    lock.l_pid = getpid();

    int fd = open(get_file(username),O_RDONLY,0644);
    if(fd == -1)
    {
        perror("signin"); 
        return -1;
    }
    struct user u;
    if(fcntl(fd, F_SETLKW, &lock)==-1) 
    {
        perror("fcntl") ; 
        return -1;
    }
    // start of critical section
    lseek(fd,0,SEEK_SET);
    if(read(fd,&u,sizeof(struct user))==-1) 
    {
        perror("read");
        return -1;
    }
    // end of critical section
    lock.l_type = F_UNLCK;
    fcntl(fd,F_SETLKW,&lock);
    close(fd);
    return u.balance;
}

int change_password(char* username, char* pwd){
    static struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_start = 0;
    lock.l_whence = SEEK_SET;
    lock.l_len = sizeof(struct user);
    lock.l_pid = getpid();

    int fd = open(get_file(username),O_RDWR,0644);
    if(fd == -1)
    {
        perror("change pwd"); 
        return -1;
    }
    struct user u;
    lseek(fd,0,SEEK_SET);
    if(fcntl(fd, F_SETLKW, &lock)==-1) 
    {
        perror("fcntl") ; 
        return -1;
    }
    // start of critical section
    if(read(fd,&u,sizeof(struct user))==-1) 
    { 
        perror("read"); 
        return -1; 
    }
    strcpy(u.password,pwd);
    lseek(fd,0,SEEK_SET);
    if(write(fd,&u,sizeof(struct user))==-1) 
    { 
        perror("write"); 
        return -1; 
    }
    // end of critical section
    lock.l_type = F_UNLCK;
    fcntl(fd,F_SETLKW,&lock);
    close(fd);
    return 0;
}

char* get_details(char* username){
    static struct flock lock;
    lock.l_type = F_RDLCK;
    lock.l_start = 0;
    lock.l_whence = SEEK_SET;
    lock.l_len = 0;
    lock.l_pid = getpid();

    int fd = open(get_file(username),O_RDWR,0644);
    if(fd == -1)
    {
        perror("open"); 
        return "user does not exist\n";
    }

    struct user u;
    if(fcntl(fd, F_SETLKW, &lock)==-1) 
    {
        perror("fcntl"); 
        return "sorry, section is locked.\n";
    }
    // start of critical section
    lseek(fd,0,SEEK_SET);
    if(read(fd,&u,sizeof(struct user))==-1)
    {
        perror("read"); 
        return "unable to read file\n";
    }
    // end of critical section
    lock.l_type = F_UNLCK;
    fcntl(fd,F_SETLKW,&lock);
    close(fd);
    char* user_details = (char*)malloc(BUF_SIZE * sizeof(char));
    if (strcmp(u.type,"joint") == 0)
    {
    	sprintf(user_details,"username : %s\nsecondary username : %s\npassword : %s\ntype : %s\nbalance : %d\n",
        u.username,u.sec_username,u.password,u.type,u.balance);
    }
    else{
	    sprintf(user_details,"username : %s\npassword : %s\ntype : %s\nbalance : %d\n",
        u.username,u.password,u.type,u.balance);
    }
    return user_details;
}

int exit_user(char* username){
    static struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_start = sizeof(struct user);
    lock.l_whence = SEEK_SET;
    lock.l_len = sizeof(struct user);
    lock.l_pid = getpid();
    
    int fd = open(get_file(username),O_RDWR,0644);
 
    if(fd == -1){
        perror("signin"); return -1;
    }
    // struct user u;
    // if(fcntl(fd, F_SETLKW, &lock)==-1) {perror("fcntl") ; return -1;}
    // // start of critical section
    // lseek(fd,0,SEEK_SET);
    // if(read(fd,&u,sizeof(struct user))==-1) {perror("read"); return -1;}
    // u.active -= 1;
    
    // lseek(fd,0,SEEK_SET);
    // if(write(fd,&u,sizeof(struct user))==-1) {perror("write"); return -1;}
    // end of critical section
    lock.l_type = F_UNLCK;
    fcntl(fd,F_SETLKW,&lock);
    close(fd);
    return 0;
}

int delete_user(char* username){
    int fd = open(get_file(username),O_RDWR,0644);
    if(fd == -1)
    { 
        perror("open");
    }
    return unlink(get_file(username));
}

int modify_user(char* sec_username, char* username, char* new_username, char* password) {
    static struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_start = 0;
    lock.l_whence = SEEK_SET;
    lock.l_len = 0;
    lock.l_pid = getpid();
    int option;
    int fd = open(get_file(username),O_RDWR,0644);
    if(fd == -1)
    {
        perror("modify user");
        return -1;
    }
    struct user u;
    if(fcntl(fd, F_SETLKW, &lock)==-1) 
    {
        perror("fcntl");
        return -1;
    }
    // start of critical section
    lseek(fd,0,SEEK_SET);
    if(read(fd,&u,sizeof(struct user))==-1) 
    { 
        perror("read"); 
        return -1; 
    }
    delete_user(username);
    
    if(strcmp(u.type,"normal")==0) option = SIGN_UP_AS_USER;
    else option = SIGN_UP_AS_JOINT;

    if (strcmp(sec_username,"Yes")==0)
    {
        sign_up(option, username, new_username, password);
        deposit(username, u.balance);
    }
    else
    {
        sign_up(option, new_username, u.sec_username, password);
        deposit(new_username, u.balance);
    }
    // end of critical section
    lock.l_type = F_UNLCK;
    fcntl(fd,F_SETLKW,&lock);
    close(fd);
    return 0;
}