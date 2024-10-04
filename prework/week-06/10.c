/*
the shell is a process
its job is to create other processes

string "hello you" passed as input to program

redirect output of echo as the input of other process

echo "hello you" | cat
echo "hello you" | md5

pipe takes as input, an array of size 2 ints
execute and create a pipe
file descriptors
    - end point of pipe write
    - end point of pipe read

$ A | B     stdin stdout stderr
shell sets up the pipe for points to communicate
set up before we fork

4 is a pointer to read end
3 is a pointer to write end
[4,3] our array

now its time to fork
4 is a pointer to read end
3 is a pointer to write end

parent wont communicate the pipe
pipe is meant as a process for A and B
the parent shell sets up the pipe fot communication

child process needs to write to the pipe
stdout currently points to 1
close(1) dup(3); stdout points to 3 now

parent process close write end
A already has write end
parent holds onto read end of the pipe

close(0); dup(4);

pipe went from 
process 1 to 2
then process 2 to 3

change pointers so that 2 -> 3 and 3 -> 2

once per stage of the pipeline
all processes of pipeline run concurrently
when first source process dies its output is closed
child keeps reading remaining inputs
and dies when he has wirtten its last output

when a process ends all its open files close
    all pipes get closed automatically


*/


/*

*/