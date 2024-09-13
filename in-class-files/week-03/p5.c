/* Write a C program to implement a min heap. Your program must implement the below functions:
 * makeHeap - creates a heap in memory. Input: max number of values that the heap can hold. Output: pointer to the heap in memory. 
 * insertHeap - insert values in a heap starting at index 1. Make sure the heap property is maintained. Input: pointer to a heap, value to insert.  
 * printHeap -  prints the values as a heap. Input: pointer to a heap. 
 * emptyHeap - check if a heap is empty. Input: pointer to a heap. Output: true if the heap is empty; false otherwise.
 * extractMin - extract and return the min value from a heap. Make sure the remaining elements form a valid heap. Input: pointer to a heap. Output: an int value.
 * freeHeap - deallocates any allocated memory. Input: pointer to a heap.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Heap {
	int* t;	 //pointer to an array containing the elements in the heap
	int sz;  //number of elements currently in the heap
	int msz; //max number of elements a heap can store
} Heap;

int main() {
	Heap* h = makeHeap(128);
	for(int i=0; i<10; i++)
		insertHeap(h, 10-i);
	printHeap(h);
	while(!emptyHeap(h)) {
		int v = extractMin(h);
		printf("Got: %d\n", v);
	}
	freeHeap(h);
	return 0;
}
