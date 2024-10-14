#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s cmd1 cmd1_arg cmd2 [cmd2_args ..]\n", argv[0]);
        return 1;
    }

    int status;
    pid_t pid1, pid2;

    pid1 = fork();
    if (pid1 == -1) {
        perror("fork");
        return 1;
    } else if (pid1 == 0) {
        execlp(argv[1], argv[1], argv[2], NULL);
        perror("execlp"); 
        exit(1);
    }


    waitpid(pid1, &status, 0);
    printf("exited=%d exitstatus=%d\n", WIFEXITED(status), WEXITSTATUS(status));


    pid2 = fork();
    if (pid2 == -1) {
        perror("fork");
        return 1;
    } else if (pid2 == 0) {

        execvp(argv[3], &argv[3]);
        perror("execvp");  
        exit(1);
    }

    waitpid(pid2, &status, 0);
    printf("exited=%d exitstatus=%d\n", WIFEXITED(status), WEXITSTATUS(status));

    return 0;
}
