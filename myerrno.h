#ifndef MYERRNO
#define NYERRNO
#include<errno.h>
#include<stdarg.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXLINE 4096
/*
*Print a message and return a caller
*Caller specifies "errnoflag"
*/
static void err_doit(int errnoflag,int error,const char*fmt,va_list ap);
/*
*Nonfatal error related to a system call
*Print a message and return.
*/
void err_ret(const char*fmt,...);
/*
*Fatal error related to a system call
*Print a message and terminate.
*/
void err_sys(const char*fmt,...);
/*
*Nonfatal error unrelated to a system call
*Error code passed as explict parameter
*Print a message and return.
*/
void err_cont(int error,const char*fmt,...);
/*
*Fatal error unrelated to a system call
*Error code passed as explict parameter
*Print a message and terminate
*/
void err_exit(int error,const char*fmt,...);
/*
*Fatal error related to a system call
*Print a message,dump core,and terminate.
*/
void err_dump(const char*fmt,...);
/*
*Nonfatal error unrelated to a system call
*Print a message and return.
*/
void err_msg(const char*fmt,...);
/*
*Fatal error unrelated to a system call
*Print a message and terminate.
*/
void err_quit(const char*fmt,...);
void err_ret(const char *fmt,...){
    va_list ap;
    va_start(ap,fmt);
    err_doit(1,errno,fmt,ap);
    va_end(ap);
}
void err_sys(const char *fmt,...){
    va_list ap;
    va_start(ap,fmt);
    err_doit(1,errno,fmt,ap);
    va_end(ap);
    exit(1);
}
void err_cont(int error,const char *fmt,...){
    va_list ap;
    va_start(ap,fmt);
    err_doit(1,error,fmt,ap);
    va_end(ap);
}
void err_exit(int error,const char *fmt,...){
    va_list ap;
    va_start(ap,fmt);
    err_doit(1,error,fmt,ap);
    va_end(ap);
    exit(1);
}
void err_dump(const char *fmt,...){
    va_list ap;
    va_start(ap,fmt);
    err_doit(1,errno,fmt,ap);
    va_end(ap);
    abort();    //dump core and terminate
    exit(1);//shouldn't get here
}
void err_msg(const char *fmt,...){
    va_list ap;
    va_start(ap,fmt);
    err_doit(0,0,fmt,ap);
    va_end(ap);
}
void err_quit(const char *fmt,...){
    va_list ap;
    va_start(ap,fmt);
    err_doit(0,0,fmt,ap);
    va_end(ap);
    exit(1);
}
static void err_doit(int errnoflag,int error,const char*fmt,va_list ap){
    char buf[MAXLINE];
    vsnprintf(buf,MAXLINE-1,fmt,ap);
    if(errnoflag)
        snprintf(buf+strlen(buf),MAXLINE-strlen(buf)-1,": %s",strerror(error));
    strcat(buf,"\n");
    fflush(stdout);
    fputs(buf,stderr);
    fflush(NULL);
}
#endif
