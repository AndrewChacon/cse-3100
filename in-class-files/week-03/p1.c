/* Write a C program to find the average of a set of integers stored in an array. */

#include <stdio.h>

int main() {
    int n, i, sum = 0;
    float average;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    /* TODO: Create an array of size n to store the user input and compute the average. */

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    average = (float)sum / n; // must be type casted since sum and n are ints

    printf("Average = %.2f\n", average);
  
    return 0;
}