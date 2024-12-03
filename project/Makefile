CC = cc
CFLAGS = -g
LFLAGS = -pthread

all: dining selectionSortTest

dining: dining.o
    $(CC) $(CFLAGS) dining.o -o dining $(LFLAGS)

dining.o: dining.c dining.h
    $(CC) $(CFLAGS) -c dining.c -o dining.o

selectionSort.o: selectionSort.c
    $(CC) $(CFLAGS) -c selectionSort.c -o selectionSort.o

selectionSortTest: selectionSort.o selectionSortTest.c
    $(CC) $(CFLAGS) selectionSortTest.c -o selectionSortTest selectionSort.o $(LFLAGS)

clean:
    rm -rf *.o dining selectionSortTest