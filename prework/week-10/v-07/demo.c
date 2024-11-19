#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "counter.h"

typedef struct Input {
    SCounter *shared;
    long cnt;
} Input;

void increase(Input *input) {
    for (int i = 0; i < input -> cnt; i++) {
        incCounter(input->shared);
        // lock and unlock are embedded in shared counter
    }
}

int main(int argc, char* argv[]) {
    pthread_t tid1, tid2;
    int status;
    long cnt = atol(argv[1]);
    Input input = {makeCounter(), cnt};
    // pointer to counter, # of iterations we want

    status = pthread_create(&tid1, NULL, (void*(*)(void*))increase,(void*)&input);
    status = pthread_create(&tid2, NULL, (void*(*)(void*))increase,(void*)&input);

    void *v1, *v2;
    pthread_join(tid1, &v1);
    pthread_join(tid2, &v2);
    printf("Counter is %d\n", input.shared->_val);
    freeCounter(input.shared); // deallocate
    return 0;
}