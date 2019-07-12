#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int g=6;
char buf[]="a write to stdout\n";
int main(void){
    int var;
    pid_t pid;
    var=88;
    if(write(STDOUT_FILENO,buf,sizeof(buf)-1)!=sizeof(buf)-1)
    printf("write error\n");
    printf("before fork\n");

    if((pid=fork())<0)
    printf("fork error");
    else if(pid==0){
        g++;
        var++;
    }else{
        sleep(2);
    }
    printf("pid=%ld,ppid=%d,uid=%d,euid=%d,gid=%d,egid=%d,g=%d,var=%d\n",(long)getpid(),getppid(),getuid(),geteuid(),getgid(),getegid(),g,var);
    exit(0);
}
