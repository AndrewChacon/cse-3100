#include <stdio.h>

int main() {
    printf("Hello World!\n");

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

    char operator;
    double num1, num2, result;

    printf("Select an operation (+, -, *, /): ");
    scanf("%c", &operator);

    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);

    switch (operator)
    {
    case '+':
        result = num1 + num2;
        printf("%lf + %lf = %lf\n", num1, num2, result);
        break;
    case '-':
        result = num1 - num2;
        printf("%lf - %lf = %lf\n", num1, num2, result);
        break;
    case '*':
        result = num1 * num2;
        printf("%lf * %lf = %lf\n", num1, num2, result);
        break;
    case '/':
        result = num1 / num2;
        if(num2 == 0) {
            printf("Invalid input for num2, cannot divide by 0 number.\n");
        }
        printf("%lf / %lf = %lf\n", num1, num2, result);
        break;
    default:
        printf("Error: Invalid operator.\n");
        break;
    }

    return 0;
}