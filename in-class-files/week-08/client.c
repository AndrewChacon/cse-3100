#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/select.h>
#include <assert.h>

void checkError(int status,int line) {
   if (status < 0) {
      printf("socket error(%d)-%d: [%s]\n",getpid(),line,strerror(errno));
      exit(-1);
   }
}

/* Reads input till end of line from the socket */
char* readResponse(int fd) {
   int sz = 8;
   char* buf = malloc(sz);
   int ttl = 0,at = 0;
   int recvd;
   do {
      recvd = read(fd,buf+at,1);
      ttl += recvd;
      at  += recvd;
      if (recvd > 0 && ttl == sz) {
         buf = realloc(buf,sz*2);
         sz *= 2;
      }
      buf[ttl] = 0;
   } while (buf[ttl-1] != '\n' && recvd > 0);
   return buf;
}

int main(int argc,char* argv[]) {
   if (argc < 3) {
      printf("Usage is: client <hostname> <port>\n");
      return 1;
   }

   int p = atoi(argv[2]);   /* Port number for the server. This is the same as argv[1] in the server process */

   /* Specify the server address and connect with the server on port p */
   int sid = socket(PF_INET,SOCK_STREAM,0);
   struct sockaddr_in srv;
   struct hostent *server = gethostbyname(argv[1]);
   if (server==NULL) {
      printf("Couldn't find a host named: %s\n",argv[1]);
      return 2;
   }
   srv.sin_family = AF_INET;
   srv.sin_port   = htons(p);
   memcpy(&srv.sin_addr,server->h_addr_list[0],server->h_length);
   int status = connect(sid,(struct sockaddr*)&srv,sizeof(srv));
   checkError(status,__LINE__);

   fd_set afd; // set of file descriptors for selectapi    what is fdset, 
   size_t sz = 512; // size of the buffer 
   char* buf = malloc(sz); // allocating bugger 
   memset(buf,0,sz); // initalize the buffer with zeros 
   int done = 0; // status flag 
   do {
     FD_ZERO(&afd); // clear the fd set 
     FD_SET(STDIN_FILENO,&afd); // allowing standard in into fd set 
     FD_SET(sid,&afd); // adding socket descriptor into the set 
     int nbReady = select(sid+1,&afd,NULL,NULL,NULL); // want same data on the client and server
     if (nbReady > 0) {         // waiting for activity 
       if (FD_ISSET(STDIN_FILENO,&afd)) { // check to see if theres input from standard in 
	        int rc = getline(&buf,&sz,stdin); // get the input
           int wc = write(sid,buf,rc); // write it 
       } 
       // selection is about choosing what is sent 
       if (FD_ISSET(sid,&afd)) { // check if recieving message or not or input from a socket 
            char* line = readResponse(sid); // read response 
            int rc = strlen(line);
            strcpy(buf,line);
            free(line);
            done = rc == 0;
            if (!done) {
                int wc = write(STDOUT_FILENO,buf,rc); // write to terminal 
                assert(wc > 0);
            }
       }
       done |= strncmp(buf,"Bye!",4)==0;             
     } else done = 1;
   } while(!done);
   
   close(sid);
   return 0;
}

