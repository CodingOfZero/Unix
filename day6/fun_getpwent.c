#include<stdio.h>
#include<pwd.h>
int main(void){
    struct passwd *ptr;
    setpwent();
    while((ptr=getpwent())!=NULL){
        printf("%s:%s:%d:%d:%s:%s:%s\n",ptr->pw_name,ptr->pw_passwd,ptr->pw_uid,ptr->pw_gid,ptr->pw_gecos,ptr->pw_dir,ptr->pw_shell);
    }
    endpwent();
    return 0;
}

