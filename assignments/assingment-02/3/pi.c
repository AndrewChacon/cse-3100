#include <stdio.h>
#include <assert.h>

double leibnizRecurrent(int n) {
  if (n == 0) {
    return 1.0;  // base case
  } else {
    return (n % 2 == 0 ? 1.0 : -1.0) / (2.0 * n + 1) + leibnizRecurrent(n - 1);
  }
}

double leibnizIterative(int n) {
  double sum = 0.0;
  for (int i = 0; i <= n; i++) {
    sum += (i % 2 == 0 ? 1.0 : -1.0) / (2.0 * i + 1);
  }
    return sum;
}

int main(int argc, char* argv[]){
  if(argc != 3){
    printf("Usage: ./pi <mode> <n>, where <mode> is 1 for recurrent version, and 2 is for the iterative version, and n is the upper bound of the summation.\n");
  }else{
    int mode = 0, n = 0;
    double pi = 0;
    assert(sscanf(argv[1], "%d", &mode) == 1);
    assert(sscanf(argv[2], "%d", &n) == 1);
    assert(mode == 1 || mode == 2);
    assert(n >= 0);
    if(mode == 1){
      pi = 4*leibnizRecurrent(n);
    }else{
      pi = 4*leibnizIterative(n);
    }
    printf("PI: %f\n", pi);
  }
  return 0;
}
