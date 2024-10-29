what about forking??
its small fat
forking a process operation, clones the process

what about threads in the parent process?
only the thread calling fork is cloned
the other threads are not cloned in the process
the other threads are unaffected in the parent process

any thread can call fork on the main thread
the only thread that survives is the one who called the fork process
the other threads arent carried over into the child process

virtual address space
the stack is at the top and grows down into the address space
the queue starts from the bottom and grows upward into the address space

each thread gets a stack
stack have a maximal size
keep stacks seperated to avoid accidental overlap

each thread gets its own stack with a fixed size
these stacks are not consecutive in case they need to grow
pretty spaced out inside the address space 

32 bit OP everything is very tight
100 threads per process is not a lot
kernal has 367 threads within
dropbox has 144 threads

circumventing the limit on 32bit machines
make smaller stacks (careful when using recursion)
seperate tasks in seeveral process that
    - comms with pipes
    - comms with shared virtual memory

64 bit 2^24 threads inside an address space (8 million)

