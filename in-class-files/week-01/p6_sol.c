/*
 * Print the following pattern of * for n rows, where n is an integer taken as input from the user. In the below example, n = 5.
            *
          * *
        * * *
      * * * *
    * * * * *
*/

#include <stdio.h>

int main(int argc, char* argv[]) {
    int n;
    printf("Enter a value for n: ");
    scanf("%d", &n);

    // Notice that the given pattern is a combination of an inverted triangle of spaces and an upright triangle of *
    // Using a nested for loop
    for(int i=1; i<=n; i++) {
        for(int j=n; j>i; j--) {
            printf("  ");
        }
        for(int j=1;j<=i;j++) {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}
