#include<stdio.h>
#include<unistd.h>
int g=6;
char buf[]="a write ro stdout\n";
int main(){
    int var;
    pid_t pid;
    var=88;
    if(write(STDOUT_FILENO,buf,sizeof(buf)-1)!=sizeof(buf)-1)
        printf("write error");
    printf("before fork\n");

}
