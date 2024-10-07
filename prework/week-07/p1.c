/*
Socket Programming

socket based communication:
client and server relationship
network encoding
message format

inter-process communication - pipes
inter-machine communication - sockets

sockets are very useful for inter machine concurrency
sockets rely on networking layers
focus tcp/ip

end to end comm layer
handles format and transmission of packets residing on different machines
addressing, routing, modality
tcp/ip is organized in layers (osi)
model based on 7 layers

osi layers: physical, data link, network, transport, session, presentation, application

tcp/ip layers: application, transport, internet, network interface

network tpology
host a -> router -> router -> host b

data flow

transport - tcp or udp
ip layer - internet protocol
link later - wireless access point and home router

encapsulation
data, application, l4
udp transport - udp header added, udp header becomes payload
ip header
link frame - link layer ex. ethernet

[frame - header][ip][data][frame - footer]

manipulating the payload from layer 2
ip(internet protocol) a datagram service
packets are handled independently
best effort (no loses, no order, duplication)
every packet has a destination "label": the address

ipv4 addressing - up address ex 137.99.10.65

transport layer - sits above ip layer
tpc - transmission control protcol
udp user datagrak protocol

tpc - connection oriented (telephone system)
reliable, byte stream channel
flow control and bi directional
things arrive in order - buffering
check if packets are lost - taken care of by tcp 

udp - connectionless 
no acknowledgements or retransmissions
up to you to sort out if packets are lost or duplicated
modern apps dont use udp
no ordering





*/

#include <stdio.h>

int main() {
    printf("Hello World!");
}
