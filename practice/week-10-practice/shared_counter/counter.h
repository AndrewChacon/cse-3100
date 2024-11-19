#ifndef __COUNTER_H
#define __COUNTER_H

#include <pthread.h>

typedef struct SCounter {
    int val;                // counter to be incremented by the threads
    pthread_mutex_t mtx;    // mutex to protect access to val
} SCounter;

SCounter* makeCounter();
void freeCounter(SCounter*);
void incCounter(SCounter*);
void decCounter(SCounter*);
void resetZeroCounter(SCounter*);

#endif