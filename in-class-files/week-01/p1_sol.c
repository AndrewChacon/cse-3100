/*
 * Calculate and print the area of a circle with radius r, where r is read from the user
*/

#include <stdio.h>

int main(int argc, char* argv[]) {
    float r, area;

    printf("Enter the radius r: ");
    scanf("%f", &r);
    
    area = 3.14 * r * r;
    printf("Area of a circle with radius %.2f is %.2f\n", r, area);

    return 0;
}