#include <stdio.h>

double approxLog(double a, int n) {
  double deltaX = (a - 1) / n;
  double sum = 0.0;
  for (int k = 1; k <= n; k++) {
    double x_k_minus_1 = 1 + (k - 1) * deltaX;
    double x_k = 1 + k * deltaX;
    sum += 0.5 * (1.0 / x_k_minus_1 + 1.0 / x_k) * deltaX;
  }
  return sum;
}

int main(int argc, char* argv[])
{
  double a;
  int n;
  printf("Enter a: ");
  scanf("%lf", &a);
  printf("Enter n: ");
  scanf("%d", &n);
  double logarithm = approxLog(a, n);
  printf("Natural logarithm: %lf\n", logarithm);
  return 0;
}
