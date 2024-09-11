/* Write a C program to print a 2-D identity matrix */

#include <stdio.h>
#include <stdlib.h>

void printMat(int n, int** x) {
	for(int i=0; i<n;i++) {
		for(int j=0;j<n;j++) {
			printf("%d ", x[i][j]);
		}
		printf("\n");
	}
	return;
}

int main() {
	int n = 4;

	int** m2 = (int**)malloc(sizeof(int*)*n);
	
	for(int i=0; i< n; i++) {
		m2[i] = (int*)calloc(n, sizeof(int));
		m2[i][i] = 1;
	}

	printMat(n, m2);

	for(int i=0; i< n; i++) {
		free(m2[i]);	
	}

	free(m2);

	return 0;
}
