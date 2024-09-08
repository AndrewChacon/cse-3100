#include <stdio.h>

int main() {
    printf("Hello World!\n");

    // september 3rd

    // read indefinte amount of values from user
    // compute running total and running average
    // stop when control c + control d

    // 3 variables

    // PROBLEM #1

    // double num, total=0, avg=0;
    // int count = 0;

    // printf("Enter an input: ");

    // while(scanf("%lf", &num) == 1){
    //     count++;
    //     total += num;
    //     printf("\n\nTotal: %lf  Average: %lf\n", total, (total / num));
    //     printf("Enter an input: ");
    // }

    // PROBLEM #2

    // printf("Enter your grade: ");
    // int grade = 100;

    // if(grade <= 59) {
    //     printf("Your grade is a F\n");
    // }
    // else if (grade >= 60 && grade <= 69) {
    //     printf("Your grade is a D\n");
    // } else if (grade >= 70 && grade <= 79) {
    //     printf("Your grade is a C\n");
    // } else if (grade >= 80 && grade <= 89) {
    //     printf("Your grade is a B\n");
    // } else if (grade >= 90 && grade <= 100) {
    //     printf("Your grade is a A\n");
    // } else {
    //     printf("Invalid input for a grade.\n");
    // }

    /*
    90-100 - a
    80-89 - b
    70-79 - c
    60-69 - d
    0-59 - f
    */

    // PROBLEM #3

    // char operator;
    // double num1, num2, result;

    // printf("Select an operation (+, -, *, /): ");
    // scanf("%c", &operator);

    // printf("Enter two numbers: ");
    // scanf("%lf %lf", &num1, &num2);

    // switch (operator)
    // {
    // case '+':
    //     result = num1 + num2;
    //     printf("%lf + %lf = %lf\n", num1, num2, result);
    //     break;
    // case '-':
    //     result = num1 - num2;
    //     printf("%lf - %lf = %lf\n", num1, num2, result);
    //     break;
    // case '*':
    //     result = num1 * num2;
    //     printf("%lf * %lf = %lf\n", num1, num2, result);
    //     break;
    // case '/':
    //     result = num1 / num2;
    //     if(num2 == 0) {
    //         printf("Invalid input for num2, cannot divide by 0 number.\n");
    //         break;
    //     }
    //     printf("%lf / %lf = %lf\n", num1, num2, result);
    //     break;
    // default:
    //     printf("Error: Invalid operator.\n");
    //     break;
    // }

    // september 5th

    // PROBLEM #1
    // function to compute halleys sequence
    // double x, epsillion;

    // prinf("Enter the value x: ");
    // scanf("%lf", &x);

    // printf("Enter the type epsillon: ");
    // scanf("%lf", &epsillion);

    // double answer = halleys(x, epsillion);
    // printf("Result: %lf", answer);


    // PROBLEM #2

    /* 
    n discs, make disks from a to c - tower of hanoi problem
    3 arrays
    pushing the stack

    using recurssion
    */

    int diskNumber;

    printf("Enter the number of disks: ");
    scanf("%d", diskNumber);

    // using the move function calculate the number of moves needed
    // print the result

    printf("");

    /*
    1 move - a to c

    1 move

    */

    return 0;
}

int move(int n, char a, char b, char c) {
    if (n == 1) {
        printf("Moved 1 Disk from A to C");
        return;
    }
}

// double halleys(double x, double epsillion) {
//     // int guess = x / 2;
//     // while(fabs(guess * guess - x) > epsillion) {

//     // }

//     double guess = x, prev_s = 0;
//     guess = prev_s * (prev_s * prev_s + 3 * x) / (3 * prev_s * prev_s + x);

//     while(fabs(guess - prev_s) >= epsillion) {
//         prev_s = guess;
//         guess = prev_s * (prev_s * prev_s + 3 * x) / (3 * prev_s * prev_s + x);
//     }
//     return guess;

//     return 0;
// }