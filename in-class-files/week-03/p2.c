/* Write a C program that swaps the values of two variables using pointers. */

#include <stdio.h>

void swap(int *x, int *y) {
    /*TODO: Swap the values pointed by x and y. */
    int temp = 0;
    temp = *x;
    *x = *y;
    *y = temp;
    // dereference what x and y are pointing to 
    return;
}

int main() {
    int a = 10, b = 20;
    printf("Before swapping: a = %d, b = %d\n", a, b);

    /*TODO: call the swap function to swap the values */
    swap(&a, &b); // reference the pointer a and b

    printf("After swapping: a = %d, b = %d\n", a, b);
    return 0;
}