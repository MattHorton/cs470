#include"buffer.h"
#include"c-ringbuf/ringbuf.h"

#define BUFFER_SIZE 5
buffer_item buffer[BUFFER_SIZE];
int index = 0;



int insert_item(buffer_item item) {
    //insert item into buffer
    int itm = item;

    //return 0 for success
    return -1;//failed
}
int remove_item(buffer_item* item) {
    int itm = *item;
    //get mutex
    //itm = buffer[index]
    //index--
    //full and empty must be checked
    //remove item from buffer place value into item
    //release mutex
    //signal
    //return 0 for success
    return -1;//failed
}
void bufInit() {
    index = 0;
}