/* Using MUTEXes to increment a global variable x to cnt concurrently in two threads
    *
    * Mutex is a lock. Stands for mutual exclusion.
    * We need one mutex per "thing" we wish to protect.
    * If a thread can acquire the lock, it can enter the critical section. Once it's complete it can unlock.
    * If a thread fails to acquire the lock, it will go to sleep and wake up once the lock is available.

    * Mutex APIs:
        * Initialize a mutex - int pthread_mutex_init(pthread_mutex_t * mutex, const pthread_mutexattr_t * attr);
            * init takes two arguments: the mutex and its attributes. Attributes define the kind of mutexes we can create.
                * NULL - create the default mutex
                * PTHREAD_MUTEX_NORMAL - does not detect a deadlock. This is the default.
                * PTHREAD_MUTEX_ERRORCHECK - provides error checking for scenarios like deadlock.
                * PTHREAD_MUTEX_RECURSIVE - useful for recursive function - to relock a mutex without first unlocking it. Unlock as many times as you lock.
                * PTHRED_MUTEX_DEFAULT - use the default of the operating system.
        * Lock a mutex - int pthread_mutex_lock(pthread_mutex_t * mutex);
        * Unlock a mutex - int pthread_mutex_unlock(pthread_mutex_t * mutex);
        * Destroy a mutex - int pthread_mutex_destroy(pthread_mutex_t * mutex);

    * Note: By default, mutexes are blocking!!!!
    * Try locking a mutex - int pthread_mutex_trylock(pthread_mutex_t *mutex);
        * if the mutex is not locked, it will succeed and lock
        * if the mutex is already locked, it will not block and return an error code.
        * if you use it, do not forget to check the return value of trylock!!!
    * Rule of thumb: Critical sections must be short to ensure low contention and, therefore, lesser context switching!
*/

/* Example 2: Incrementing a global variable x, protected by mutex m, to cnt concurrently in two threads.
   Compile using:  cc p2_mutex.c -lpthread -o p2 */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int x = 0;          // global variable to be shared by threads
pthread_mutex_t m;  // STEP 1: declare the mutex to protect access to x

void increase(int cnt) {
	int i;
	for(i=0;i<cnt;i++) {
		pthread_mutex_lock(&m);             //lock the mutex m
		x = x + 1;                          //critical section
		pthread_mutex_unlock(&m);           //unlock the mutex m
	}
}

int main(int argc, char* argv[]) {
	pthread_t tid1, tid2; 
	int status;
	long cnt = atol(argv[1]); 
	pthread_mutex_init(&m, NULL);       // STEP 2: initialize the mutex

	status = pthread_create(&tid1, NULL, (void * (*) (void *))increase, (void*)cnt); 
	status = pthread_create(&tid2, NULL, (void * (*) (void *))increase, (void*)cnt); 

	void *v1, *v2;
	pthread_join(tid1, &v1); 
	pthread_join(tid2, &v2); 
	
    pthread_mutex_destroy(&m);         // STEP 3: destroy the mutex
	
    printf("Counter is %d\n", x);
	
    return 0;
}

/* Install htop on your VM using: sudo yum install htop 
 * Run htop on cli to see the CPU usage
 */
