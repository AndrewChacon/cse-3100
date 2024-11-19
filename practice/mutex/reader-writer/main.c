#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// controlling access to shared resource 
pthread_mutex_t resource_mtx = PTHREAD_MUTEX_INITIALIZER;
// controlling access to reader counter
pthread_mutex_t reader_count_mtx = PTHREAD_MUTEX_INITIALIZER;

// global variables 
int reader_count = 0; // # of active readers
int shared_resource = 0; // shared resource

void* reader(void*arg) {
    int id = *(int *)arg;

    // reader enters
    pthread_mutex_lock(&reader_count_mtx); // lock reader_count
    reader_count++;
    if(reader_count == 1) {
        pthread_mutex_lock(&resource_mtx); // first reader locks shared resource 
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
    pthread_mutex_unlock(&reader_count_mtx); // unlocks after reader count is updated 
    free(arg); // frees memory allocated for id 
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

    free(arg); // frees memory allocated for id
    return NULL;
}

int main(int argc, char* argv[]) {
    pthread_t readers[5], writers[2]; // stores thread ids for reader and writer threads 

    // create reader threads 
    for (int i = 0; i < 5; i++) {
        int *id = malloc(sizeof(int));
        *id = i + 1;
        pthread_create(&readers[i], NULL, reader, id); // creates reader thread 
    }

    // create writer threads
    for (int i = 0; i < 2; i++) {
        int *id = malloc(sizeof(int));
        *id = i + 1;
        pthread_create(&writers[i], NULL, writer, id); //creates writer thread 
    }

    // wait for all reader threads to finish
    for (int i = 0; i < 5; i++) {
        pthread_join(readers[i], NULL);
    }

    // wait for all writer threads to finish
    for (int i = 0; i < 2; i++) {
        pthread_join(writers[i], NULL);
    }

    return 0;
}