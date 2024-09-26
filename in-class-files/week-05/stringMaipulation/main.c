#include <stdio.h>

int main() {
    char str[] = "Program";
    printf("%s", str);



    return 0;
}


// hamming distane question
// write down what i have to do - put the doc away
/*
compare two strings 
difference of 2 for hamming distance 

int length 1 = str len s1
int length 2 = str len s2

if len1 != len2 -> throw an error

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int optimizedHD(char *s1, char *s2) {
    // int hd = (strlen(s1) != strlen(s2) ? 1 : 0);

    // for(int i = 0; i < strlen(s1) || strlen(s2); i++) {

    // }

    int hd = 0;
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    
}