CFLAGS = -g
CC = cc
OFILES = counter.o counterTest.o

all: counterTest

counterTest: $(OFILES)
	$(CC) $(OFILES) -lpthread -o $@

counter.o: counter.c counter.h
	$(CC) -c $(CFLAGS) $<

counterTest.o: counterTest.c counter.h
	$(CC) -c $(CFLAGS) $<

clean:
	rm -rf *.o *~ counterTest	
