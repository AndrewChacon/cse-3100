what we learned 
create threads, die as a thread, wait on a thread joining
carry out independent computations with threads

mutual exclusion
protect shared memory
you cant truly protect it only police the code that is accessing the memory
protocol - enforce access discipline among threads


thread 1 
i wanna use var x 
do something to var x     |
continue it               |-- critical section 
almost done now           |
im done with var x 

thread 2 
id like to use var x
sleep time
wake up
do something with var x 
im done with var x 

ask permission for the critical section

two threads 
race each other to get to critical section
one of the wins the race 
winner
    - gets the lock first
    - executes ciritcal section 
    - gets rid of the lock
loser
    - waits as lock is taken
    - wakes up when lock is available
    - executes critical section
    - gets rid of the lock 

theres a lock on the block of the code that is the critical section
all activity in between the lock init and destruction, the specified data is modified

the lock is a POSIX abstraction
mutex or mutual exclusion
