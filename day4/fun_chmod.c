#include<sys/stat.h>
#include<stdio.h>
int main(){
    struct stat buf;
    if(stat("foo",&buf)<0)
        printf("stat error\n");
    if(chmod("bar",S_IRWXG|S_IROTH)<0)
        printf("chomd bar error\n");
    if(chmod("foo",(buf.st_mode& ~S_IXGRP)|S_ISGID)<0)
        
        printf("chomd bar error\n");
    
    return 0;
}
