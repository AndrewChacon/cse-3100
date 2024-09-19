/* File IO in C
 * This program counts the number of lines in a given text file. 
 *
 * How do we get FILE* ? 
 * * FILE* fopen(const char *restrict filename, const char *restrict mode); //filename is the name of the file to open and mode specifies what actions should be permissible.
 * * int fclose(FILE *stream);  //stream is a pointer to the file that needs to be closed.
 * * int feof(FILE *stream); // stream is a pointer to the file that we are reading. feof returns TRUE if we have reached the end of file.
 * 
 * How to read lines from a file ?
 * * char *fgets (char *str, int n, FILE *stream);  //str is a pointer to a char array where the string read will be copied, n is the max number of chars to be copied incl NULL, pointer to the input file. 
 */

#include <stdio.h>

int main() {
    FILE *fp;
    char str[1000]; //at a time we will only read upto 100 characters including a NULL. That is, every 100 chars make a line.
    int count = 0;

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // if fgets successfully reads chars <= 100 or chars and a newline, increment the number of lines by 1. fgets returns NULL if no chars are read or EOF has been reached
    while (fgets(str, 1000, fp) != NULL) {
        count++;
    }

    printf("Number of lines: %d\n", count);

    fclose(fp);

    return 0;
}