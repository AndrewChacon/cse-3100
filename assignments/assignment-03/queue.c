#include "queue.h"
#include <stdio.h>  

void initQueue(Queue* q)
{
    initStack(&q->stack1); 
    initStack(&q->stack2); 
}

void enQueue(Queue* q, int number)
{
    pushStack(&q->stack1, number); 
}

int deQueue(Queue* q)
{
    if (isEmpty(&q->stack2)) {

        while (!isEmpty(&q->stack1)) {
            int val = popStack(&q->stack1);
            pushStack(&q->stack2, val);
        }
    }
    
    if (isEmpty(&q->stack2)) {
        fprintf(stderr, "Queue is empty\n");
        exit(1);  
    }

    return popStack(&q->stack2); 
}

void freeQueue(Queue* q)
{
    freeStack(&q->stack1); 
    freeStack(&q->stack2); 
}
