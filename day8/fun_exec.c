#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
char *env_init[]={"USER=unknown","PATH=/tmp",NULL};
int main(void){
    pid_t pid;
    if((pid=fork())<0)
    ;
    else if(pid==0){
        if(execle("/home/hu/c_unix/echoall","echoall","myarg1","MY ARG2",(char *)0, env_init)<0)
            printf("execle error\n");
    }
    if((waitpid(pid,NULL,0))<0)
        printf("wait error");
    if((pid=fork())<0)
    ;
    else if(pid==0){
        if(execlp("/home/hu/c_unix/echoall","echoall","only 1 arg",(char *)0)<0)
            printf("execlp error\n");
    }
    exit(0);
}
