/*************************************************************************
    > File Name: create.c
    > Author: Black_K
    > Mail: xzp01@foxmail.com 
    > Created Time: 2021年10月10日 星期日 16时50分58秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
void* thread_entry(void* arg){
    printf("%s\n",(char*)arg);
    while(1){
    printf("thread_entry excute:\n");
    sleep(1);                                                                                                                                                                                  
    }
    return NULL;
}
int main(int argc,char* argv[]){
//"start coding K:"
    pthread_t tid;
    int ret;
    char* ptr="实习冲刺：";
    ret=pthread_create(&tid,NULL,thread_entry,(void*)ptr);
    if(ret!=0){
        printf("pthread_create failed\n");
        return -1;
    }
    while(1){
        printf("主线程运行\n");
        sleep(1);
    }
    return 0;
}
