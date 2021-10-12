/*************************************************************************                                                                                                                                                                                                                                                                                                                                                                                                                   
    > File Name: pro_cus.cpp
    > Author: Black_K
    > Mail: xzp01@foxmail.com 
    > Created Time: 2021年10月12日 星期二 09时28分12秒
 ************************************************************************/

#include<iostream>
#include<queue>
#include<pthread.h>
using namespace std;

#define CAPACITY_MAX 6

//class BlockQueue;

class BlockQueue{
    private:
        int _capacity;//容量
        std::queue<int> _queue;//队列
        pthread_mutex_t _mutex;//互斥锁
        pthread_cond_t _cond_cus;//条件变量? 消费者
        pthread_cond_t _cond_pro;//生产者
    public:
        bool Push(int data){
           //加锁
            pthread_mutex_lock(&_mutex);
            while(_queue.size()==_capacity){
                pthread_cond_wait(&_cond_pro,&_mutex);//在生产者队列等待，解锁、等待、加锁
            }   
            //插入数据
            _queue.push(data);
            //唤醒
            pthread_cond_signal(&_cond_cus);
            //解锁
            pthread_mutex_unlock(&_mutex);
            return true;
        }   
        bool Pop(int* data){
            //加锁
            pthread_mutex_lock(&_mutex);
            //判断
            while(_queue.empty()){
            //等待
            pthread_cond_wait(&_cond_cus,&_mutex);
            }   
            //取出数据
            *data=_queue.front();
            _queue.pop();
            //唤醒
            pthread_cond_signal(&_cond_pro);
            //解锁
            pthread_mutex_unlock(&_mutex);
            return true;
        }   
        BlockQueue(int cap=CAPACITY_MAX)
            :_capacity(cap){
                pthread_mutex_init(&_mutex,NULL);
                pthread_cond_init(&_cond_cus,NULL);
                pthread_cond_init(&_cond_pro,NULL);
            }   
        ~BlockQueue(){
                pthread_mutex_destroy(&_mutex);
                pthread_cond_destroy(&_cond_cus);
                pthread_cond_destroy(&_cond_pro);
        }   
};


//生产者入口函数
void* entry_pro(void* arg){
    BlockQueue* q=(BlockQueue*)arg;
    int data=0;
    while(1){
        q->Push(data);
        printf("线程：%p-push data:%d\n",pthread_self(),data++);
    }   
    return NULL;
}
//消费者入口函数
void* entry_cus(void* arg){
    BlockQueue* q=(BlockQueue*)arg;
    int data;
    while(1){
    q->Pop(&data);
    printf("线程：%p-get---------- data:%d\n",pthread_self(),data);
    }   
    return NULL;
}

//主函数
int main(int argc,char* argv[]){
    BlockQueue bq; 
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
