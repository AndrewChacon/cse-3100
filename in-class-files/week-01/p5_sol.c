/*
 * Print the following pattern for n rows, where n is an integer taken as input from the user. In the below example, n = 5.
    * * * * *
    * * * *
    * * *
    * *
    * 
*/

#include <stdio.h>

int main(int argc, char* argv[]) {
    int n;
    printf("Enter a value for n: ");
    scanf("%d", &n);

    // Using a nested for loop. Notice how we have now flipped the initialization of the loop and used a decrementer 
    for(int i=n; i>=1; i--) {
        for(int j=i; j>=1; j--) {
            printf("* ");
        }
        printf("\n");
    }

    printf("\n");

    // Alternatively, you can use a nested while loop
    int i=n;
    int j=i;
    while(i>=1) {
        while(j>=1) {
            printf("* ");
            j--;
        }
        i--;
        j=i;
        printf("\n");
    }
    return 0;
}

