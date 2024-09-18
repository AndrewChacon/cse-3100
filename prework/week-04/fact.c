#include <stdio.h> 
#include <stdlib.h>

int fact(int n);

int main(int argc, char* argv[]) {

    /*
    basic io in c language
    3 strings
    standard input = 0
    standard output = 1
    standard error = 2

    unbuffered - open close read write - file descriptors
    buffered - manipulating file pointers

    getchar / putchar

    getchar returns a read in
    putchar returns a read out

    int fputc(int c, FILE *stream);
    int putc(int c, FILE * stream);

    fopen - fclose - blocks of buffered memory 

    */

    // int c = fgetc(stdin);
    // while(!feof(stdin)) {
    //     fputc(c, stdout);
    //     c = fgetc(stdin);
    // }

    /*
    DEBUGGING
    -g infront of compile will include debugger information
     gbd the GNU debugger   

    */

    // if(argc < 2) {
    //     printf("usage is: ");
    //     return 1;
    // }
    // int n = atoi(argv[1]);
    // int r = fact(n);
    // printf("Factorial(%d) = %d\n", n, r);

    // memory debugging - memory management
    

    return 0;
}

// int fact(int n) {
//     if (n == 0) {
//         return 1;
//     } else {
//         return n * fact(n - 1);
//     }
// }