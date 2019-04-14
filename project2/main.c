#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include"buffer.h"
#include<stdlib.h>//required for rand()

#define RAND_MAX 10

sem_t empty, full, mtx;


void* producer(void* param);
void* consumer(void* param);
void initializeBuffer();



int main(int argc, char** argv) {
    sem_t sem;
    //create semaphore initialize it to 1
    sem_init(&sem, 0, 1);
    //pointer, flag for lvl sharing, initial value

    //acquire semaphore
    sem_wait(&sem);
    //  critical section

    //release semaphore
    sem_post(&sem);
    //note : all sem functions rtrn 0 when successful



    

    pthread_t producerThread;
    pthread_t consumerThread;

    //1. get command line arguments
        //argv[1] is how long main is to sleep before terminating
        //argv[2] is number of producer threads
        //argv[3] is number of consumer threads
    //2. initialize the buffer
    initializeBuffer();
    //3. create producer threads
    for(int i = 0; i < (int)argv[2]; i++) {
        pthread_create(&producerThread, 0, producer((void*)i), 0);
    }
    //4. create consumer threads
    for(int i = 0; i < (int)argv[3]; i++) {
        pthread_create(&consumerThread, 0, consumer((void*)i), 0);
    }
    //5. sleep
    sleep(argv[1]);
    //6. exit() 
    return 0;
}
void* producer(void* param) {
    buffer_item item;

    while(1) {
        //sleep for random period of time
        sleep(rand());
        //generate a random number
        item = rand();
        if(insert_item(item))
            printf("report error condition");
        else
            printf("producer %d produced %d\n", param, item);   
    }
    pthread_exit(0);
}
void* consumer(void* param) {
    buffer_item item;

    while(1) {
        //sleep for random period of time
        sleep(rand());
        //generate a random number
        item = rand();
        if(remove_item(&item))
            printf("report error condition");
        else
            printf("consumer %d consumed %d\n", param, item);   
    }
    pthread_exit(0);
}
void initializeBuffer() {
    //initialize mutex object and empty and full semaphores
    sem_init(&empty, 0, 1);
    sem_init(&full, 0, 0);
    sem_init(&mtx, 0, 0);
    bufInit();
}