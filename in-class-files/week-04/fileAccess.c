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
    fclose(fh_output);


    /*
    mode: a (append)
    opens up file - doesnt overwrite, adds to existing content
    */

   // reading contents of a file

    FILE *fh_input;
    fh_input = fopen("io.txt", "r");
    // open file and set mode to r for read  

    int fIn = 0;
    int nums[100];
    int lines = 0;

    // fscanf(fh_input, "%d", &fIn); // scan data from
    // reading first int from file
    // printf("Number: %d\n", fIn);
    // fclose(fh_input);

    // keep calling fscanf until it reaches end of file 
    // store value of each line into array
    while(fscanf(fh_input, "%d", &fIn) != EOF) {
        printf("File Line %d: %d\n", lines + 1, fIn);
        nums[lines] = fIn;
        lines++; // next line
    }
 

    int total = 0;
    for (int i = 0; i < lines; i++) {
        total += nums[i];
    }

    double avg = (float)total / (float)lines;

    printf("total: %d\n", total);
    printf("average: %.2lf\n", avg);

    fclose(fh_input);

    fh_input = fopen("in.txt", "r");

    char buffer[256];
    fgets(buffer, 256, fh_input);
    // array for input, size of buffer, file read from

    printf("Buffer: %s\n", buffer);
    // reads in content of file as a string
    // store it into buffer as string until reached size

    fclose(fh_input);

    return 0;
}