/*
pipes

process descriptor - pointer to table
the table has multiple entries - 0 1 2
0 points to file - standard input
1 points to file - terminal stdout
2 points to error - stderror 

fork copies the AS - identical
the copy has reference to exact same table
parent gets identifier, child gets 0
child inherits all the files of the parent

set up communication channels to communicate between child and parent
this is called pipes

playing with redirections
child process inherits files of parent
child can replace file to stdin with another file
upgrade output from terminal to file

shell redirections

sort < file.txt > sorted.txt
< filename - take input from file filename
> filename - send output to file filename
2> filename: send errors to file filename 

take input from file.txt and send output to sorted.txt

echo "hello world" | md5
    take stdin of echo and make it the stdin of another process

echo "hello world" | cat

echo "hello world" | cat | md5
multiple pipes
stdin of echo into cat -> stdin of cat to md5

*/