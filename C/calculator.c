#include<stdio.h>

int main(void)
{
    //declaration
    double num1=0.0;
    double num2=0.0;
    double add, sub, multi,divi;
    int mod;
    char operation;

    //input
    printf("Enter the calculation ");
    scanf("%lf %c %lf",&num1,&operation,&num2);

    //processing
    add=num1+num2;
    sub=num1-num2;
    multi=num1*num2;
    divi=num1/num2;
    mod=(int)num1%(int)num2;


    //switch statement
    switch(operation)
    {
        case '+':printf("=%lf",add);
            break;
        case '-':printf("=%lf",sub);
            break;
        case '*': printf("=%lf",multi);
            break;
        case '/': printf("=%lf",divi);
            break;
        case'%': printf("=%d",mod);
            break;
        default: printf("Invalid input");
    }
}

