#include <stdio.h>
#include <stdlib.h>

// typedef struct Mono {
//     int coef;
//     int deg;
//     struct Mono *next;
// } Mono;

// Mono* ptr = (Mono*)malloc(sizeof(Mono));

// union type
// varients - values of multiple types
// one at a time

typedef struct taggedValue {
    int tag;
    union uTag {
        int iVal;
        float fVal;
        char *sVal;
    } u;
} UType;

#define INTEGER_TAG 0
#define FLOAT_TAG 1
#define STRING_TAG 2

void printUType(UType* x) {
    switch (x->tag)
    {
    case INTEGER_TAG:
        printf("%d\n", x->u.iVal);
        break;
    case FLOAT_TAG:
        printf("%f\n", x->u.fVal);
        break;
    case STRING_TAG:
        printf("%s\n", x->u.sVal);
        break;
    }
}

UType makeUTFloat(float v) {
    UType rv;
    rv.tag = FLOAT_TAG;
    rv.u.fVal = v;
    return rv;
}

UType makeUTString(char* s) {
    UType rv;
    rv.tag = STRING_TAG;
    rv.u.sVal = s;
    return rv;
}

// UType x;
// x.tag = INTEGER_TAG;
// x.u.iVal = 5;
// printUType(&x);

// bit fields
// mechanism used to optimize storage in a structure

// struct Census {      12 bytes
//     int age;
//     int gender;
//     int species;
// }                    use bits 7,2,3

// struct Census {
//     short age : 7;
//     short gender : 2;
//     short species : 3;  // significant reduction in memory 
// };

// FUNCTION POINTERS




int main()
{
    UType x = makeUTFloat(5.25);
    printUType(&x);
    UType y = makeUTString("Hello World!"); // static string
    printUType(&y);
    return 0;
}
