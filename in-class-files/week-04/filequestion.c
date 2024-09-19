#include <stdio.h>

int main() {
    FILE *fp1, *fp2;
    char str[100];

    // open input.txt source file, copy its content into output.txt
    // use fgets and fprintf to read and write the inpit
    // close files when ur done using them

    // fp1 = open("input.txt", "r");
    // if(fp1 == NULL) {
    //     // error opening file
    //     return 1;
    // }

    // fp2 = open("output.txt", "w");
    // if(fp2 == NULL) {
    //     // error opening file
    //     fclose(fp2);
    //     return 1;
    // }
    
    // read from input.txt
    // write to output.txt
    // while(fgets(str, sizeof(str), fp1) != NULL) {
    //     fprintf(fp2, "%s", str);
    // }

    // fclose(fp1);
    // fclose(fp2);

    fp1 = fopen("input.txt", "r");
    if(fp1 == NULL) {
        return 1;
    }
    // open and read input.txt

    fp2 = fopen("output.txt", "w");
    if(fp2 == NULL) {
        return 1;
    }
    // open and write output.txt

    while(fgets(str, 100, fp1) != NULL) {
        fprintf(fp2, "%s", str);
    }
    // write from input.txt to output.txt

    fclose(fp1);
    fclose(fp2);
    // close files when done working with them

    return 0;
}

// null pointer
// segmentation fault - access memory that isnt mine
// int *ptr = NULL;
// *ptr = 10;

// run it to see if it works first 
// variable, stack, life time is life time of the function 

// build system - makefiles
