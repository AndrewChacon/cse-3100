#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;

	printf("n = ");
	scanf("%d", &n);

	int m = n;
	//TODO
	//add code below
	
	while(n != 1 && n != 4) {

		int sum = 0;
		int temp = n;

		while(temp > 0) { // the sum of squares 
			int digit = temp % 10;
			sum += digit * digit;
			temp = temp / 10;
		}
		n = sum; // replace n with the sum of all squares 
		printf("%d\n", n);
	}

	if(n==1) printf("%d is a happy number.\n", m);
	else printf("%d is NOT a happy number.\n", m);
	return 0;
}
