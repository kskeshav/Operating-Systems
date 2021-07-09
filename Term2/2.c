// Name: Keshav Singhal
// Roll number: IMT2018511
// Date: May, 2021
// Description: a program to print the system resource limits.

#include<stdio.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <unistd.h>

int main(){

    struct rlimit r;

    getrlimit(RLIMIT_AS , &r);
    printf("Soft Limit : %lu \nHard Limit : %lu\n\n",r.rlim_cur,r.rlim_max);
    getrlimit(RLIMIT_CORE , &r);
    printf("Soft Limit : %lu \nHard Limit : %lu\n\n",r.rlim_cur,r.rlim_max);
    getrlimit(RLIMIT_CPU , &r);
    printf("Soft Limit : %lu \nHard Limit : %lu\n\n",r.rlim_cur,r.rlim_max);
    getrlimit(RLIMIT_FSIZE , &r);
    printf("Soft Limit : %lu \nHard Limit : %lu\n\n",r.rlim_cur,r.rlim_max);
    return 0;
}