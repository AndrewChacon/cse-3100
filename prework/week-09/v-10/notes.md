basic apis for threads
link with threading library -lpthread

THREAD CREATION
#include <pthread.h>
int pthread_create()

pthread_t indentifier of thread

thread termination
thread coordination 

you have no control over scheduling
thread starts right away inside entry point function
threads can exist in two states, joinable or detatched