/* Write a C program to find the average of a set of numbers stored in an array. */

#include <stdio.h>

int main() {
    int n, i, sum = 0;
    float average;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i]; 
    }

    average = (float)sum / n;

    printf("Average = %.2f\n", average);

    return 0;
}