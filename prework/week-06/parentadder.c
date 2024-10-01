#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main() {
    pid_t child = fork();
    if(child == 0) {
        printf("In child\n");
        execl("./adder", "./adder", "1", "2", "3", "10", NULL);
        printf("Oops...something went wrong. Shouldnt be here\n");
        char *msg = strerror(errno);
        printf("Error was %s\n", msg);
        return -1;
    }
    else {
        printf("In parent\n");
        execl("./adder", "./adder", "100", "200", "300", NULL);
        printf("Oops...something went wrong. Shouldnt be here\n");
        char *msg = strerror(errno);
        printf("Error was %s\n", msg);
        return -1;
    }
}


/*
In parent
In child
Sum is: 600
Sum is: 16

In parent
In child
Sum is: 16
Sum is: 600

no guarante in which the order of parent and child will finish running

child inherited the standard output from its parent
*/