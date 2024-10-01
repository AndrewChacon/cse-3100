#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define READ_END 0
#define WRITE_END 1

int main() {
    int fd[2];
    pipe(fd); // Create the pipe

    pid_t pid1 = fork(); // Create the first child process
    if (pid1 < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid1 == 0) {
        // First child process: write "hello world" to the pipe
        close(fd[READ_END]); // Close unused read end
        write(fd[WRITE_END], "hello world\n", 12); // Write message to pipe
        close(fd[WRITE_END]); // Close write end after writing
        exit(0); // Exit child process
    }

    pid_t pid2 = fork(); // Create the second child process
    if (pid2 < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid2 == 0) {
        // Second child process: read from the pipe and execute `cat`
        close(fd[WRITE_END]); // Close unused write end
        dup2(fd[READ_END], STDIN_FILENO); // Redirect pipe read end to stdin
        close(fd[READ_END]); // Close original read end
        execlp("cat", "cat", (char *)NULL); // Execute `cat`
        perror("execlp failed"); // Handle execlp failure
        exit(1);
    }

    // Parent process
    close(fd[READ_END]); // Close both ends of the pipe
    close(fd[WRITE_END]); // Close both ends of the pipe

    // Wait for both child processes to finish
    wait(NULL);
    wait(NULL);

    return 0;
}