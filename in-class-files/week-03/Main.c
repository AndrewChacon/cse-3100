#include <stdio.h>
#include <stdlib.h>

/*
malloc gives memory from the heap - memory stack
life time of array is life time of the function 

*/

// using astrikes to show that it is pointers
// & address of 
// * derefernceing the pointer

// void swap(int *x, int *y) {
//     int temp = *y;
//     *y = *x;
//     *x = temp;
//     return;
// }

// void printMat(int n, int x[n][n]) {
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             printf("%d ", x[i][j]); 
//         }
//         printf("\n"); 
//     }
//         return;
// }

void printMat(int n, int** x) { // ** pointer to a pointer
    /*TODO: print the matrix stored in x */
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", x[i][j]); 
        }
        printf("\n"); 
    }
    return;
}

int main() {

    // int n, i, sum = 0;
    // float average;

    // int input = 0;

    // printf("Enter value for n: ");
    // scanf("%d", &n);

    // int values[n];

    // for (int i = 0; i < n; i++){
    //     printf("Enter value: ");
    //     // scanf("%d", &input);
    //     // values[i] = input;
    //     scanf("%d", &values[i]);
    //     sum += values[i];
    // }

    // average = (float)sum / n;

    // printf("Average: %f", average);

    // int a = 10, b = 20;
    // printf("Before swamping: a = %d, b = %d\n", a, b);

    // // call swap function
    // swap(&a, &b); // passing pointers

    // printf("After swamping: a = %d, b = %d\n", a, b);

    // int imatrix[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

    // int arr[n][n];
    // printMat(3, imatrix);

    int n = 4;
    // (int**)malloc(n*sizeof(int*))

    int **m2 = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        m2[i] = (int *)calloc(n, sizeof(int));
        m2[i][i] = 1;
    }

    for (int i = 0; i < n; i++) {
        free(m2[i]);
    }

        /*TODO: allocate memory and initialize a 2-D identity matrix of size n x n. Call the printMat function to print the matrix. */

        // an array of pointers
        // double pointers
        // all values replaced with '0's
        // find out and replace only values that should be '1'

        // maximum subarray problem
        // heaps

        return 0;
}