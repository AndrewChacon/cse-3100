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
main function takes in as an arg the # of interations we need
converts it to a long and stores it in cnt

creates a thread - tid1 and tid2 hold the name of the thread, the identifier 

(void *(*)(void *)
pthread expects as an argument, a function that takes a pointer to a void and returns a pointer to a void

v1 v2 pick up results of the thread after they terminate 
pthread_join - wait for end of exec of the thread
*/