#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>
#include "guess-mt.h"

typedef struct thread_arg_tag {
    gmn_t* sb; // shared buffer for talking between thread c and p 
    /* TODO 
     * Add mutexes and condition variables required
    */
    pthread_mutex_t lock; // setting up the var for our mutex
    pthread_cond_t parent_ready; // singal variable to parent
    pthread_cond_t child_ready; // signal variable to child 
} thread_arg_t;

// function defs for thread c and thread p
void *thread_c(void* consumer_thread_data);
void *thread_p(void* producer_thread_data);

int main(int argc,char* argv[])
{
    
    /* TODO
     * Create an instance of thread_arg_t and initialize it. The value to be guessed is taken as input from the command line arguments.
     * Create two threads - one each for the parent and child
     * Join the threads and reap the resources (destroy the mutexes and condition variables used).
    */

    // take in argv[1] which is our input
    int input = atoi(argv[1]);
    // initalize shared buffer with our input (argv[1])
    gmn_t *shared_buffer = gmn_init(input);
    thread_arg_t thread_args = {
        // fields we created in gmn_t structure
        .sb = shared_buffer,
        .lock = PTHREAD_COND_INITIALIZER,
        .parent_ready = PTHREAD_COND_INITIALIZER,
        .child_ready = PTHREAD_COND_INITIALIZER,
    };
    // initalize both of our threads
    pthread_t parent_tid, child_tid;
    // we are actually creating thread 1 and 2 so they can be used to do work 
    pthread_create(&parent_tid, NULL, thread_p, &thread_args);
    pthread_create(&child_tid, NULL, thread_c, &thread_args);
    // wait for thread 1 and thread 2 to finish their jobs
    pthread_join(parent_tid, NULL); // NULL no value needs to be returned for the threads
    pthread_join(child_tid, NULL);
    // mutex and conditions must be destroyed once the jobs is finished
    pthread_mutex_destroy(&thread_args.lock);
    pthread_cond_destroy(&thread_args.parent_ready);
    pthread_cond_destroy(&thread_args.child_ready);
    // shared buffer must be freed in the end
    free(shared_buffer);

    return 0;
}

void* thread_p(void *producer_thread_data) {
   /* TODO
    * This is a parent thread.
    * repeat the following until guess is correct
        guess a number between min and max. initially max is set to MAX_VALUE
        send the guess to the child and wait for a result (thread_c)
        if result is 0 i.e. you guessed the number correctly, end the thread
        if result is -1 or 1, update the search interval and make a guess
   */
   thread_arg_t *args = (thread_arg_t *)producer_thread_data;
   // vars we need for checking the conditions of our guess
   int low = 1;
   int high = MAX_VALUE;
   int guess;

   while(1) {
       pthread_mutex_lock(&args->lock); // we might update data so we should lock the mutex
       guess = (low + high) / 2;
       args->sb->guess = guess;
       args->sb->status = 1;
       printf("My guess is %d.\n", guess);
       // were gonna let the child know theres a new guess that was just made
       pthread_cond_signal(&args->child_ready);
       while(args->sb->status == 1) { // waiting for the child to finish its job on our guess
           pthread_cond_wait(&args->parent_ready, &args->lock);
       }

       // this is where we check if the guess is high or low, then adjust
       if(args->sb->result == 0) {
           printf("Parent: %s", args->sb->message); // if the guess was correct we just spit it out to the output
           pthread_mutex_unlock(&args->lock);
           break;
        // condition if our guess is too small, increase the low 
       } else if(args->sb->result == -1) {
            printf("Parent: %s", args->sb->message);
            low = guess + 1;
       } else {
        // condition if the guess is too large we decrease the high 
        printf("Parent: %s", args->sb->message);
            high = guess - 1;
       }
        // after its all done we can unlock it
       pthread_mutex_unlock(&args->lock);
   }

   return NULL;
}

void* thread_c(void * consumer_thread_data)

{
    /* TODO
     * This is a child thread.
     * repeat the following until guess is correct 
     *      wait for a guess from the parent (thread_p) 
     *      call gmn_check() to compare the guess with the user input value
     *      send the result to thread_p
     */
    thread_arg_t *args = (thread_arg_t *)consumer_thread_data;
    while(1) {
        // we gotta change data so we need to lock
        pthread_mutex_lock(&args->lock);
        // wait for the parent to send its next guess over
        while(args->sb->status == 0) {
            pthread_cond_wait(&args->child_ready, &args->lock);
        }
        // update the shared data from our guess
        args->sb->result = gmn_check(args->sb);

        // we must set the status to 0 and signal this to the parent
        args->sb->status = 0;
        pthread_cond_signal(&args->parent_ready); // tell parent to wake up and work again

        if (args->sb->result == 0) {
            pthread_mutex_unlock(&args->lock); // if result is 0 break out of the loop
            break;
        }
        pthread_mutex_unlock(&args->lock);
    }

    return NULL;
}