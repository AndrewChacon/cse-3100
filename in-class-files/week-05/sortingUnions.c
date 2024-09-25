/* Write a program to sort unions using qsort */

#include <stdio.h> 
#include <stdlib.h>

#define CH 0
#define UINT 1
#define INT 2

typedef union Values {
  char ch;
  unsigned int uint;
  int integer;
} Values;

typedef struct Variant {
  int tag;
  Values val;
} Variant; 

/*
vairent
  - int tag
  - Values val
      - ch
      - uint
      - int

set union -> tag,
*/

/* This function sets the tag as dType and the correct value field of the Variant */ 
int setUnion(Variant* tagged_union, int dType, void* value) {
  tagged_union->tag = dType;
  switch (dType)
  {
  case CH:
    tagged_union->val.ch = *(char *)value;
    break;
  case UINT:
    tagged_union->val.uint = *(unsigned int *)value;
    break;
  case INT:
    tagged_union->val.integer = *(int *)value;
    break;
  default:
    break;
    }
}

/* This function retrieves the correct value field of the Variant. Note that the function should return a void* pointer to the value. Call exit(-1) in case of an error. */
void* getUnion(Variant* tagged_union) {
    // check for int, char, unsigned switch case
    switch (tagged_union->tag)
    {
    case CH:
      return &tagged_union->val.ch;
      break;
    case UINT:
      return &tagged_union->val.uint;
      break;
    case INT:
      return &tagged_union->val.integer;
      break;
    default:
      exit(-1);
      break;
    }
}
  
/* This function prints the correct value field of the Variant. Make use of the getUnion function. */
void printUnion(Variant* tagged_union) {

    switch (tagged_union->tag)
    {
    case CH:
      printf("%c", *(char*)getUnion(tagged_union));
      break;
    case UINT:
        printf("%u", *(unsigned int*)getUnion(tagged_union));
        break;
    case INT:
        printf("%d", *(int*)getUnion(tagged_union));
        break;
    default:
        break;
    }
}

/* This function compares the value within two tagged unions that have the same tag type. 
 * Return a negative integer if union 1 is smaller than union 2, zero if they are equal and a positive integer otherwise.
 * Note that compUnion compares int by their magnitude only. So, -7 is greater than 5. 
 * Call exit(-1) in case of an error. */
int compUnion(const void* tagged_union1, const void* tagged_union2) {

}

/* This function sorts an array of n tagged unions using qsort. */
void sortUnion(Variant* tUnionArray, int n) {
  printf("Printing Unsorted Array:\n[");
  for(int i = 0; i<n-1; i++) {
    printUnion(&tUnionArray[i]);
	  printf(", ");
  }
  printUnion(&tUnionArray[n-1]);
  printf("]\n\n");

  printf("Sorting...\n\n");
  qsort(tUnionArray, n, sizeof(tUnionArray[n-1]), compUnion); //qsort takes pointer to the function compUnion

  printf("Printing Sorted Array:\n[");
  for(int i = 0; i<n-1; i++) {
    printUnion(&tUnionArray[i]);
	  printf(", ");
  }
  printUnion(&tUnionArray[n-1]);
  printf("]\n");
}

int main() { 
  int arr[] = {-2, 0, 4, -9, 5, -7}; 
  int n = sizeof(arr)/sizeof(arr[0]);   //determine number of elements in arr

  /* Initialize array of Variants and populate with values in arr */
  Variant tUnionArray[n];
  for(int i=0; i<n; i++) {
	  setUnion(&tUnionArray[i], INT, (void*)&arr[i]);
  }
  
  printf("Sort unions with integers (magnitude only) using sortUnion:\n");
  sortUnion(tUnionArray, n);

  return 0;
}

/*
as many practice problems
linked lists heaps binary search trees

*/