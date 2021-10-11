/*************************************************************************                                                                                                                                                                                                                                                                                                                                                                                                                   
  > File Name: cond.c
  > Author: Black_K
  > Mail: xzp01@foxmail.com 
  > Created Time: 2021年10月11日 星期一 17时40分23秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>


pthread_mutex_t mutex;
pthread_cond_t cond_coo;
pthread_cond_t cond_cus;

int bowl=1;//1 有 0没有
void* cooker_entry(void* arg){
    while(1){
        //加锁
        pthread_mutex_lock(&mutex);
        if(bowl==1){
            //等待
            pthread_cond_wait(&cond_coo,&mutex);
        }
        //做饭
        printf("面好了；；吃面吧;\n");
        bowl++;
        //唤醒顾客
        pthread_cond_signal(&cond_cus);
        //解锁
        pthread_mutex_unlock(&mutex);

    }
    return NULL;
}
void* customer_entry(void* arg){
    while(1){
        //加锁
        pthread_mutex_lock(&mutex);
        if(bowl==0){
            //等待
            pthread_cond_wait(&cond_cus,&mutex);
        }
        //吃饭
        printf("吃面了；；；\n");
        bowl--;
        //唤醒cooker
        pthread_cond_signal(&cond_coo);
        //解锁
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}
int main(int argc,char* argv[]){
    //"start coding K:"
    pthread_t ctid,dtid;
    int ret;
    pthread_cond_init(&cond_coo,NULL);
    pthread_cond_init(&cond_cus,NULL);
    pthread_mutex_init(&mutex,NULL);
    for(int i=0;i<4;++i){
        ret=pthread_create(&ctid,NULL,cooker_entry,NULL);
        if(ret!=0){
            printf("cooker pthread_create error:\n");
            return -1;
        }
    }
    for(int i=0;i<4;++i){
        ret=pthread_create(&dtid,NULL,customer_entry,NULL);
        if(ret!=0){
            printf("customer pthread_create error:\n");
            return -1;
        }
    }
    pthread_join(ctid,NULL);
    pthread_join(dtid,NULL);
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond_cus);
    pthread_cond_destroy(&cond_coo);
    return 0;
}
