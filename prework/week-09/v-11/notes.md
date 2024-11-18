thread termination
basics self termination execution

event when thread returns from entry
the thread ends

call exit to terminate process early
terminate threads early with pthread_exit(covid \*retval)

process can kill another process with kill function
thread can terminate another thread with pthread_kill(thread, sig)

Thread lifetime coordination - joining
joinable when the thread dies, returns value of entry point
another thread can join to pick up the value
resource is reclaimed when join completes

