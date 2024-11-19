lock then unlock, the critical section
pthread_mutex_trylock
if mutex is not locked, behavior is like locking
if mutex is locked, error status is returned

mutex attributes - depends on the kind of mutex u want
pthread_mutex_normal - doesnt detect deadlock
pthread_mutex_errorcheck - provides error checking
thread_mutex_recursive - attempting to relock mutex without first unlocking, it will succeed in locking the mutex, multiple locks require same number of unlocks to release the mutex. 5 locks require 5 unlocks
pthread_mutext default - default of the OS to lock
