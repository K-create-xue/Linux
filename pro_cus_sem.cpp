/*************************************************************************                                                                        
    > File Name: pro_cus_sem.cpp
    > Author: Black_K
    > Mail: xzp01@foxmail.com 
    > Created Time: 2021年10月12日 星期二 19时15分23秒
 ************************************************************************/

#include<pthread.h>
#include<semaphore.h>
#include<iostream>
#include<vector>
using namespace std;

#define MAX_CAPACITY 5
class RingQueue{
    private:
        std::vector<int> _arry;
        int _capacity;
        int _step_read;
        int _step_write;
        sem_t _sem_lock;
        sem_t _sem_idle;
        sem_t _sem_data;
    public:
        RingQueue(int cap=MAX_CAPACITY)
            :_capacity(cap),
            _step_read(0),
            _step_write(0),
            _arry(cap){
                sem_init(&_sem_lock,0,1);
                sem_init(&_sem_idle,0,cap);
                sem_init(&_sem_data,0,0);
            }   
        ~RingQueue(){
                sem_destroy(&_sem_lock);
                sem_destroy(&_sem_idle);
                                sem_destroy(&_sem_data);            
        }
        bool Push(int data){
            sem_wait(&_sem_idle);
            sem_wait(&_sem_lock);
            _arry[_step_write]=data;
            _step_write=(_step_write+1)%_capacity;
            sem_post(&_sem_lock);
            sem_post(&_sem_data);
            return true;
        }
        bool Pop(int* data){
            sem_wait(&_sem_data);
            sem_wait(&_sem_lock);
            *data=_arry[_step_read];
            _step_read=(_step_read+1)%_capacity;
            sem_post(&_sem_lock);
            sem_post(&_sem_idle);
            return true;
        }
};




//生产者入口函数
void* entry_pro(void* arg){
    RingQueue* q=(RingQueue*)arg;
    int data=0;
    while(1){
        q->Push(data);
        printf("线程：%p-push data:%d\n",pthread_self(),data++);
    }
    return NULL;
}
//消费者入口函数                        
void* entry_cus(void* arg){
    RingQueue* q=(RingQueue*)arg;
    int data;
    while(1){
    q->Pop(&data);
    printf("线程：%p-get---------- data:%d\n",pthread_self(),data);
    }
    return NULL;
}

//主函数
int main(int argc,char* argv[]){
    RingQueue bq;
    int count=3,ret;
    pthread_t  ptid[3],ctid[3];
    for(int i=0;i<count;++i){
        ret=pthread_create(&ptid[i],NULL,entry_pro,&bq);
        if(ret!=0){
            printf("producer pthread create error\n");
            return -1;
        }
    }
    for(int i=0;i<count;++i){
        ret=pthread_create(&ptid[i],NULL,entry_cus,&bq);
        if(ret!=0){
            printf("customer pthread create error\n");
            return -1;
        }
    }
    for(int i=0;i<count;++i){
        pthread_join(ptid[i],NULL);
        pthread_join(ctid[i],NULL);
    }
    return 0;
}                       
