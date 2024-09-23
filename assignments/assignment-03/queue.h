#ifndef QUEUE_H
#define QUEUE_H

#include "LStack.h"  

typedef struct Queue {
    Stack stack1;  
    Stack stack2; 
} Queue;


void initQueue(Queue* q);
void enQueue(Queue* q, int number);
int deQueue(Queue* q);
void freeQueue(Queue* q);

#endif