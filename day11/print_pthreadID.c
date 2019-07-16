#include<pthread.h>
#include"myerrno.h"
#include<unistd.h>
pthread_t ntid;
void printids(const char *s){
    pid_t pid;
    pthread_t tid;

    pid=getpid();
    tid=pthread_self();/*由于下列原因,故使用此函数获取自己的线程ID*/

    printf("%s pid %lu tid %lu (0x%lx)\n",s,(unsigned long)pid,(unsigned long)tid,(unsigned long)tid);
}
void *thr_fn(void *arg){
    printids("new thread:");
    return ((void*)0);
}
int main(void){
    int err;
    err=pthread_create(&ntid,NULL,thr_fn,NULL);/*新建线程并不能安全地使用ntid,若新线程在主线程调用此函数返回之前就运行了,则新线程看到的是未被初始化的ntid的内容*/
    if(err!=0)
        err_exit(err,"can't create thread");
    printids("main thread: ");
    sleep(1);   /*主线程需要休眠,否则新线程还没有机会运行,整个进程可能就已经终止了*/
    exit(0);
}
