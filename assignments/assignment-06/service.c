#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <errno.h>
#include <assert.h>

void checkError(int status,int line) {
   if (status < 0) {
      printf("socket error(%d)-%d: [%s]\n",getpid(),line,strerror(errno));
      exit(-1);
   }
}

int main(int argc, char* argv[]) {
   if (argc < 3) {
      printf("usage is: service <hostname> <port>\n");
      return 1;
   }

   char* hostname = argv[1];
   int sid = socket(PF_INET, SOCK_STREAM, 0);
   struct sockaddr_in srv;
   struct hostent *server = gethostbyname(hostname);
   srv.sin_family = AF_INET;
   srv.sin_port   = htons(atoi(argv[2]));
   memcpy(&srv.sin_addr.s_addr, server->h_addr, server->h_length);
   int status = connect(sid, (struct sockaddr*)&srv, sizeof(srv));
   checkError(status, __LINE__);

   char* terminateCommand = "$die!";
   int sent = send(sid, terminateCommand, strlen(terminateCommand), 0);
   checkError(sent, __LINE__);

   char buffer[1024];
   int received = recv(sid, buffer, sizeof(buffer) - 1, 0);
   checkError(received, __LINE__);
   buffer[received] = '\0';
   printf("%s", buffer);

   close(sid);

   return 0;
}

