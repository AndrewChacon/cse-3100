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
