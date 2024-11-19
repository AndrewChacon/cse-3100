/* Implementation of all the functions should be thread-safe */

#include "counter.h"
#include <stdlib.h>

SCounter* makeCounter() {
    SCounter* c = (SCounter*)malloc(sizeof(SCounter));
    c->val = 0;
    pthread_mutex_init(&c->mtx, NULL);
    return c;
}

void freeCounter(SCounter* c) {
    pthread_mutex_destroy(&c->mtx);
    free(c);
}

void incCounter(SCounter* c) {
    pthread_mutex_lock(&c->mtx);
    c->val++;
    pthread_mutex_unlock(&c->mtx);
}

void decCounter(SCounter* c) {
    pthread_mutex_lock(&c->mtx);
    c->val--;
    pthread_mutex_unlock(&c->mtx);
}

void resetZeroCounter(SCounter* c) {
    pthread_mutex_lock(&c->mtx);
    c->val = 0;
    pthread_mutex_unlock(&c->mtx);
}