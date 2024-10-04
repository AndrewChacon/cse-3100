// need two pipes - bidirectional comms
/*
    output:
    ./a.out file.text
    dead children: #
    prints file hash
*/

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


/* Set up pipes for bi-directional communication between the parent and child.
    * The child process executes /usr/bin/md5sum on the input from the pipe and writes the output to a pipe. 
    * The parent process calls sendPayload to send the file via a pipe and readResponse to read from a fd.
    * The parent waits for the child to die first. */
   
char* md5sum(char* payload,size_t sz) {
   int pid;
   int fd1[2];
   int fd2[2];

   pipe(fd1);
   pipe(fd2);

   pid = fork();

   if(pid < 0) {
       perror("Error: did not fork properly");
   }

   if(pid == 0) { // in child process
        // read pay load
        close(fd1[WRITE_END]);
        close(fd2[READ_END]);
        read(fd1[READ_END], payload, sizeof(size_t));
        write(fd1[READ_END], payload, sizeof(size_t));

        close(fd1[READ_END]);
        close(fd2[WRITE_END]);
        printf("Child process is finished");
        exit(0);
   }
   else
   { // in parent process
       // write payload
       close(fd1[READ_END]);
       close(fd2[WRITE_END]);
   }

   wait(NULL);
   wait(NULL);
}
