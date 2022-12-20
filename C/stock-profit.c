#include<stdio.h>

int main()
{
    //declaration
    char name[15];
    int sharenum;
    float bprice, cprice, yfee,inital,current,profit;

    //input
    printf("Enter the name of the stock: ");
    gets(name);

    printf("Enter Number of shares ");
    scanf("%d",&sharenum);

    printf("Enter buy price ");
    scanf("%f",&bprice);

    printf("Enter current price ");
    scanf("%f",&cprice);

    printf("Enter yearly fees ");
    scanf("%f",&yfee);

    fflush(stdin);

    //calculations
    inital=sharenum*bprice;
    current=sharenum*cprice;
    profit=current-inital-yfee;

    //output
    printf("The stock name   %s\n",name);
    printf("Initial cost:    $ %.2f\n",inital);
    printf("Current cost:    $ %.2f\n",current);
    printf("profit:          $  %.2f\n",profit);



}
