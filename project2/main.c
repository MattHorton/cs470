#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include"buffer.h"
#include<stdlib.h>//required for rand()

#define RAND_MAX 10

void* producer(void* param);
void* consumer(void* param);

int main(int argc, char** argv) {
    //argv[1] is how long to sleep before terminating
    //argv[2] is number of producer threads
    //argv[3] is number of consumer threads
    
    while(1) {
        //do nothing
    };

    sem_t sem;
    //create semaphore initialize it to 1
    sem_init(&sem, 0, 1);
    //pointer, flag for lvl sharing, initial value

    //acquire semaphore
    sem_wait(&sem);
    //  critical section
    //release semaphore
    sem_post(&sem);
    //all sem functions rtrn 0 when successful

    return 0;
}



void* producer(void* param) {
    buffer_item item;

    while(true) {
        //sleep for random period of time
        sleep(rand());
        //generate a random number
        item = rand();
        if(insert_item(item))
            fprintf("report error condition");
        else
            printf("producer produced %d\n", item);   
    }
}
void* consumer(void* param) {
    buffer_item item;

    while(true) {
        //sleep for random period of time
        sleep(rand());
        //generate a random number
        item = rand();
        if(remove_item(&item))
            fprintf("report error condition");
        else
            printf("consumer consumed %d\n", item);   
    }
}