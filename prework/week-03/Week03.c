#include <stdio.h>

int main() {

    /*
    array is a type construction - produces new type
    linear, contiguous. fixed - 0 to n-1
    array is located on the stack 
    allected when you enter the function 
    array is deallocated when the function returns 
    each recursion call gets its own copy
    access x[5]?? buffer overflow
    access x[-1]?? not good practice
    */

    // int x[5];

    // x[0] = 1;
    // x[1] = 2;
    // x[2] = 3;
    // x[3] = 4;
    // x[4] = 5;
    // x[5] = 6;
    // x[6] = 7;    buffer overflow 

    // for (int i = 0; i < 5; i++) {
    //     printf("%d\n", x[i]);
    // }

    // char s[6];

    // s[0] = 'H';
    // s[1] = 'e';
    // s[2] = 'l';
    // s[3] = 'l';
    // s[4] = 'o';
    // s[5] = '\0';

    // char s[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    // char s[6] = "Hello"; // binary null is still present '\0'

    // char s[] = "Hello"; // binary null is still present '\0'
    //printf("Array is: %s\n", s); // passing entire array

    /*
    can be static
    can be dynamic 
    cannot be too large - stack has limited space
    arrays are passed as pointer - reference to orignal array 
    */

   // structures - compound types
   
    // struct Person {
    //     int age;
    //     char gender;
    // }

    // struct Person p;
    // p.age = 44;
    // p.gender = 'M';

        // struct Person {
    //     int age;
    //     char gender;
    //     char name[32];
    // }

    // struct Person family[4] = {
    //     {50, 'M', "Darth Vader"},
    //     {49, 'F', 'Padme'},
    //     {21, 'M', 'Luke'},
    //     {19, 'F', 'Leia'}
    // }

    

    return 0;
}