#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int g=6;
char buf[]="a write to stdout\n";
int main(void){
    int var;
    pid_t pid;
    var=88;
    printf("before vfork\n");
    if((pid=vfork())<0)
    printf("fork error");
    else if(pid==0){
        g++;
        var++;
        _exit(0);
    }
    printf("pid=%ld,ppid=%d,uid=%d,euid=%d,gid=%d,egid=%d,g=%d,var=%d\n",(long)getpid(),getppid(),getuid(),geteuid(),getgid(),getegid(),g,var);
    exit(0);
}
