#include <stdio.h>

int main(){

    char  operator;
    double num1;
    double num2;
    double result;

    printf("\nEnter an operator for addition (+) subtration (-) multiplication (*) division (/): ");
    scanf("%c", &operator);

    switch (operator){
        case '+':
            printf("Enter numer 1: ");
            scanf("%lf", &num1);
            printf("Enter numer 2: ");
            scanf("%lf", &num2);
            result = num1 + num2;
            printf("\nThe result is %.3lf.", result);
            break;

        case '-':
            printf("Enter numer 1: ");
            scanf("%lf", &num1);
            printf("Enter numer 2: ");
            scanf("%lf", &num2);
            result = num1 - num2;
            printf("\nThe result is %.3lf.", result);
            break;

        case '*':
            printf("Enter numer 1: ");
            scanf("%lf", &num1);
            printf("Enter numer 2: ");
            scanf("%lf", &num2);
            result = num1 * num2;
            printf("\nThe result is %.3lf.", result);
            break;

        case '/':
            printf("Enter numer 1: ");
            scanf("%lf", &num1);
            printf("Enter numer 2: ");
            scanf("%lf", &num2);
            result = num1 / num2;
            printf("\nThe result is %.3lf.", result);
            break;

        default:
            printf("\n%c is not valid. Please enter a valid operator.", operator);
            break;
    }

    return 0;
}