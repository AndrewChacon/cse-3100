API

pthread_cond_init - initalize condition 
pthread_cond_destroy - destroy condition

pthread_cond_wait - predicate is false
pthread_cond_signal - wakes up one waiting thread 
pthread_cond_broadcast - wakes up all waiting threads in condition, grabs the mutex one at a time

pthread_cond_timedwait

spurious wake up - thread wakes up for no reason
this is why checks are nessesary