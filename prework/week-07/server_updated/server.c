#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <dirent.h>

// helps check any errors that might occur when making a call to a socket api function 
void checkError(int status) { 
    if(status < 0) {
        printf("Socket Error(%d): [%s]\n", getpid(), strerror(errno));
        exit(-1);
    }
}

// input: socket we get back from accept call 
void handleNewConnection(int chatSocket);

int main(int argc, char* argv[]) {
    // create socket
    int sid = socket(PF_INET, SOCK_STREAM, 0);

    // set up our address - listen on port 8080
    struct sockaddr_in addr;
    addr.sin_len = sizeof(addr);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8081);
    addr.sin_addr.s_addr = INADDR_ANY;

    // pairs new socket with requested address
    int status = bind(sid,(struct sockaddr*)&addr,sizeof(addr));
    checkError(status);

    // listen on socket, can queue up to 10 requests
    status = listen(sid, 10);
    checkError(status);


    while(1) { // always listening
        struct sockaddr_in client; // address of client 
        socklen_t clientSize;
        int chatSocket = accept(sid,(struct sockaddr*)&client,&clientSize); 
        // accept call on created socket using client address
        checkError(chatSocket);
        printf("We accepted a socket: %d\n", chatSocket);

        // server should go back to accepting more connections
        // fork to create new process that takes care of the connection we accepted 
        pid_t child = fork();
        if(child == 0) {
            handleNewConnection(chatSocket);
            close(chatSocket);
            return 1;
        } else if (child > 0){ // if return value of fork is a postive value, we have a child process. child will handle socket process
            printf("Created a child: %d\n", child);
            close(chatSocket);
            int status = 0;
            pid_t deadChild;
            do {
                deadChild = waitpid(0, &status, WNOHANG);
                checkError(deadChild);
                if(deadChild > 0)
                    printf("Reaped %d\n", deadChild);
            } while (child > 0);
            // if a deadchild is found lets wait for it
            // if dead child clean it up
            // keep going until we find more dead children
        }
    }
    return 0;
}

void handleNewConnection(int chatSocket) {
    // this is the child process
    int done = 0;
    char buf[256];
    char msg[] = "Howdy!"; // msg server sends back to client
    int status = recv(chatSocket, &buf, sizeof(buf), 0); // recieve in coming message from the client. addr of buf and size of buf
    checkError( status);
    printf("Client said     :[%s]\n",buf); // print buf
    printf("I'm responding: [%s]\n",msg); // print what we send back

    int rem = strlen(msg) + 1, sent = 0;
    while(rem != 0) {
        status = send(chatSocket, msg + sent, rem, 0);
        rem -= status;
        sent += status;
    }

    /*
    rem - remaining, len of my message + 1
    sent - havent sent anything yet

    as long as something is remaining
    try and send over socket all bytes starting from msg buffer + sent
    postive status - how many bytes sent 
    remaining non zero means still things to be sent
    */
}