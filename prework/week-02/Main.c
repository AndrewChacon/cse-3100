// #include <stdio.h>

// #define INIT 0
// #define ENDV 300
// #define STEPV 10

// int main() {

    // blocks for while if-then-else switch break continue 
    // control - boolean conditions
    // group statements together

    // FOR LOOPS

    // for (int i = 0; i < 10; i++) {
        // do something 10 times
    // }



    // int lower, upper;
    // int step;
    // lower = INIT; macros made them not needed
    // upper = ENDV;
    // step = STEPV;

    // for (int fahr = INIT; fahr <= ENDV; fahr += STEPV) {
    //     int celcius = 5 * (fahr - 32) / 9;
    //     printf("From %d to %d C degrees\n", fahr, celcius);
    // }

    // WHILE LOOPS - unbounded loop
    // while(1) {
        // do this
    // }

    // BRANCHING 

    // if(1){
        // do this
    // }

    // if(1) {
        // do this
    // } else {
        // do this instead 
//     }


//         return 0;
// }


#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 10

int fact(int n) {
    if(n==0) {
        return 1;
    } else {
        return n * fact(n - 1);
    }
}

int fahrToCelcius(int degF);


#define MIN(x,y) ((x) < (y) ? (x) : (y))
#define MAX(x,y) ((x) >= (y) ? (x): (y))

int main() {
    // int w = fact(5);
    // printf("Answer: %d\n", w);

    // SWITCHES 
    // break and continue
    // avoid using continue, use break inside switches

    // FUNCTIONS
    // input output
    // specify what computations to do 
    // only depend on their inputs

    // for (int fahr = LOWER; fahr <= UPPER; fahr += STEP) {
    //     int celcius = fahrToCelcius(fahr);
    //     printf("From %d F to %d C degrees\n", fahr, celcius);
    // }


    // Avoid statics and globals
    // a function should only depend on an argument 


    // Function State 
    // mapping function calls
    // context frames - contain copy of function arugments
    // nothing in a frame survives a call 
    // Execution stack - memory management is automatic

    // int a = 10, b = 20;
    // int x = MIN(a, b);
    // int y = MAX(a, b);

    // printf("Min: %d\n", x);
    // printf("Max: %d\n", y);

    // macros are able to take arguments
    // use correct grouping of variables in macros 


    // MEMORY ORGANIZATION
    // every process has an address space 
    // Execuatable code at the bottom
    // statics are above that 
    // the stack is at the top - top down direction
    // heap grows from the bottom - bottom up direction 
    


    return 0;
}

// int fahrToCelcius(int degF) {
//     return 5 * (degF - 32) / 9;
// }

// compute x^n

// int power(int base, int n) {
//     int rv = 1;
//     while(n--)
//         rv *= base;
//     return rv;
// }

    // reursive version
// int power(int base, int n) {
//     if(n==0)
//         return 1;
//     else return base * power(base, n - 1);
// }
