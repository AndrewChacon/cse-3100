/* Print the following diamond of * for n rows, where n is an integer taken as input from the user. In the below example, n = 5.

            *
          * * *
        * * * * *
      * * * * * * *
    * * * * * * * * *
      * * * * * * *
        * * * * *
          * * *
            * 
            
*/

/* Do not edit the code that is given to you. */

#include <stdio.h>

int main(int argc, char* argv[]) {
    int n;
    printf("Enter a value for n: \n");
    scanf("%d", &n);

    /* Put your code after this line */

      // top of the triangle

      for (int i = 1; i <= n; i++) {

        // leading spaces
        for (int j = i; j <= n; j++) {
          printf("  ");
        }
        // left side of triangle
        for (int j = 1; j < i; j++) {
          printf("* ");
        }
        // one less row on right side for tip
        for (int j = 1; j <= i; j++) {
          printf("* ");
        }
        printf("\n");
    }


    // bottom of triangle

    for(int i = n - 1; i >= 1; i--) {

      // leading spaces 
      for (int j = 0; j <= n - i; j++) {
        printf("  ");
      }

      // left side of triangle
      for (int j = 1; j <= i; j++) {
        printf("* ");
      }

      // right side of triangle - 1 less iteration
      for (int j = 1; j < i; j++) {
        printf("* ");
      }
      printf("\n");
    }

    

    return 0;
}
