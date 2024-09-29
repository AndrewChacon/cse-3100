/*
FORK FUNCTION

fork function execute in a parent process to create a child process

completely identical 
parent and child will return from the fork 
parent returns child identifier
child will return 0 to indicate child process

distinguish if it is child or parent

output
    In main: value = 5926 -> parent process
    In main: value = 0 -> child process

    process identifer was returned

what happens if we add 2 calls to fork?
    In main: value = 6226
    In main: value = 0
    In main: value = 6227 
    In main: value = 0

    2 calls to fork results in 4 child processes 
    a 3rd call adds another layer

parent will take actions based on child created
run concurrently and check back on child later
could wait till the child dies
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t value; // value as a pid
    value = fork(); // fork inside value 
    value = fork();
    printf("In main: value = %d\n", value);

    return 0;
}