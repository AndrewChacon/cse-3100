#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

#define READ_END 0
#define WRITE_END 1
#define BUFFER_SIZE 20

void write_message(char* message, int fd) {
    int msgLength = strlen(message);
    for (int i = 0; i < msgLength; i++) {
        write(fd, &message[i], 1);
    }
}

char* read_message(int fd) {
    int bufferSize = BUFFER_SIZE; // buffer size
    char *buffer = (char *)malloc(sizeof(char) * bufferSize); // allocate memory for buffer 

    if (buffer == NULL) {
        return NULL; 
    }

    int bytes = 0;
    char c;

    while (read(fd, &c, 1) > 0) {
        if (bytes >= bufferSize - 1) {
            bufferSize += 1;
            buffer = (char*)realloc(buffer, bufferSize * sizeof(char));
        }
        buffer[bytes++] = c;
        if (c == '\n') break; 
    }

    buffer[bytes] = '\0';
    return buffer;
}

void customEncrypt(char* message) {
    for (int i = 0; i < strlen(message); i++) {
        if (message[i] == '\n') break;
        message[i] += 1;
    }
}

void decrypt(char* message) {
    for (int i = 0; i < strlen(message); i++) {
        if (message[i] == '\n') break;
        message[i] -= 1;
    }
}

int main() {
    int pipe1[2], pipe2[2], pipe3[2];

    if (pipe(pipe1) == -1) perror("Error creating pipe1");
    if (pipe(pipe2) == -1) perror("Error creating pipe2");
    if (pipe(pipe3) == -1) perror("Error creating pipe3");

    pid_t pid1 = fork();

    if (pid1 == 0) {
        char* msg;

        printf("Child 1 is Encrypting!\n");

        close(pipe1[WRITE_END]);
        close(pipe2[READ_END]);
        close(pipe3[READ_END]);
        close(pipe3[WRITE_END]);

        msg = read_message(pipe1[READ_END]);
        close(pipe1[READ_END]); 

        customEncrypt(msg);

        write_message(msg, pipe2[WRITE_END]);
        close(pipe2[WRITE_END]); 

        free(msg);
        exit(0); 
    } else {     
        pid_t pid2 = fork();
        if (pid2 == 0) { 
            close(pipe1[READ_END]);
            close(pipe1[WRITE_END]);
            close(pipe2[WRITE_END]);
            close(pipe3[READ_END]);

            char* msg = read_message(pipe2[READ_END]);
            close(pipe2[READ_END]); 

            printf("Child 2: %s", msg);

            write_message(msg, pipe3[WRITE_END]);
            close(pipe3[WRITE_END]); 

            free(msg); 
            exit(0); 
        } else { 
            close(pipe1[READ_END]);
            close(pipe2[READ_END]);
            close(pipe2[WRITE_END]);
            close(pipe3[WRITE_END]);

            char* msg = "This is a test.\n";
            printf("Parent: %s", msg);

            write_message(msg, pipe1[WRITE_END]);
            close(pipe1[WRITE_END]); 

            msg = read_message(pipe3[READ_END]);
            close(pipe3[READ_END]);

            decrypt(msg);
            printf("Parent: %s", msg);

            free(msg);
            wait(NULL);
            wait(NULL);
            return 0;
        } 
    }
}
