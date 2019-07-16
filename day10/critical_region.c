#include<signal.h>
#include"myerrno.h"
#include"pr_mask.h"
static void sig_int(int);
int main(void){
    sigset_t newmask,oldmask,waitmask;
    pr_mask("proggram start: ");
    if(signal(SIGINT,sig_int)==SIG_ERR)
        err_sys("signal(SIGINT) error");
    sigemptyset(&waitmask);
    sigemptyset(&newmask);
    sigaddset(&newmask,SIGINT);
    sigaddset(&waitmask,SIGUSR1);
    if(sigprocmask(SIG_BLOCK,&newmask,&oldmask)<0)
        err_sys("SIG_BLOCK error");
    /*
    *Critical region of code
    */
    pr_mask("in critical region:");

    /*
    *Pause,allowing all signals except SIGUSR1
    */
    if(sigsuspend(&waitmask)!=-1)
        err_sys("sigsuspend error");

    pr_mask("after return from sigsuspend: ");

    if(sigprocmask(SIG_SETMASK,&oldmask,NULL)<0)
        err_sys("SIG_SETMASK error");

    /*
    *   And continue processing...
    */
    pr_mask("program exit: ");

    exit(0);
}
static void sig_int(int signo){
    pr_mask("\nin sig_int: ");
}
/*proggram start: 
in critical region: SIGINT
^C
in sig_int:  SIGINT SIGUSR1         //在信号处理程序中,处理当前信号会将该信号加入信号屏蔽字中.(SIGINT)
after return from sigsuspend:  SIGINT
program exit:*/
