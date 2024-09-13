#include <stdio.h>
#include <stdlib.h>

// void memoryHog(int size);

int main() {
    /*
    Stack vs Heap

    Memory is an ordered list of locations to store data
    each position in memory has a unqiue address 

    The stack - in order right next to the existing memory allocated for already existing variables
    data is fixed size that doesnt change - variables

    head is for dynamic allocation of memory 
    request blocks of memory on heap of different sizes during runtime of a program 
    blocks can be different sizes and might not be in order

    malloc - function to request memory block on the heap
    create a dynamic array 
    create block of memory for each element 
    */

//    int *a = malloc(sizeof(int) * 10); // space for 10 ints

//     for (int i = 0; i < 10; i++) {
//         a[i] = 10 - i;
//     }

//     for (int i = 0; i < 10; i++) {
//         // printf("a[%d] = %d\n", i, a[i]);
//     }
    // printf("\n");
    // printf("a: %p\n", a);

    // after using allocated memory, we must free it
    // automatically done on the stack, not on the heap

    // free(a);

    // the stack grows downards into unused space
    // the heap grows upwards into unused space
    // we can allocate memory and run out of memory
    // free the memory to avoid a memory leak
    // manual memory management 
    // the programmer comepletely controls the memory



    // EXAMPLE OF A MEMORY LEAK

    // while(1) {
    //     memoryHog(1000000000);
    // }

    // we keep calling memoryHog which allocates a million bytes
    // but we never free this space
    // infinite loop

    // Calloc
    // calloc sets the space to all 0's

    int size = 0;
    printf("Enter size of array: ");
    scanf("%d", &size);

    int *a = calloc(size, sizeof(int)); // space for 10 ints
    for (int i = 0; i < size; i++) {
        a[i] = size - i;
    }
    for (int i = 0; i < size; i++) {
        // printf("a[%d] = %d\n", i, a[i]);
    }

    // int *save = a;
    // free(a);

    for (int i = 0; i < size; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    } // freeing the memory sets everything back to 0's

    // for (int i = 0; i < size; i++) {
    //     printf("save[%d] = %d\n", i, save[i]);
    // }

    // memory is freed to be allocated
    // the data is not deleted however
    // advantage of calloc is the data will be set to 0 

    // reallocate space for a larger block of memory

    a = realloc(a, sizeof(int) * (size + 5));
    // pointer to existing allocated space
    // size of new space
    // returns pointer to new block of memory
    // old block + new block - size is increased

    for (int i = size; i < (size + 5); i++) {
        a[i] = 9;
    }

    for (int i = size; i < (size + 5); i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    // bigger block of memory was allocated

    free(a);

    // benefit - performance
    // cost    - responsibility 

    return 0;
}

// void memoryHog(int size) {
//     int *a = malloc(size);
// }