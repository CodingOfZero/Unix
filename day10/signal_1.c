#include"myerrno.h"
#include<signal.h>
void(*signal_1(int signo, void(*func)(int)))(int){
    struct sigaction act,oact;
    act.sa_handler=func;
    sigemptyset(&act.sa_mask);
    act.sa_flags=0;
    if(signo==SIGALRM){
 #ifdef SA_INTERRUPT
        act.sa_flags|=SA_INTERRUPT;
 #endif
    }else{
        act.sa_flags|=SA_RESTART;
    }
    if(sigaction(signo,&act,&oact)<0)
        return(SIG_ERR);
    return(oact.sa_handler);
}
/*don't restart*/
void(*signal_2(int signo, void(*func)(int)))(int){
    struct sigaction act,oact;
    act.sa_handler=func;
    sigemptyset(&act.sa_mask);
    act.sa_flags=0;
 #ifdef SA_INTERRUPT
        act.sa_flags|=SA_INTERRUPT;
 #endif
    if(sigaction(signo,&act,&oact)<0)
        return(SIG_ERR);
    return(oact.sa_handler);
}
int main()
{return 0;}
