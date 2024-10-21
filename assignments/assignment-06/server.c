#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <dirent.h>

/* prints the error that is encountered and terminate the program */
void checkError(int status,int line) {
   if (status < 0) {
      printf("socket error(%d)-%d: [%s]\n",getpid(),line,strerror(errno));
      exit(-1);
   }
}

/* creates a server-side socket that binds to the given port number and listens for TCP connect requests */
int bindAndListen(int port) {
   int sid = socket(PF_INET,SOCK_STREAM,0);
   struct sockaddr_in addr;
   addr.sin_family = AF_INET;
   addr.sin_port   = htons(port);
   addr.sin_addr.s_addr = INADDR_ANY;
   int status = bind(sid,(struct sockaddr*)&addr,sizeof(addr));
   checkError(status,__LINE__);
   status = listen(sid,10);
   checkError(status,__LINE__);
   return sid;
}

/* reaps dead children */
void cleanupDeadChildren() {
   int status = 0;
   pid_t deadChild; // reap the dead children
   do {
      deadChild = waitpid(0,&status,WNOHANG);
   } while (deadChild > 0);
}

int main(int argc, char* argv[]) {
   if (argc < 3) {
      printf("usage is: server <port1> <port2>\n");
      return 1;
   }

   int sid = bindAndListen(atoi(argv[1]));
   int srv = bindAndListen(atoi(argv[2]));

   fd_set readfds;
   int maxfd = (sid > srv) ? sid : srv;
   char buffer[8192];

   while (1) {
      FD_ZERO(&readfds);
      FD_SET(sid, &readfds);
      FD_SET(srv, &readfds); 

      int activity = select(maxfd + 1, &readfds, NULL, NULL, NULL);
      checkError(activity, __LINE__);

      if (FD_ISSET(sid, &readfds)) {
         struct sockaddr_in clientAddr;
         socklen_t clientLen = sizeof(clientAddr);
         int clientSock = accept(sid, (struct sockaddr*)&clientAddr, &clientLen);
         checkError(clientSock, __LINE__);

         int pid = fork();
         checkError(pid, __LINE__);

         if (pid == 0) {
            close(sid);
            close(srv);

            dup2(clientSock, STDIN_FILENO);
            dup2(clientSock, STDOUT_FILENO);
            dup2(clientSock, STDERR_FILENO);

            execlp("sqlite3", "sqlite3", "foobar.db", (char *)NULL);

            perror("Failed to execute sqlite3");
            close(clientSock);
            exit(1);
         } else {
            close(clientSock);
            cleanupDeadChildren();
         }
      }

      if (FD_ISSET(srv, &readfds)) {
         struct sockaddr_in clientAddr;
         socklen_t clientLen = sizeof(clientAddr);
         int clientSock = accept(srv, (struct sockaddr*)&clientAddr, &clientLen);
         checkError(clientSock, __LINE__);

         int received = recv(clientSock, buffer, sizeof(buffer) - 1, 0);
         checkError(received, __LINE__);
         buffer[received] = '\0';

         if (strcmp(buffer, "$die!") == 0) {
            printf("terminated...\n");
            close(clientSock);
            close(srv);
            close(sid);
            break;
         } else {
            printf("bad command [%s]\n", buffer);
            char errorMsg[1024];
            strcpy(errorMsg, "bad command [");
            strcat(errorMsg, buffer);
            strcat(errorMsg, "]\n");

            send(clientSock, errorMsg, strlen(errorMsg), 0);
         }

         close(clientSock);
      }
   }

   cleanupDeadChildren();
   return 0;
}
