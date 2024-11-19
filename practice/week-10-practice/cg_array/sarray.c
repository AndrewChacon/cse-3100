/* Implementing a shared array - coarse grained locking */

#include "sarray.h"
#include <stdlib.h>
#include <pthread.h>

SArray* makeAnArray(int sz) {
    SArray* p = (SArray*)malloc(sizeof(SArray)); 
    p->sz = sz;
    p->data = (int*)calloc(sz, sizeof(int)); //allocate space to store int -> sz of them
    pthread_mutex_init(&p->lock, NULL);
    return p;
}

void freeArray(SArray* a) {
    pthread_mutex_destroy(&a->lock);
    free(a->data);
    free(a);
}

int getValueAt(SArray* a, int idx) {
    pthread_mutex_lock(&a->lock);
    int rv = a->data[idx];
    pthread_mutex_unlock(&a->lock);
    return rv;
}

void setValueAt(SArray* a, int idx, int val) {
    pthread_mutex_lock(&a->lock);
    a->data[idx] = val;
    pthread_mutex_unlock(&a->lock);
}
