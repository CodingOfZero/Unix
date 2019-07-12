#include<stdio.h>
#include<shadow.h>
int main(void){
    struct spwd *p;
    setspent();
    while((p=getspent())!=NULL)
        printf("%s:%s\n",p->sp_namp,p->sp_pwdp);
    endspent();
    return 0;
}
