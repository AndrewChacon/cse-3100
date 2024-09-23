#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void initVector(IntVector* vec, int cap)
{
  vec->numbers = (int*) malloc(cap * sizeof(int));  // allocate memory for cap 
  vec->size = 0;  // size pointer
  vec->capacity = cap;  // set cap
}

void freeVector(IntVector* vec)
{
  free(vec->numbers);  // Free array memory
  vec->numbers = NULL;  // reset
  vec->size = 0;  // size to 0
  vec->capacity = 0;
}

void expandVector(IntVector* vec)
{
  vec->capacity *= 2;
  vec->numbers = (int*) realloc(vec->numbers, vec->capacity * sizeof(int));
}

void pushBackVector(IntVector* vec, int number)
{
  if (vec->size == vec->capacity) {
    expandVector(vec);  // if vectori s full 
  }
  vec->numbers[vec->size] = number; 
  vec->size++;
}

int popBackVector(IntVector* vec)
{
  assert(vec->size > 0); 
  int number = vec->numbers[vec->size - 1]; 
  vec->size--; 
  return number;  // Return element
}

void pushFrontVector(IntVector* vec, int number)
{
  if (vec->size == vec->capacity) {
    expandVector(vec); 
  }
  memmove(&vec->numbers[1], &vec->numbers[0], vec->size * sizeof(int));
  vec->numbers[0] = number;
  vec->size++; 
}

int popFrontVector(IntVector* vec)
{
  assert(vec->size > 0);
  int number = vec->numbers[0];  // first element
  memmove(&vec->numbers[0], &vec->numbers[1], (vec->size - 1) * sizeof(int));
  vec->size--; 
  return number;  // return first element
}

void swap(IntVector* vec, size_t indexOne, size_t indexTwo)
{
  assert(indexOne < vec->size);
  assert(indexTwo < vec->size);
  int temp = vec->numbers[indexOne];
  vec->numbers[indexOne] = vec->numbers[indexTwo];
  vec->numbers[indexTwo] = temp;
}

void sortVector(IntVector* vec)
{
  for (size_t i = 1; i < vec->size; i++) {
    size_t j = i;
    while (j > 0 && vec->numbers[j - 1] > vec->numbers[j]) {
      swap(vec, j, j - 1); 
      j--;
    }
  }
}

void printVector(IntVector* vec)
{
  printf("(");
  for(size_t i = 0; i < vec->size; i++){
    printf("%d ", vec->numbers[i]);
  }
  printf(")\n");
}

int lengthVector(IntVector* vec)
{
  return vec->size;
}
