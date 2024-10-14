/*
Protocols

working with TCP - order is preserved - sending and recieving a stream of bytes

api
    - int send(sockfd, msg, msgLen, flags)
    - int recv(sockfd, buffer, bufLen, flags)

how do you encode messages?
raw, xml, json, yaml

why is there a need to?
sends on the messages u are sending, application dependent

example trivial file transfer protocol
    - make app specific messages
    example commands
        - ls: list files on server
        - GET(fn): get back file
        - PUT(fn): sends file to server
        - EXIT: end session

encode the command in a message

GET(fn)
"get : hello.txt"

binary option:
#define LS      0
#define GET     1
#define PUT     2
#define EXIT    3

struct Command {
    int code;
    char fileName[256];
}

nothing to parse, fixed size
compact

send file in response
    - send the file size (n)
    - send n bytes

Network Encoding
big endian 
little endian 

byte ordering
    - host byte ordering: natural for platform
    - network byte ordering: always big endian

alignment and padding
compiler can introduce padding in structures
can affect the size of the structure
make the struct explicit

*/