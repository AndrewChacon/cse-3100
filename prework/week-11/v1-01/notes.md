posix conditions

mutexes are useful to create critical section

some thread produce content or values
other threads consume the content
both groups need a mechanism to handshake

theres data to use, pick it up and working on it

handshake mechanism is always paired with a sharing protection
if soem data is exhanged its access is mutex protected

setup
    - POSIX condtion var 
    - POSIX mutex
    - boolean predicate P


producer starts producing before consumer tries consuming
consumer is eagar and tries to consume before produce has produced anything 

t1 changes shared data condition
t2 wakes up and checks the predicate
critical section for t1 and t2 never overlap
