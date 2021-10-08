#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
int main(){
    int pipefd[2];
    int ret=pipe(pipefd);
    if(ret<0){
        perror("pipe error:");
        return -1;
    }
    pid_t pid=fork();
    int total=0;
    if(pid<0){
        perror("fork error:");
        exit(-1);
    }else if(pid==0){
        char* ptr="保险箱密码是252525";
        while(1){
            int ret=write(pipefd[1],ptr,strlen(ptr));

            total+=ret;
            printf("父进程写入成功\n:%d",total);
        }
    }else{
        sleep(1);
        char buf[1024];
        read(pipefd[0],buf,1023);
        printf("子进程读取成功,secure passwd:->%s \n",buf);
    }
    return 0;
}
