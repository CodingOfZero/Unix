#include<sys/stat.h>
#include<stdio.h>
#include<fcntl.h>
int main(int argc,char *argv[]){
    int fd,i;
    struct stat buf;
    struct timespec times[2];
    for(i=1;i<argc;i++){
         if(stat(argv[i],&buf)<0){
            printf("%s:stat error\n",argv[i]);
            continue;
         }
         if((fd=open(argv[i],O_RDWR|O_TRUNC))<0){
            printf("%s:open error\n",argv[i]);
            continue;
         }
        times[0]=buf.st_atim;
        times[1]=buf.st_mtim;
        if(futimens(fd,times)<0)
            printf("%s:futimes error\n",argv[i]);
        close(fd);
     }
    return 0;
}
