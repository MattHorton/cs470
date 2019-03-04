#ifndef __BUFFER_H
#define __BUFFER_H
#include"c-ringbuf/ringbuf.h"



typedef int buffer_item;
int insert_item(buffer_item item);
int remove_item(buffer_item* item);



#endif /* __BUFFER_H */