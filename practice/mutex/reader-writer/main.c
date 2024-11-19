#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t resource_mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t reader_count_mtx = PTHREAD_MUTEX_INITIALIZER;
// mutex for shared rsource and reader count

int reader_count = 0; // # of active readers
int shared_resource = 0; // shared resource

void* reader(void*arg) {
    int id = *(int *)arg;

    // reader enters
    pthread_mutex_lock(&reader_count_mtx); // lock reader_count
    reader_count++;
    if(reader_count == 1) {
        pthread_mutex_lock(&resource_mtx); // lock first reader
    }
    pthread_mutex_unlock(&reader_count_mtx); // unlock reader count

    // reading the shared resource
    printf("Reader %d: reading shared_resource = %d\n", id, shared_resource);
    usleep(1000000); // simulates reading

    // reader exits
    pthread_mutex_lock(&reader_count_mtx);
    reader_count--;
    if(reader_count == 0) { // last reader unlocks the resource 
        pthread_mutex_unlock(&resource_mtx);
    }
    pthread_mutex_unlock(&reader_count_mtx);
    free(arg);
    return NULL;
}

void* writer(void* arg) {
    int id = *(int *)arg;

    //writer enters
    pthread_mutex_lock(&resource_mtx); // lock shared resource

    //writing to the shared resource
    shared_resource += 10;
    printf("Writer %d: updated shared_resource to %d\n", id, shared_resource);
    usleep(150000); // simulate writing

    // writer exits
    pthread_mutex_unlock(&resource_mtx); // unlock shared resource

    free(arg);
    return NULL;
}

int main(int argc, char* argv[]) {
    pthread_t readers[5], writers[2];

    //create reader and writer threads
    for (int i = 0; i < 5; i++) {
        int *id = malloc(sizeof(int));
        *id = i + 1;
        pthread_create(&readers[i], NULL, reader, id);
    }

    for (int i = 0; i < 2; i++) {
        int *id = malloc(sizeof(int));
        *id = i + 1;
        pthread_create(&writers[i], NULL, writer, id);
    }

    // wait for threads to finish
    for (int i = 0; i < 5; i++) {
        pthread_join(readers[i], NULL);
    }

    for (int i = 0; i < 2; i++) {
        pthread_join(writers[i], NULL);
    }

    return 0;
}