#include <stdlib.h>
#include "buffer.h"
#include <stdio.h>

//skeleton
int main(int argc, char** argv) {
    //1. get command line arguments
    //2. initialize buffer
    //3. create producer threads
    //4. create consumer threads
    //5. sleep
    //6. exit
}

void* producer(void* param) {
    buffer_item item;

    while(1) {
        //sleep for a random period of time
        sleep(rand()%100);
        //generate a random number
        item = rand();
        if(insert_item(item))
            fprintf("report error condition", stdout);
        else
            printf("producer produced %d\n", item);        
    }
}

void* consumer(void* param) {
    buffer_item item;

    while(1) {
        //sleep for a random period of time
        sleep(rand()%100);
        //generate a random number
        item = rand();
        if(remove_item(&item))
            fprintf("report error condition", stdout);
        else
            printf("consumer consumed %d\n", item);        
    }
}