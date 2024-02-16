#include <stdio.h>

// Function to add two numbers
double add(double num1, double num2)
{
    return num1 + num2;
}

// Function to subtract two numbers
double subtract(double num1, double num2)
{
    return num1 - num2;
}

int main()
{  
    double num1, num2, sum, diff;
    
    printf("Please enter two numbers:\n");
    scanf("%lf %lf", &num1, &num2);
    
    sum = add(num1, num2);
    diff = subtract(num1, num2);
    
    printf("Summation  of the two numbers is :%f\n", sum);
    printf("Difference between the two numbers is: %f\n", diff);
    printf("Summation and Difference of the two numbers are:%f\t %f\t", sum, diff);
    
    return 0;
}
