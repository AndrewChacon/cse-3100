#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int x = 0;

void increase(int cnt) {
    int i;
    for (int i = 0; i < cnt; i++) {
        x = x + 1;
    }
}

int main(int argc, char* argv[]) {
    pthread_t tid1, tid2;
    int status;
    long cnt = atol(argv[1]);
    status = pthread_create(&tid1, NULL, (void *(*)(void *))increase, (void *)cnt);
    status = pthread_create(&tid2, NULL, (void *(*)(void *))increase, (void *)cnt);

    void *v1, *v2;
    pthread_join(tid1, &v1);
    pthread_join(tid2, &v2);
    printf("Counter is %d\n", x);

    return 0;
}

/*
cc thread.c -lpthread -o thread
./thread 1000  
    Result: 2000

./thread 10000000                                                             
Counter is 12275856        this is an error

the two threads are executing and time sharing, things are not being scheduled


*/