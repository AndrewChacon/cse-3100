/*
 * Calculate and print the sum of all even numbers betweeen 1 and 100 (inclusive).
*/

#include <stdio.h>

int main(int argc, char* argv[]) {
    int sum = 0;
    int i=1;

    // Calculating the sum using a while loop
    while(i<=100) {
        if(i%2==0)
            sum = sum + i;
        i++;
    } 
    printf("The sum of even numbers between 1 to 100 is: %d\n", sum);

    // Alternatively, you can use a for loop
    sum = 0;
    for(i=1; i<=100; i++)
        if(i%2==0)
            sum = sum + i;
    printf("The sum of even numbers between 1 to 100 is: %d\n", sum);

    return 0;
}

