/* Print the following pattern of * for n rows, where n is an integer taken as input from the user. In the below example, n = 5.

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

    for(int i = n; i >= 1; i--) {

      // leading spaces 
      for (int j = 0; j < n - i; j++) {
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
