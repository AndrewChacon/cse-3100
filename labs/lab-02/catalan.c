/* Write a program to compute the nth Catalan number. */

#include <stdio.h>

long catalan_number(int n)
{
    /* TODO: Calculate the nth catalan number using the given recursion.
	     You do not need to use floating point operations */
    if(n == 0) { // base case c0 and c1 both = 1
        return 1;
    }

    // for (int i = 0; i < n; i++) {
    //     // the math goes here
    //     result += catalan_number(i) * catalan_number(n - i - 1);  // c0c3 + c1c2 + c2c1 + c3c0 = 14
    //     printf("%ld\n", result);
    // }

    long previous = catalan_number(n - 1);
    long result = (4 * n - 2) * previous / (n + 1);

    return result;
}

/* Do not change the main function */
int main(void)
{
    int n;

    while (scanf("%d", &n) == 1) {
        if (n < 0) 
            printf("C(%2d) is not defined.\n", n);
        else 
            printf("C(%2d)=%18ld\n", n, catalan_number(n));
    }
    return 0;
}