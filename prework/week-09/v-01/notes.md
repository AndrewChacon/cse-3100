Introduction to threads

proces and thread abstractions
data sharing - memory, code

processes do run concurrently on an OS
processes support time sharing and multi tasking on multicore
processes also provide protection

a thread lives alone - isolated
multi threading changes that

multiple threads inside the same process

you have to do everything alone
isolation - prison

comms outside is tricky but very limited
threads all exist on their own, sharing is limited, cannot get together easily

concurrency with processes
doable with virtual shared memory (pipes or sockets)

google chrome very much uses multiple threads for every process that the chrome browswer uses

can we do better?
