/* File IO in C
 * This program reads text from the user, writes it to a file, and then reads the contents of the file and displays them on the console.
 * 
 * To do this we make use of the following functions:
 * * fopen and fclose - to open and close a file
 * * fgets - to read a string from the user and then to read contents from the file
 * * fprintf - to write a string into a file
 * * * int fprintf(FILE *stream, const char *format, char *str, ...); //pointer to the FILE stream where the output is to be written, format of the output, char array containing the string to be written 
*/

#include <stdio.h>

int main() {
    FILE *fp;   // pointer to type FILE
    char str[100]; // character string array of length 100

    fp = fopen("output.txt", "w"); // opening up a file called output.txt for writing
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    printf("Enter a string: ");
    fgets(str, 100, stdin);

    fprintf(fp, "%s", str);

    fclose(fp);

    fp = fopen("output.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    while (fgets(str, 100, fp) != NULL) {
        printf("%s", str);
    }

    fclose(fp);

    return 0;
}