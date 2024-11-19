mutexes are useful to create critical section
yield exclusive access to a resource
policing shared access

cannot communicate between threads to share information

why is it useful?? 
GUI refresh
    thread1 - computes result
    thread2 - display on UI when computation is done
real time processing
    thread1 - process realtime stream of data
            - produce summary
            - stores 1m summary in memory
    thread2 - consumes 1m stream to update DS
    