/* Write a C program to implement the Fizz buzz game */

#include <stdio.h>

int main() {

  /* TODO: read the value for n and implement the logic of the game here */

  int n; // input

  printf("Enter a value for n: \n");
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {

    if(i % 3 == 0 && i % 5 == 0) {
      printf("fizzbuzz \n");
    } else if (i % 3 == 0) {
      printf("fizz \n");
    } else if (i % 5 == 0) {
      printf("buzz \n");
    } else {
      printf("%d \n", i);
    }

  }

    return 0;
}