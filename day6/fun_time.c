#include<stdio.h>
#include<time.h>
int main(void){
    time_t t;
    struct tm *p;
    char buf1[32];
    time(&t);
    p=localtime(&t);
    if(strftime(buf1,32,"%a %b %d %X %Z %Y",p)!=0)
        printf("%s\n",buf1);
    return 0;
}
