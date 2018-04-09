#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h> 
#include <unistd.h> 
#include <string.h> 
#define DEBUG 0 
//#define DEBUG 1    //控制是否进行调试的开关。 
int num=0; 
pthread_mutex_t mylock=PTHREAD_MUTEX_INITIALIZER; 
pthread_cond_t qready=PTHREAD_COND_INITIALIZER; 
void * thread_func(void *arg) 
{ 
    int i=(int)arg;   
    int ret; 
    sleep(5-i);//线程睡眠,然最先生成的线程，最后苏醒 
    pthread_mutex_lock(&mylock);//调用 pthread_cond_wait前，必须获得互斥锁 
    while(i!=num) 
    { 
#ifdef DEBUG 
        printf("thread %d waiting\n",i); 
#endif 
        ret=pthread_cond_wait(&qready,&mylock);//该函数把线程放入等待条件的线程列表，然后对互斥锁进行解锁，这两部都是原子操作。并且在 pthread_cond_wait 返回时，互斥量再次锁住。 
        if(ret==0) 
        { 
#ifdef DEBUG 
            printf("thread %d wait success\n",i); 
#endif 
        }else 
        { 
#ifdef DEBUG 
            printf("thread %d wait failed:%s\n",i,strerror(ret)); 
#endif 
        } 
    } 
    printf("thread %d is running \n",i); 
    num++; 
    pthread_mutex_unlock(&mylock);//解锁 
    pthread_cond_broadcast(&qready);//唤醒等待该条件的所有线程 
    return (void *)0; 
} 
int main(int argc, char** argv) { 
   
    int i=0,err; 
    pthread_t tid[4]; 
    void *tret; 
    for(;i<4;i++) 
    { 
        err=pthread_create(&tid[i],NULL,thread_func,(void *)i); 
        if(err!=0) 
        { 
            printf("thread_create error:%s\n",strerror(err)); 
            exit(-1); 
        } 
    } 
    for (i = 0; i < 4; i++) 
    { 
        err = pthread_join(tid[i], &tret); 
        if (err != 0) 
        { 
            printf("can not join with thread %d:%s\n", 
i,strerror(err)); 
            exit(-1); 
        } 
    } 
    return 0; 
} 


#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h> 
#include <unistd.h> 
#include <string.h> 
int num=0; 
pthread_mutex_t mylock=PTHREAD_MUTEX_INITIALIZER; 
void *add(void *arg) { 
    int i = 0,tmp; 
    for (; i <500; i++) 
    { 
        pthread_mutex_lock(&mylock); 
        tmp=num+1; 
        num=tmp; 
        printf("+1,result is:%d\n",num); 
        pthread_mutex_unlock(&mylock); 
    } 
    return ((void *)0); 
} 
void *sub(void *arg) 
{ 
    int i=0,tmp; 
    for(;i<500;i++) 
    { 
        pthread_mutex_lock(&mylock); 
        tmp=num-1; 
        num=tmp; 
        printf("-1,result is:%d\n",num); 
        pthread_mutex_unlock(&mylock); 
    } 
    return ((void *)0); 
} 
int main(int argc, char** argv) { 
   
    pthread_t tid1,tid2; 
    int err; 
    void *tret; 
    err=pthread_create(&tid1,NULL,add,NULL);//创建线程 
    if(err!=0) 
    { 
        printf("pthread_create error:%s\n",strerror(err)); 
        exit(-1); 
    } 
    err=pthread_create(&tid2,NULL,sub,NULL); 
    if(err!=0) 
    { 
        printf("pthread_create error:%s\n",strerror(err)); 
          exit(-1); 
    } 
    err=pthread_join(tid1,&tret);//阻塞等待线程 id 为 tid1 的线程，直到该线程退出 
    if(err!=0) 
    { 
        printf("can not join with thread1:%s\n",strerror(err)); 
        exit(-1); 
    } 
    printf("thread 1 exit code %d\n",(int)tret); 
    err=pthread_join(tid2,&tret); 
    if(err!=0) 
    { 
        printf("can not join with thread1:%s\n",strerror(err)); 
        exit(-1); 
    } 
    printf("thread 2 exit code %d\n",(int)tret); 
    return 0; 
} 
