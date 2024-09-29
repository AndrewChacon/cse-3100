/*
SYSTEMS PROGRAMMING 

Process Life Cycle
    - Fork, Wait, Exec, File Handles
Pipes
FIFO

code + processor state + memory + resource usage
everything organized as a tree
init - root of the process tree
init has children
all other processes are children of the init
every process has 0 or children

process life cycle
birth
    - starts as clone of its parent process
    - upgrades itself to run different executable
    - process retains access to the files open by parent
life
    - process can create children processes
death
    - exit or abort to terminate process

birth via cloning

    #include <unistd.h>
    pid_t fork(void);

child is exact copy of the parent

in parent process fork returns the process identifer of the child, if fails return -1

in child process fork returns 0

cloning effect on resources
virtually indistinguishable
all memory is 100% identical

parent and clone and quickly diverge on any changes

the parent and child both return from fork
running concurrently
both can run at the same time - multicore machine


*/

#include <stdio.h>

int main() {
    return 0;
}