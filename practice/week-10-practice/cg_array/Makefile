CFLAGS = -g
CC = cc
OFILES = sarray.o sarrayTest.o

all: sarrayTest

sarrayTest: $(OFILES)
	$(CC) $(OFILES) -lpthread -o $@

sarray.o: sarray.c sarray.h
	$(CC) -c $(CFLAGS) $<

sarrayTest.o: sarrayTest.c sarray.h
	$(CC) -c $(CFLAGS) $<

clean:
	rm -rf *.o *~ sarrayTest	
