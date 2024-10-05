#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

#define READ_END 0
#define WRITE_END 1

#define BUFFER_SIZE 20

// Function to write a message character-by-character to the pipe
void write_message(char* message, int fd) {
    for (int i = 0; message[i] != '\0'; i++) {
        write(fd, &message[i], 1);
    }
}

// Function to read a message from a pipe until a newline character is encountered
char* read_message(int fd) {
    int buffer_size = BUFFER_SIZE; // Initial buffer size
    char* buffer = (char*)malloc(buffer_size * sizeof(char));
    int index = 0;

    char c;
    while (read(fd, &c, 1) > 0) { // Read character-by-character from the pipe
        // Expand the buffer if necessary
        if (index >= buffer_size - 1) {
            buffer_size *= 2;
            buffer = (char*)realloc(buffer, buffer_size * sizeof(char));
        }
        buffer[index++] = c;
        if (c == '\n') break; // Stop reading at the newline character
    }
    buffer[index] = '\0'; // Null-terminate the string
    return buffer;
}

// Function to encrypt the message by incrementing each character by 1
void customEncrypt(char* message) {
    for (int i = 0; i < strlen(message); i++) {
        if (message[i] == '\n') break;
        message[i] += 1;
    }
}

// Function to decrypt the message by decrementing each character by 1
void decrypt(char* message) {
    for (int i = 0; i < strlen(message); i++) {
        if (message[i] == '\n') break;
        message[i] -= 1;
    }
}

int main() {
    int pipe1[2], pipe2[2], pipe3[2];

    // Create three pipes for communication between parent and children
    if (pipe(pipe1) == -1 || pipe(pipe2) == -1 || pipe(pipe3) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t pid1 = fork(); // Create the first child process
    if (pid1 == 0) {
        /* Child 1 */
        // Close unnecessary pipe ends for this child
        close(pipe1[WRITE_END]);
        close(pipe2[READ_END]);
        close(pipe3[READ_END]);
        close(pipe3[WRITE_END]);

        // Read message from parent through pipe1
        char* msg = read_message(pipe1[READ_END]);
        close(pipe1[READ_END]); // Close read end after reading

        printf("Child 1 is Encrypting!\n");
        // Encrypt the message
        customEncrypt(msg);

        // Write encrypted message to pipe2 to send to Child 2
        write_message(msg, pipe2[WRITE_END]);
        close(pipe2[WRITE_END]); // Close write end after writing

        free(msg); // Free the allocated memory for the message
        exit(0); // Exit Child 1
    } else {
        pid_t pid2 = fork(); // Create the second child process
        if (pid2 == 0) {
            /* Child 2 */
            // Close unnecessary pipe ends for this child
            close(pipe1[READ_END]);
            close(pipe1[WRITE_END]);
            close(pipe2[WRITE_END]);
            close(pipe3[READ_END]);

            // Read encrypted message from Child 1 through pipe2
            char* msg = read_message(pipe2[READ_END]);
            close(pipe2[READ_END]); // Close read end after reading

            // Print the received (encrypted) message
            printf("Child 2: %s", msg);

            // Write encrypted message to pipe3 to send back to Parent
            write_message(msg, pipe3[WRITE_END]);
            close(pipe3[WRITE_END]); // Close write end after writing

            free(msg); // Free the allocated memory for the message
            exit(0); // Exit Child 2
        } else {
            /* Parent */
            // Close unnecessary pipe ends for the parent
            close(pipe1[READ_END]);
            close(pipe2[READ_END]);
            close(pipe2[WRITE_END]);
            close(pipe3[WRITE_END]);

            // Parent message to be sent to Child 1
            char* msg = "This is a test.\n";
            printf("Parent: %s", msg);

            // Write the plaintext message to Child 1 through pipe1
            write_message(msg, pipe1[WRITE_END]);
            close(pipe1[WRITE_END]); // Close write end after writing

            // Read encrypted message from Child 2 through pipe3
            msg = read_message(pipe3[READ_END]);
            close(pipe3[READ_END]); // Close read end after reading

            // Decrypt the message
            decrypt(msg);
            // Print the decrypted message
            printf("Parent: %s", msg);

            free(msg); // Free the allocated memory for the message

            // Wait for both child processes to finish
            wait(NULL);
            wait(NULL);

            return 0; // Exit the Parent process
        }
    }
}
