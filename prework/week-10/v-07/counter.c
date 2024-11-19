#include "counter.h"
#include <stdio.h>

SCounter* makeCounter(){
    SCounter *c = (SCounter *)malloc(sizeof(SCounter));
    pthread_mutex_init(&c->_mtx, NULL);
    c->_val = 0;
    return c;
}

void freeCounter(SCounter* c) {
    pthread_mutex_destroy(&c->_mtx);
    free(c);
}

int incCounter(SCounter* c) {
    pthread_mutex_lock(&c->_mtx);
    int rv = c->_val++; // return value
    pthread_mutex_unlock(&c->_mtx);
    return rv; // returned incremented value
}

int decCounter(SCounter* c) {
    pthread_mutex_lock(&c->_mtx);
    int rv = c->_val--;
    pthread_mutex_unlock(&c->_mtx);
    return rv;
}