/*************************************************************************
    > File Name: shm_read.c
    > Author: Black_K
    > Mail: xzp01@foxmail.com 
    > Created Time: 2021年10月08日 星期五 20时26分57秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/shm.h>

#define IPC_KEY 0x12345678
int main(int argc,char* argv[]){
//"start coding K:"
    //key_t ftok("./",IPC_KEY);
    int shmid=shmget(IPC_KEY,32,IPC_CREAT|0664);
    if(shmid<0){
        perror("shmget error:");
        return -1;
    }
    void* shm_start=shmat(shmid,NULL,0);
    if(shm_start==(void*)-1){
        perror("shmat error:");
        return -1;
    }
    while(1){
        printf("%s\n",(char*)shm_start);
        sleep(1);
    }
    shmdt(shm_start);                                                                                                                                                   
    shmctl(shmid,IPC_RMID,NULL);
    return 0;
}
