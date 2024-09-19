/* Write a program to encrypt user input using Caesar cipher. 
 * Execute the program as: echo "ABCD" | ./p1 3
 */

#include <stdio.h>
#include <stdlib.h> //cannot be executed without this at least

/* This function takes as input a char and encrypts it by shifting it by n spaces to the right. Assume that the user only inputs uppercase letters. 
 * For instance, if n = 3, then A --> D, B --> E, C --> F, D --> G, and so on. Do not forget to wrap around towards the end such that Z --> C. */
int caesar(int c, int n) {
    return ((c - 'A' + n) % 26) + 'A';  // Shift the character and wrap around using modulo 26
}

int main(int argc, char* argv[]) {
    /* Take a sequence of uppercase letters as input from stdin and print the encrypted letters on stdout. You may use the fgetc and fputc functions for that. 
     * The number of places to shift each character is taken as command line input and stored in argv[1]. */
    // Check if the number of arguments is correct
    if (argc != 2) {
        printf("Usage: ./p1 <shift>\n");
        return 1;
    }

    // Convert the shift value from the command line argument to an integer
    int shift = atoi(argv[1]);
    int ch;

    // Read input from stdin character by character using fgetc
    while ((ch = fgetc(stdin)) != EOF) {
        // Check if the character is an uppercase letter
            if (ch >= 'A' && ch <= 'Z') {
            // Encrypt the character using the Caesar cipher
            ch = caesar(ch, shift);
        }
        // Output the character using fputc
        fputc(ch, stdout);
    }

    return 0;
}