#include<stdio.h>

int main()
{
    int amount,twent,ten,five,one;
    printf("Enter a dollar amount: ");
    scanf("%d",&amount);

    twent=amount/20;
    ten=(amount-20*twent)/10;
    five=(amount-(10*ten+20*twent))/5;
    one=(amount-(20*twent+10*ten+5*five));


    printf("$20 bills: %d\n",twent);
    printf("$10 bills: %d\n",ten);
    printf("$5 bills: %d\n",five);
    printf("$1 bills: %d\n",one);



}
