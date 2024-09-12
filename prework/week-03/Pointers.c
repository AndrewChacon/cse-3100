#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);

int main() {

    /*
    Programs and data are both stored in RAM memory when executing
    Memory addresses have some number - specifies its position in memory
    Variables stored in memory, at a memory address
    Some kind of unique postive int for the address
    */

    /*
    Pointers are vairables that store a memory address
    Hold memory address of another variable
    Have a type - type of variable that pointer is pointing to 
    */

    /*
    int *a;
    Pointer variable that points to an int variable
    The variable a, will store a memory address 
    the memory address is of another int variable
    */

    // int b = 42;
    // int *a = &b;

    // printf("b:  %d\n", b);  // value of b
    // printf("&b: %p\n", &b); // memory address of b 
    // printf("a:  %p\n", a);  // pointing to memory address of b

    // use a to access the value of b and modify it
    // *a = 50; // modify value of b
    // printf("b:  %d\n", b); 
    // printf("&b: %p\n", &b);
    // printf("a:  %p\n", a);

    // pass by reference or (pass by pointer)
    // a function that modifies multiple variables at once
    // dynamic memory allocation

    // int a, b, c;
    // a = b = c = 0;
    // printf("Enter 3 numbers: ");
    // scanf("%d %d %d", &a, &b, &c);
    // printf("Result: %d\n", a + b + c);

    /*
    passing variables to functions, passing the values 
    pass by pointer 
    */

    // int x, y;
    
    // x = 5;
    // y = 10;

    // printf("x: %d, y: %d\n", x, y);
    // printf("&x: %p, &y: %p\n", &x, &y);
    // swap(&x, &y);
    // printf("x: %d, y: %d\n", x, y);

    // dynamic memory allocation
    // int a[10];   static
    int *a;
    int length = 0;

    printf("Enter a length: ");
    scanf("%d", &length);

    a = malloc(length * sizeof(int));
    /*
    malloc allocates space on the heap
    area of memory for dynamically allocated things
    a will be a pointer to the newly allocated space 
    malloc takes input of how much space we need
    size of int * length
    */

    printf("a: %p\n", a);

    for (int i = 0; i < length; i++) {
        a[i] = i;
    }

    for (int i = 0; i < length; i++) {
        printf("a[%d] = %d\n", a[i], i);
    }

    free(a); // frees up the allocated space we used
    // dynamic memory allocation - not fixed spaces in runtime

    return 0;
}

// void swap(int *a, int *b) {
//     printf("a: %p, b: %p\n", a, b);
//     printf("*a: %d, *b: %d\n", *a, *b);
//     int temp = 0;
//     temp = *a;
//     *a = *b;
//     *b = temp;
// }