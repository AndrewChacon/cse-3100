#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define READ_END 0      // defining pipe read point
#define WRITE_END 1     // defining pipe write point

int main() {
    int fd[2];  // 0 - stdin, 1 - stdout, 2 - stderr
    pipe(fd);   // initalize pipe

    // FIRST CHILD PROESS

    pid_t pid1 = fork(); // create 1st child process
    if(pid1 < 0) { // child should return 0 if successful
        perror("--Fork Failed---");
        return 1;
    }

    // we will write a message to the pipe
    if(pid1 == 0) { // check if we are in 1st child process
        close(fd[READ_END]); // read is unused so we close it
        write(fd[WRITE_END], "hello world\n", 12); // write message to pipe
        close(fd[WRITE_END]); // we close write after using it
        exit(0); // exit the 1st child process
    }



    // SECOND CHILD PROCESS

    pid_t pid2 = fork(); // create 2nd child process
    if(pid2 < 0) { // check if fork failed
        perror("--Fork Failed---");
        return 1;
    }

    if(pid2 == 0) { // check if we are in 2nd child process
        close(fd[WRITE_END]); // unused write, close write end
        dup2(fd[READ_END], STDIN_FILENO); // redirect read end of pipe to stdin 
        close(fd[READ_END]); // close read end after done with it
        execl("cat", "cat", (char *)NULL); // execute 'cat'
        perror("Execl Error"); // if execl fails - error handling
        exit(1); // if error - child exits with an error code
    }



    // PARENT PROCESS

    // close both ends of the pipe
    close(fd[READ_END]);
    close(fd[WRITE_END]);

    // wait for both child processes to finish
    wait(NULL);
    wait(NULL);

    return 0;

    /*
    The parent initalizes and creates a pipe
    1st child writes "hello world" to the pipe
    2nd child reads message from pipe and uses 'cat' to output it to the terminal
    The parent waits for both children processes to finish ensuring a clean exit 
    */
}

/*
write(arg1, arg2, arg3)
file descriptor of pipes write end
message to write in a string
size of message - must be manually set


*/


// can you explain the arguments for the execlp function
// using this as an example: ```execlp("cat", "cat", (char *)NULL);```

// can you explain when we would need to use dup vs dup2?

// also do u have example problems for pipes we can work on? 


/*
execlp is a family of functions that run command lines with files and arguments
execlp("cat", "cat", NULL);
the first arg is the name of the file/program "cat"
the second arg is the first argument to the program

execlp("cat", "cat", NULL);
1 - searches directory for program 'Cat'
1 - argument of cat program 'Cat'

this is the equvilant of typing cat into the shell followed by its input
cat "hello world" = execlp("cat", "cat", NULL);

execl replaces what the child process is doing


*/