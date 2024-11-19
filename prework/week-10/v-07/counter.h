#ifndef __COUNTER_H
#define __COUNTER_H

#include <pthread.h>

typedef struct SCounterTag{
    pthread_mutex_t _mtx;
    int _val;
} SCounter;

SCounter *makeCounter();
void freeCounter(SCounter *);
int incCounter(SCounter *);
int decCounter(SCounter *);
void resetZeroCounter(SCounter *);

#endif