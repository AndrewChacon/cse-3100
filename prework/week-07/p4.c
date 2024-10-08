// CLIENT SIDE EXAMPLE

#include <stdio.h>
#include <stdlib.h> // malloc
#include <string.h> // strings
#include <sys/types.h> // manipulate sockets
#include <sys/socket.h> // manipulate sockets
#include <netdb.h>
#include <netinet/in.h> // headers for ipv4 ipv6 addresses
#include <errno.h> // errors

void checkError(int status) { 
    if(status < 0) {
        printf("Socket Error: [%s]", strerror(errno));
        exit(-1);
    }
}

int main(int argc, char* argv[]) {
    int sid = socket(PF_INET, SOCK_STREAM, 0); // tcp socket
    struct sockaddr_in srv; // socket addr srv - addr of server
    struct hostent *server = gethostbyname("localhost"); // give me ip for localhost - connect to server on same machine
    // server is a pointer to host entity
    srv.sin_family = AF_INET; // connect to internet
    srv.sin_port = htons(8080); // specify port
    memcpy(&srv.sin_addr.s_addr, server->h_addr, server->h_length);
    // copy address of server, hostname and len inside s address field of target
    int status = connect(sid, (struct sockaddr *)&srv, sizeof(srv));
    // connect sid socket to destination of server
    checkError(status);
    return 0;
}

/*

summary
3 entities: server, private agent, client

server creates socket, binds socket, listens for request
    enters infinite loop listening and accepting requests

client creates socket, requests server to connect
lets talk reaches server

server accept returns a socket - file descriptor for private comms 

private agent created in response to having a socket for the conversation
can create this using a fork - inherits files of parent 

child socket can now send info and read from client, client can read info and send to private angent 
ping pong conversation between the two
either one can initate close, the other recieves end of file return 

private agent could be a thread or a cloned process (fork)


On the server side:
    - accept is blocking until lets talk request comes in
    if servering client directly
        - lets talk requests are queued up to max # set in listen
        - forking sub process to talk to client
On client side:
    - connect is blocking until server responds or refuses 


*/