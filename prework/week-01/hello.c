#include <stdio.h>

#define BOOL char
#define TRUE 1
#define FALSE 0

int main(int argc, char* argv[]) {
    printf("Hello World!\n");
    // return 0; // 0 = exec was successful 


    // cc hello.c - compile our code
    // ./a.out  - this is an executable for the program

    /*
    int argc, char* argv[]
    arguments passed into our main functions
    argc and argv
    */

    int length = 100;
    int counter = 0;
    int sum = 0;
    while (counter < 100)
    {
        counter = counter + 1;
        if(counter % 2 == 0) {
            sum = sum + counter;
        }
    }
    printf("\nSum of even #: %d\n", sum);


    // Expressions in C-lang
    /*
    constants cant be changed 
    */
    float fahr;
    float celcius;
    fahr = 90;
    celcius = 5 * (fahr - 32) / 9; // int cannot represent decimals 
    // fahr = 91.45;
    printf("celcius: %f", celcius);

    // assignments are not statements

    // creating boolean expressions

    BOOL x = TRUE;
    BOOL y = FALSE;
    BOOL w, z;

    z = x || y;
    w = x && y;
    printf("\n");
    printf("z is = %d\n", z);
    printf("w is = %d\n", w);

    return 0;
}