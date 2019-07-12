#include<stdio.h>
#include<pwd.h>
int main(){
    struct passwd *ptr;
    char *id="hu";
    ptr=getpwnam(id);//获取口令文件项
    printf("%s:%s:%d:%d:%s:%s:%s\n",ptr->pw_name,ptr->pw_passwd,ptr->pw_uid,ptr->pw_gid,ptr->pw_gecos,ptr->pw_dir,ptr->pw_shell);
    return 0;
}
