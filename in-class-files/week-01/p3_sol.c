/*
 * Print the first n rows of Floyd's triangle, where n is an integer taken as input from the user. 
       Example: Below are the first 4 rows of Floyd's triangle 
        1
        2 3
        4 5 6
        7 8 9 10
*/

#include <stdio.h>

int main(int argc, char* argv[]) {
    // int n, val=1;
    // printf("Enter a value for n: ");
    // scanf("%d", &n);

    // // Using a nested while loop
    // int j=1, i=1;
    // while(i<=n) {
    //     while(j<=i) {
    //         printf("%d ", val);
    //         val++;
    //         j++;
    //     }
    //     j=1;
    //     i++;
    //     printf("\n");
    // }

    // printf("\n");
    
    // // Alternatively, you can use a nested for loop
    // val=1;
    // for(int i=1; i<=n; i++) {
    //     for(int j=1; j<=i; j++) {
    //         printf("%d ", val);
    //         val++;
    //     }
    //     printf("\n");
    // }

    int row, col, count = 1;
    int num = 4;

    printf("Increasing\n");

    for (row = 1; row <= num; row++) {
        for (col = 1; col <= row; col++) {
            printf("%d ", count++);
        }
        printf("\n");
    }

    printf("Decreasing\n");

    for (row = 1; row <= num; row++) {
        for (col = row; col <= num; col++) {
            printf("%d ", count++);
        }
        printf("\n");
    }

        return 0;
}



/*
enter number of rows
*/
