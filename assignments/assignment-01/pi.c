#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, i;

	printf("n = ");
	scanf("%d", &n);

	double pi = 0.;
	//TODO
	//add code below

	double x = 1; // value for 16^i

	for (i = 0; i <= n; i++) {
		double term1 = (4.0 / ((8 * i) + 1));
		double term2 = (2.0 / ((8 * i) + 4));
		double term3 = (1.0 / ((8 * i) + 5));
		double term4 = (1.0 / ((8 * i) + 6));
		// broke up - better readable for me 

		double compute = term1 - term2 - term3 - term4;
		pi += compute / x;
		x *= 16; // updating 16^i
	}

		printf("PI = %.10f\n", pi);
	return 0;
}
