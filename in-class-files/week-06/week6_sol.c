/* Using pipes to set up bi-directional communication. 
 * The parent process reads a file from disk, stores it in a buffer and sends it to the child.
 * The child process computes md5sum of the file and sends it to the parent.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define READ_END 0
#define WRITE_END 1

char* md5sum(char* payload, size_t sz);

char* readFile(char* fName, long* sz) {
   FILE* src = fopen(fName,"r");
   fseek(src,0,SEEK_END);
   *sz = ftell(src);
   fseek(src,0,SEEK_SET);
   char* payload = malloc(sizeof(char) * *sz);
   fread(payload,sizeof(char),*sz,src);
   fclose(src);
   return payload;
}

int main(int argc,char* argv[]) {
   long sz = 0;
   char* payload = readFile(argv[1], &sz); //read file from the disk. Return the buffer and store the file size in sz
   char* rv = md5sum(payload, sz);         //compute md5sum of the payload
   printf("Got md5 [%s]\n",rv);
   free(rv);
   return 0;
}

void sendPayload(int fd,char* payload,size_t sz) {
   int sent=0, rem = sz;
   while(sent != sz) {
      int nbSent = write(fd, payload+sent, rem);
      sent += nbSent;
      rem  -= nbSent;
   }
}

char* readResponse(int fd) {
   int sz = 8;
   char* buf = (char*)malloc(sz);
   int ttl = 0, at = 0;
   int recvd;
   do {
      recvd = read(fd, buf+at, sz-at);
      ttl += recvd;
      at  += recvd;
      if (recvd > 0 && ttl == sz) {
         buf = realloc(buf,sz*2);
         sz *= 2;
      }
   } while (recvd > 0);
   char* final = (char*)malloc(ttl+1);
   memcpy(final, buf, ttl);
   final[ttl] = 0;
   free(buf);
   return final;
}

char* md5sum(char* payload, size_t sz) {
    /* Set up pipes for bi-directional communication between the parent and child.
     * The child process executes /usr/bin/md5sum on the input from the pipe and writes the output to a pipe. 
     * The parent process calls sendPayload to send the file via a pipe and readResponse to read from a fd.
     * The parent waits for the child to die first. */
    int pc[2], cp[2];
    
    if (pipe(pc) == -1 || pipe(cp) == -1) {
        perror("Failed to create pipes");
        exit(EXIT_FAILURE);
    }

    pid_t val = fork();

    if (val == 0) {
        // Child process
        close(pc[WRITE_END]);   // Close unused write end of parent-to-child pipe
        close(cp[READ_END]);    // Close unused read end of child-to-parent pipe
        
        // Redirect stdin to the read end of pc
        dup2(pc[READ_END], 0);
        close(pc[READ_END]);

        // Redirect stdout to the write end of cp
        dup2(cp[WRITE_END], 1);
        close(cp[WRITE_END]);

        execl("/usr/bin/md5sum", "md5sum", NULL);
        perror("execl failed");
        exit(EXIT_FAILURE);
    } 
    else if (val > 0) {
        // Parent process
        close(pc[READ_END]);   // Close unused read end of parent-to-child pipe
        close(cp[WRITE_END]);  // Close unused write end of child-to-parent pipe

        sendPayload(pc[WRITE_END], payload, sz);  // Send file content through pipe
        close(pc[WRITE_END]);  // Close write end after sending

        char* rv = readResponse(cp[READ_END]);  // Read response (md5sum result)
        close(cp[READ_END]);   // Close read end

        int status;
        waitpid(val, &status, 0);  // Wait for the child to finish
        return rv;
    } 
    else {
        // Fork failed
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
}
