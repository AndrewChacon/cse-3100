/*
ports 
port numbers - integers - 'doors' to talk to tcp stack
up to 65k 'doors'
http - the protocol that a web server talks
listens behind door 80 
talk to a service connected to port 80 on machine
client faces a similar experince
router with physical ethernet - connects machine A to B

on port 80 - is connected to a socket
client side also has a socket attatched to a port

sockets
indentification
    - an internet address ipv4 or ipv6
    - a transport protocol tcp or upd
    - a port number

two types of sockets:
    stream sockets: tcp
        - byte oriented
    datagram sockets: udp
        - single payload oriented
        - one packet at a time


*/