single core vs multi core

single core - one process at a time
multi core - multiple processes running concurrently

threads and MIMD architectures
MIMD = multiple instructions multiple data
processor has
    - multiple execution units
    - all exec independently
    - all exec different instructions
    - all operating on different pieces of data

threads are OS abstrucations that capture computation streams
can be scheduled on a MIMD processor
all concurrent threads execute different instructions on different data

downside of threads
if a thread crashes the entire process will crash 
good multi threading must be very disciplined
good code, practice, synch, low overhead