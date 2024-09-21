#include <stdio.h>
#include <stdbool.h>

int main() {
    // file handle - reff to the file

    FILE *fh_output;
    fh_output = fopen("io.txt", "w"); // file name and mode

    // fputs("abc", fh_output);
    // fputs("123\n", fh_output);
    // include \n newlines manually

    //fputs("A string\n", fh_output); // writing to file

    //int data = 5;
    //fprintf(fh_output, "data: %d\n", data);
    // placeholders with vars, fputs cannot do that 

    //fclose(fh_output); // close files when done using them
    // cat - output contents of the file
    // cat io.txt -> prints txt file contents

    // use a loop to fill file with contents

    // for (int i = 0; i < 10; i++) {
    //     fprintf(fh_output, "%d\n", i);
    // }
    int input = 0;
    while (true)
    {
        printf("Enter # (-1 quits): ");
        scanf("%d", &input);
        if(input == -1) {
            break;
        } else {
            fprintf(fh_output, "%d\n", input);
        }
    }

        /*
        mode: a (append)
        opens up file - doesnt overwrite, adds to existing content
        */

        return 0;
}