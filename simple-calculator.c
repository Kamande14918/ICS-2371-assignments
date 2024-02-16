//Kamande Kennedy Kamau
//Reg: ENE212-0169/2021
//Simple C Calculator
#include <stdio.h>
//Simple addition and subtraction calculator
int main()
{  
    double num1,num2,sum,diff;        
    printf("Please enter two numbers:\n");
    scanf("%lf %lf", &num1, &num2);
    sum=num1+num2;
    diff=num1-num2;
    printf("Summation  of the two numbers is :%f\n",sum);
    printf("Difference between the two numbers is: %f\n",diff);
    printf("Summation and Difference of the two numbers are:%f\t %f\t", sum, diff);
    return 0;
}
