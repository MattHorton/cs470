#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include"buffer.h"




int main(int argc, char** argv) {
    //argv[0] is how long to sleep before terminating
    //argv[1] is number of producer threads
    //argv[2] is number of consumer threads
    
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