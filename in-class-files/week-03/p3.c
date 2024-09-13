/* Write a C program to print a 2-D identity matrix */

#include <stdio.h>

void printMat(int n, int x[n][n]) {
	/*TODO: print the matrix stored in x */
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%i ", x[i][j]);
		}
		printf("\n");
	}

		return;
}

int main() {
	int imatrix[3][3] = {{1,0,0}, {0,1,0}, {0,0,1}};
	printMat(3, imatrix);
	return 0;
}
