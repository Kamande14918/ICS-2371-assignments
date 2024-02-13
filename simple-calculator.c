// Kamande Kamau
// ENE212-0169/2021

// Simple C Calculator
#include <stdio.h>

int main(){
    double num1,num2,sum,diff;
    printf("Please enter two numbers\n");
    scanf("%lf,%lf",&num1,&num2);
    sum=num1 + num2;
    diff=num1-num2;
    printf("Sum of the two numbers is:\n",sum);
    printf("Difference of the two numbers is:\n",diff);
    printf("Summation and Difference of the two numbers are:%f\t%f\t",sum,diff);

}
