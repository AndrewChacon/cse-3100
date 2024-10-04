#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define FD_READ 0
#define FD_WRITE 1

int main() {
    int fd[2];
    pipe(fd);

    return 0;
}