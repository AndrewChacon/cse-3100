a thread never stays in critical section for long
spinlock
relies on hardware to get done
test and set - opperation is atomic

spinlock lock
if value back is 1, spin
spinlock unlock
write a 0 to the memory location
spinning inplace is expensive 