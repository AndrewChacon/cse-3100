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
    int n=0;
    printf("Enter a value for n: ");
    scanf("%d", &n);

    // Using a nested for loop
    for(int i=1; i<=n;i++) {
        for(int j=1;j<=i;j++) {
            printf("* ");
        }
        printf("\n");
    }

    printf("\n");

    // Alternatively, you can use a nested while loop
    int i=1, j=1;
    while(i<=n) {
        while(j<=i) {
            printf("* ");
            j++;
        }
        j=1;
        i++;
        printf("\n");
    }

    return 0;
}
