/*
PROCESS UPGRADES
fresh clone wants to run different code
child kills itself, discards code in its AS
reloads process AS with another executable
opened files are not affected by this operation

#include <unistd.h>

extern char **environ;
int execl(const char *path, const char *arg0, ...)

enviornment variable exec L system call 

call takes as an input, the path of exec to replace content
if successful execl does not return

a parent program will
call fork and check for fork

if fork
    runs adder 1,2,3,10
else
    runs adder 100,200,300

*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int i, value, sum = 0;
    for (i = 1; i < argc; i++) {
        sum += atoi(argv[i]);
    }
    printf("Sum is: %d\n", sum);
    return 0;
}

