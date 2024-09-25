#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define LINE_SIZE 1024

/* This function prints lines (in a file) that contain string s.Assume all lines have at most (LINE_SIZE - 2) ASCII characters. */
int print_matched_lines(const char *s, const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file) {
        // error opening file 
        return -1;
    }

    char line[LINE_SIZE];
    while (fgets(line, LINE_SIZE, file)) {
        if (strstr(line, s)) {
            printf("%s", line);
        }
    }

    fclose(file);
    return 0;
}

int main(int argc, char **argv)
{
    if (argc != 3) {
        printf("Usage: %s <string> <filename>\n", argv[0]);
        return -1;
    }

    if (print_matched_lines(argv[1], argv[2])) {
        printf("print_matched_lines() returned a non_zero value.\n");
	return -1;
    }
    return 0;
}
