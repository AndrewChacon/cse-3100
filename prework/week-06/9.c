/*
Building pipes with IO APIs
unix has lower level api for file handling

directly mapped to system calls
no buffering
raw IO
uses of level file descriptors - 0 1 2

open close read write
dup dup2

dup api duplicates file handles

two processes in general
each has its own table
child being identical copy of parents table
child file descriptors are being references to parent table
child has access to parents files

this doesnt have to stay the same
we can replace input and output with other files
close file descriptor 0 - close(0);
dup(3); - first unused entry will get replaced by new value 
0 will point to file 3 
closing file makes it unused
file3 is now default for stdin instead of 0
close 1 and dup 4 to override stdout

stdin 0
stdout 1
stderr 2

who can call dup? the child after you fork
you dont wanna do this to the parent
should be done before execl 
after fork but before execl

call close 0 before fork - you lose stdin of parent
child will inherit a closed stdin file
parent also looses its stdin

you call close(0) after forking
the child inherits parent stdin
parents stdin is unaffected

cant close after execl? no its too late to do that

*/

#include <fcntl.h>
#include <unistd.h>

