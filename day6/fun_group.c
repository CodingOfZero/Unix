#include<stdio.h>
#include<unistd.h>
#define SIZE 30
int main(void){
    gid_t grouplist[SIZE];
    int n;
    n=getgroups(SIZE,grouplist);
    printf("%d\n",n);
    int i=0;
    while(i<n){
        printf("%d\n",grouplist[i]);
        i++;
    }
    return 0;
}
