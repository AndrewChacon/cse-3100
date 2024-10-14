#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

#define READEND 0
#define WRITEEND 1

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: pipes a b, where a and b are integers.\n");
        exit(1);
    }

    char range[10];
    snprintf(range, sizeof(range), "%s-%s", argv[1], argv[2]);

    int pipe1[2], pipe2[2];
    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        perror("pipe");
        exit(1);
    }

    pid_t pid1 = fork();
    if (pid1 == 0) {
        dup2(pipe1[WRITEEND], STDOUT_FILENO);
        close(pipe1[READEND]);
        close(pipe1[WRITEEND]);
        execlp("ls", "ls", "/dev", NULL);
        perror("execlp ls");
        exit(1);
    }

    pid_t pid2 = fork();
    if (pid2 == 0) {
        dup2(pipe1[READEND], STDIN_FILENO);
        dup2(pipe2[WRITEEND], STDOUT_FILENO);
        close(pipe1[READEND]);
        close(pipe1[WRITEEND]);
        close(pipe2[READEND]);
        close(pipe2[WRITEEND]);
        execlp("xargs", "xargs", NULL);
        perror("execlp xargs");
        exit(1);
    }

    pid_t pid3 = fork();
    if (pid3 == 0) {
        dup2(pipe2[READEND], STDIN_FILENO);
        close(pipe1[READEND]);
        close(pipe1[WRITEEND]);
        close(pipe2[READEND]);
        close(pipe2[WRITEEND]);
        execlp("cut", "cut", "-d", " ", "-f", range, NULL);
        perror("execlp cut");
        exit(1);
    }

    close(pipe1[READEND]);
    close(pipe1[WRITEEND]);
    close(pipe2[READEND]);
    close(pipe2[WRITEEND]);

    wait(NULL);
    wait(NULL);
    wait(NULL);

    return 0;
}
