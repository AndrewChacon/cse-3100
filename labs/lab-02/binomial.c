/* Write a program to compute the binomial. */

#include <stdio.h>

/* This function should recursively compute the binomial (n, k) and return its value. */
int binomial(int n, int k){
  /* TODO: implement the function */
  
  // check for base case
  if(k == 0 || k == n) { // 1 way to choose from a set 
    return 1;
  }

  return binomial(n - 1, k) + binomial(n - 1, k - 1);
}

int main(int argc, char* argv[]){

  /* TODO: Take n and k as input from the user. These values are of type int.
   * Call the binomial function and print the result. 
   */

  int n, k, answer;

  printf("Enter n: ");
  scanf("%d", &n);

  printf("Enter k: ");
  scanf("%d", &k);

  answer = binomial(n, k);
  printf("%d choose %d = %d\n", n, k, answer);

  return 0;
}
