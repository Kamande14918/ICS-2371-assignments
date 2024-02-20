#include <stdio.h>
#include <stdlib.h>

char* check_numbers(int num1, int num2) {
    static char result[100];
    int divisible = num1 % num2 == 0;
    int even_odd = num1 % 2 == 0 || num2 % 2 == 0;

    if (divisible && even_odd) {
        sprintf(result, "Both numbers are divisible and even or odd.");
    } else if (divisible) {
        sprintf(result, "Both numbers are divisible.");
    } else if (even_odd) {
        sprintf(result, "Both numbers are even or odd.");
    } else {
        sprintf(result, "Neither number is divisible or even or odd.");
    }

    return result;
}

int main() {
    char ch;
    double num1, num2;
    int num1_int, num2_int;

    while (1) {
        printf("Enter an operator (+, -, *, /), or 'x' to quit: ");
        scanf(" %c", &ch);

        if (ch == 'x')
            exit(0);

        printf("Enter two operands: ");
        scanf("%lf %lf", &num1, &num2);

        // Check if the numbers are integers
        if (num1 == (int)num1 && num2 == (int)num2) {
            num1_int = (int)num1;
            num2_int = (int)num2;
            printf("%s\n", check_numbers(num1_int, num2_int));
        } else {
            printf("Error! Please enter integer numbers.\n");
        }

        switch (ch) {
            case '+':
                printf("%.1lf + %.1lf = %.1lf\n", num1, num2, num1 + num2);
                break;
            case '-':
                printf("%.1lf - %.1lf = %.1lf\n", num1, num2, num1 - num2);
                break;
            case '*':
                printf("%.1lf * %.1lf = %.1lf\n", num1, num2, num1 * num2);
                break;
            case '/':
                if (num2 == 0) {
                    printf("Error: Division by zero is not allowed.\n");
                } else {
                    printf("%.1lf / %.1lf = %.1lf\n", num1, num2, num1 / num2);
                }
                break;
            default:
                printf("Error! Please enter a valid operator.\n");
        }
        printf("\n");
    }

    return 0;
}
