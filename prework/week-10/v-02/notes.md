mutex api 
initalize the mutex
destroy mutex after its done

lock a mutex 
unlock a mutext

attempt to lock a mutex

#include <pthread.h>

init pthread_mutex_init -> create mutext

allocates OS resource for the lock

creation 
initalize data 
initalize mutex and provide is address space
return data value

destruction
destory mutex after its done being used

pthread_mutex_destory

pthread_mutex_lock
pthread_mutex_unlock
how to protect data being modified in a code block
if u lock u better unlock

one mutex for each thing u want to protect
a lock and unlock for each data value being modified 
lock is blocking other processes running
critical sections should be short, cuz of locking 
locking is an expensive process 