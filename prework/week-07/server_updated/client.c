#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <errno.h>

// helps check any errors that might occur when making a call to a socket api function 
void checkError(int status, int line) { 
    if(status < 0) {
        printf("Socket Error(%d)-%d: [%s]\n", getpid(), line, strerror(errno));
        exit(-1);
    }
}

int main(int argc, char* argv[]) {
    // create socket
    int sid = socket(PF_INET, SOCK_STREAM, 0); // tcp
    struct sockaddr_in srv;
    struct hostent *server = gethostbyname("localhost"); //description of local host
    srv.sin_len = sizeof(srv);
    srv.sin_family = AF_INET;
    srv.sin_port = htons(8081); // data
    memcpy(&srv.sin_addr.s_addr, server->h_addr, server->h_length);
    // copy address of server
    int status = connect(sid, (struct sockaddr *)&srv, sizeof(srv));
    checkError(status, __LINE__);
    // connect on socket and pass address of server we want to connect to
    char buf[] = "Hello server!"; // message we want to send

    int rem = strlen(buf) + 1, sent = 0;
    while(rem) {
        status = send(sid, buf + sent, rem, 0);
        checkError(status, __LINE__);
        sent += status;
        rem -= status;
    } 
    // keep sending what remains - lack of buffering
    // receive exactly what you need
    // how do i know how many bytes to recieve?
    // protocols - msgs conform to a protocol - shows size of msg
}