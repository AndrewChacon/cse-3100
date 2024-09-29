/*
PROCESS CONCURRENCY

value is 0 if child, non 0 if parent
child compute fib number
else parent process

the parent process dies
the child is still running
prints fib 45 last after parent died

child lives on until it dies
parent dies - child is adopted by init process
init process adopts orphaned process till it dies

api to stop parent from dying

#include <sys/wait.h>
pid_t wait(int *stat_loc);
pid_t waitpid(pid_t pid, int *stat_loc, int options)

parent waits on death of the child
reaping - responsibility of the parent
child process usually dies before parent

reaping
parent is alive - parent attends to dead processes
when parent is dead - two possibilites:
    - child is adopted by ancestor process
      default is adopted by init
    - children all die in solidarity
      children are murdered by dying parent
      API - kill(pid_t pid, int sig);


loop over all children processes and kill them
do nothing - init adopts them
become a sub reaper - prctl(PR_SET_CHILD_SUBREAPER, 1);



*/

#include <stdio.h>
#include <unistd.h>
#include <time.h>

int fib(int n) {
    if(n <= 1) {
        return n;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}

int main() {
    pid_t value = fork();
    int i;
    // 30 calls to fib
    if(value == 0) { // process is child
        for (int i = 0; i < 30; i++) {
            printf("fib(%2d) = %d\n", i*5, fib(i*5));
        }
    // 10 calls to sleep 
    } else {
        long begin = time(NULL);
        for (int i = 0; i < 10; i++) {
            sleep(1);
            printf("Elapsed time in parent %ld\n", time(NULL) - begin);
        }
    }
    return 0;
}