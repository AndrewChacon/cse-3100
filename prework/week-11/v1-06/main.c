#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int shared_data = 0;
int data_ready = 0;

pthread_mutex_t mutex;
pthread_cond_t cond;

void* producer(void*arg) {
    for (int i = 1; i <= 5; i++) {
        pthread_mutex_lock(&mutex);
        shared_data = i;
        data_ready = 1;

        printf("Producer: produced data %d\n", shared_data);

        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    return NULL;
}

void* consumer(void* arg) {
    for (int i = 1; i <= 5; i++) {
        pthread_mutex_lock(&mutex);

        while(!data_ready) {
            pthread_cond_wait(&cond, &mutex);
        }

        printf("Consumer: Consumed data %d\n", shared_data);
        data_ready = 0;

        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_t producer_thread, consumer_thread;
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, producer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}
