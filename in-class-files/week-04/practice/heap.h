#ifndef HEAP_H
#define HEAP_H

typedef struct Heap { 
	int* t;
	int sz; 
	int msz;
} Heap;

Heap* makeHeap(int msz);
void freeHeap(Heap* h);
void insertHeap(Heap* h, int val);
void printHeap(Heap* h); // void printHeapAux(Heap* h, int from)
int emptyHeap(Heap* h);
int extractMin(Heap* h);

#endif

/* 
makefile variables
flags to include during compile
gcc compiler 
object files - o files
*/