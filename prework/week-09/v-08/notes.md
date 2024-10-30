objective
we have var x and we want to protect it when we use threads to work on the data
make sure x is the correct result in the end
x exists in memory, we wish to protect memory

IDEA 1
    put x in a mini prison 
    if thread 1 wishes to increment x
    take x out of prision
    increment x
    put x back
    if thread2 wishes to increment x
    thread2 must wait for x to be back in its cell
    does this work?
    conceptually yes, practially no



IDEA 2
    enforce a protocol on code that wishes to use x 
    the code must obey these protocols
    if thread wishes to increment x
    thread will grab a specific lock 
    thread increases x 
    thread releases the lock 
    if it does not have the lock it must wait 
    if its locked the thread goes to sleep 
    thread must always promise to unlock the lock 
    on unlock the thread wakes up 