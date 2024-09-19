/* Write a program to encrypt user input using Caesar cipher. 
 * Execute the program as: echo "ABCD" | ./p1 3
 */

#include <stdio.h>
#include <stdlib.h>

/* This function takes as input a char and encrypts it by shifting it by n spaces to the right. Assume that the user only inputs uppercase letters. 
 * For instance, if n = 3, then A --> D, B --> E, C --> F, D --> G, and so on. Do not forget to wrap around towards the end such that Z --> C. */
int caesar(int c, int n) {
    if (c >= 'A' && c <= 'Z') {
        return ((c - 'A' + n) % 26) + 'A';
    }
    return c;
}

int main(int argc, char* argv[]) {
    /* Take a sequence of uppercase letters as input from stdin and print the encrypted letters on stdout. You may use the fgetc and fputc functions for that. 
     * The number of places to shift each character is taken as command line input and stored in argv[1]. */
    int shift = atoi(argv[1]);
    int c;
    while ((c = fgetc(stdin)) != EOF) {
        fputc(caesar(c, shift), stdout);
    }
    return 0;
}