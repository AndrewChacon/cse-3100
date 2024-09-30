#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

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
        for (int i = 0; i < 16; i++) {
            printf("fib(%2d) = %d\n", i*3, fib(i*3));
        }
    // 10 calls to sleep 
    } else {
        long begin = time(NULL);
        for (int i = 0; i < 10; i++) {
            sleep(1);
            printf("Elapsed time in parent %ld\n", time(NULL) - begin);
        }

        int exitStatus;
        pid_t deadChild = wait(&exitStatus);

        printf("Child %d died\n", deadChild);
        printf("Exited normally? [%s] with status %d\n", WIFEXITED(exitStatus) ? "yes" : "no", WEXITSTATUS(exitStatus));
    }

    return 0;
}

 