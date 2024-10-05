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
  /* TODO Q1.2: Create a buffer with initial size of BUFFER_SIZE. Read a character from fd into the buffer, until a new line character is reached. Expand the buffer as needed. 
   * The string must end with a new line character and a null character. */

  int bufferSize = BUFFER_SIZE; // buffer size
  char *buffer = (char *)malloc(sizeof(char)*bufferSize); // allocate memory for buffer 

  if(buffer == NULL) {
      return NULL; // check if buffer allocation failed
  }


  int bytes = 0;
  char currentCharacter;

  // while loop (1)
  // 
  while(1) {
    int result = read(fd, &currentCharacter, 1);
    if (result <= 0) break;

    if(bytes >= bufferSize) {
      bufferSize += 1;
      buffer = realloc(buffer, bufferSize);
    }

    buffer[bytes] = currentCharacter;
    bytes++;

    if(currentCharacter == '\n') {
      break;
    }
  }

  // read character one at a time from fd
  // expand buffer if needed
  // string must end with null terminator '\0'
  if(bytes >= bufferSize) {
      bufferSize += 1;
      buffer = realloc(buffer, bufferSize);
  }
  buffer[bytes] = '\0';
  return buffer;
}

void encrypt(char* message) {
  for(int i=0; i<strlen(message); i++) {
    if(message[i] == '\n') break;
    message[i] += 1;
  }
}

void decrypt(char* message) {
  for(int i=0; i<strlen(message); i++) {
    if(message[i] == '\n') break;
    message[i] -= 1;
  }
}

int main() {
  /* TODO Q2. Establish pipes for communication as directed in the pdf 
   * The parent process creates 2 child processes.
   * The parent process prints a string and sends it to child 1 via pipe.
   * Child 1 takes this message, encrypts it and send it to child 2 via pipe.
   * Child 2 takes the encrypted message, prints it, and sends it back to parent via pipe.
   * Parent takes the encrypted message, decrypts it and prints it on the stdout.
   
   * To do the above, you need to create pipes, fork child processes, redirect the input
   * and output of the processes to read and write end of pipes in a suitable manner.
   * Remember to always close ends of pipes that are not needed in a process.
   
   * Part of the functionality is implemented for you. Fill in the gaps listed with TODO.
   */
  
  /* TODO: Create pipes. Think carefully how many pipes you need. */
  int pipe1[2], pipe2[2], pipe3[2];

  pipe(pipe1);
  pipe(pipe2);
  pipe(pipe3); 

  if (pipe(pipe1) == -1) perror("Error creating pipe1");
  if (pipe(pipe2) == -1) perror("Error creating pipe2");
  if (pipe(pipe3) == -1) perror("Error creating pipe3");

  pid_t pid1 = fork();  

  if (pid1 == 0) {    /* Child 1 */
    char* msg;        /* Buffer to receive the message from parent */

    printf("Child 1 is Encrypting!\n");
    encrypt(msg);

    close(pipe1[WRITE_END]);
    close(pipe2[READ_END]);

    msg = read_message(pipe1[READ_END]);
    close(pipe1[READ_END]);

    encrypt(msg);

    write_message(msg, pipe2[WRITE_END]);
    close(pipe2[WRITE_END]);

    free(msg);
    exit(0);
  } else {          /* Parent process */
    pid_t pid2 = fork(); 
    if (pid2 ==0) { /* Child 2 */
      char* msg;    /* buffer to store the read message */
      /* TODO: Read the message from the pipe connecting child 1 to child 2. Close Unneeded Pipes. */
      close(pipe2[WRITE_END]);
      close(pipe3[READ_END]);

      msg = read_message(pipe2[READ_END]);
      close(pipe2[READ_END]);

      printf("Child 2: %s", msg);
      /* TODO: Write the message to the pipe connecting child 2 to Parent. Free the buffer. Close unneeded pipes. */
      write_message(msg, pipe3[WRITE_END]);
      free(msg);


      exit(0);
    } else {        /* Parent */

        close(pipe1[READ_END]);
        close(pipe3[WRITE_END]);
        char *msg = "This is a test.\n"; /* This is the plaintext message that the parent sends. */
        printf("Parent: %s", msg);

        write_message(msg, pipe1[WRITE_END]);
        close(pipe1[WRITE_END]);

        msg = read_message(pipe3[READ_END]);
        close(pipe3[READ_END]);

        decrypt(msg);
        printf("Parent: %s", msg);
        free(msg);
        return 0;
    } 
  }
}