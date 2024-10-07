/*
sockets are nothing but file descriptors
they can be manipulated just like files

sockets at the unix level
api to:
    - open / create
    - close
    - read / write

socket based comms
    client, server, protocol, network encoding, msg format

client server world
server
    - listen on a port for inbound "lets talk" requests
    - passive
client
    - initiates commns with the serveer
    - must know:
        server name
        port number
        protocol (tcp/udp)
    - active 


server side
use case tcp
    - sever binds a port for chatting
    - server listens on port for lets talk requests
    - when request comes in:
        sever allocates a seperate socket to accept private comm wit hthe client
        original socket waits for future lets talk
        comm goes on seperate socket with send/recv pairs
        conversation ends with client via close function

udp
    - similar but not accept

use send and recieve api 
close upon finishing process 
bind listen lets-talk accept listens send/recive close 



*/

#include <unistd.h> // unix apis
#include <stdio.h>
#include <stdlib.h> // malloc
#include <string.h> // strings
#include <errno.h> // errors
#include <sys/types.h> // manipulate sockets
#include <sys/socket.h> // manipulate sockets
#include <netinet/in.h> // headers for ipv4 ipv6 addresses

void checkError(int status) { 
    if(status < 0) {
        printf("Socket Error: [%s]", strerror(errno));
        exit(-1);
    }
}

int main(int argc, char* argv[]) {
    // create socket 
    int sid = socket(PF_INET, SOCK_STREAM, 0);
    // sock stream - specifiies tcp
    // 0 is for options - check docs
    // sid int - file descriptor of socket

    // setup our address - will listen on 8080
    struct sockaddr_in addr; // init socket struct
    addr.sin_family = AF_INET; // kind of network protocol af inet
    addr.sin_port = htons(8080); // port number 
    addr.sin_addr.s_addr = INADDR_ANY; // connect on any ip supported addresses

    // pairs newly created socket with requested address
    int status = bind(sid, (struct sockaddr *)&addr, sizeof(addr));
    // bind - connect socket to given address
    checkError(status); // if error arises

    // listen on socket for lets talk message
    status = listen(sid, 10); // const 10 - # of lets talk requests pending 
    checkError(status);


    while(1) { // always listening for chat request
        struct sockaddr_in client; // addr of client connecting to socket
        socklen_t clientSize; // size of info 
        int chatSocket = accept(sid, (struct sockaddr *)&client, &clientSize);
        // give address of client and client size
        checkError(chatSocket);
        printf("We accepted a socket: %d\n", chatSocket);
        close(chatSocket);
    }
    return 0;
}