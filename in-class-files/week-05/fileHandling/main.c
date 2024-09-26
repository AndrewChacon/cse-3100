#include <stdio.h>
#include <stdlib.h>

int main() {
    // standard input/output
    // int num;
    // printf("enter a number: ");
    // scanf("%d", &num);
    // printf("You entered: %d\n", num);
    // printf and scanf are examples of basic i/o

    // FILE I/O
    // fopen - opens file for reading or writing
    // FILE *fopen(const char *filename, const char *mode);
    // mode: r, w, a, r+, a+

    // FILE *fp = fopen("example.txt", "r");
    // if(fp == NULL) {
    //     printf("Error opening file!\n");
    //     return 1;
    // }

    // do something file file

    // fclose(fp); // close file after operations

    // FILE *fp = fopen("data.txt", "r");
    // int num;
    // printf("%d", num);
    // fscanf(fp, "%d", &num);
    // return 0;

    // FILE *fp = fopen("output.txt", "w");
    // if(fp == NULL) {
    //     printf("Error opening file");
    //     return 1;
    // }
    // fprintf(fp, "The result is: %d\n", 42);

    // fputs("Hello, world!\n", fp);
    // fclose(fp);

    // FILE *fp = fopen("output.txt", "r");
    // if (fp == NULL) {
    //     perror("Error opening file");
    //     return 1;
    // }
    
    // int num;
    // // Reading an integer from the file
    // fscanf(fp, "%d", &num);
    // printf("Read from file: %d\n", num);




    
    // // Closing the file
    // fclose(fp);

    // FILE *fp = fopen("output.txt", "w");
    // if(fp == NULL) {
    //     printf("error opening file");
    //     return 1;
    // }

    // int lines = 0;
    // char str[100];

    // printf("Enter how many lines you want to write: ");
    // scanf("%d", &lines);
    // getchar();

    // for (int i = 0; i < lines; i++) {
    //     printf("Enter new line: ");
    //     fgets(str, sizeof(str), stdin);
    //     fprintf(fp, "%s", str);
    // }
    // fclose(fp);
    // set lines, write #lines in output file

    FILE *inputFile = fopen("input.txt", "r");
    if(inputFile == NULL) {
        printf("Error opening the file");
        return 1;
    }

    FILE *outputFile = fopen("output.txt", "w");
        if(outputFile == NULL) {
        printf("Error opening the file");
        fclose(inputFile);
        return 1;
    }

    char line[256];

    while(fgets(line, sizeof(line), inputFile)) {
        fputs(line, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}