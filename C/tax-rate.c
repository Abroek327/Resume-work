#include<stdio.h>

//prototyping
int getStatus();
float getTI();
int getRate(int, float);
float calc(int, float, int);
void prnt(float);

int main()
{
    //declaration
    int status, rate;
    float TI, tax;

    //call the getStatus function
    status=getStatus();

    //catch any unwanted input
    if(status>5)
    {
        printf("Invalid input\n");
        status=getStatus();
    }
    //use the status to run the while loop
    while (status<5)
    {
        //call the functions
        TI=getTI();
        rate=getRate(status, TI);
        tax=calc(status, TI, rate);

        //display the output (putting it in its own function seemed pointless)
        printf("You owe $%.2f in taxes\n\n",tax);

        //check if the user wants to exit or go again
        status=getStatus();

        //catch any unwanted input (again)
        if(status>5)
        {
            printf("Invalid input\n");
            status=getStatus();
        }

    }

}


int getStatus()
{
    int status;

    //display the menu and get user input
    printf("Enter your filing status\n");
    printf("1 for single\n");
    printf("2 for Married filing jointly\n");
    printf("3 for Married filing separately\n");
    printf("4 for Head of Household\n");
    printf("5 Exit\n");
    scanf("%d",&status);

    return status;
}


float getTI()
{
    float TI;

    //get user input
    printf("Enter your taxable income ");
    scanf("%f",&TI);
    return TI;
}


int getRate(int stat, float TI)
{
    //I hope you like if statements
    //CAUSE I SURE DO
    float rate;

    //determine rate if they entered status 1
    if (stat==1)
    {
        if(TI<=24000)
            rate=15;

        if(TI>24000 && TI<=58000)
            rate=28;
        if(TI>58000 && TI<=121300)
            rate=31;
        if(TI>121300 && TI<=263750)
            rate=36;
        if(TI>263750)
            rate=39.6;

    }

    //determine rate if they entered status 2
    if (stat==2)
    {
        if(TI<=40100)
            rate=15;
        if(TI>40100 && TI<=96900)
            rate=28;
        if(TI>96900 && TI<=147700)
            rate=31;
        if(TI>147700 && TI<=263750)
            rate=36;
        if(TI>263750)
            rate=39.6;
    }

    //determine rate if they entered status 3
    if (stat==3)
    {
        if(TI<=20050)
            rate=15;
        if(TI>20050 && TI<=48450)
            rate=28;
        if(TI>48450 && TI<=73850)
            rate=31;
        if(TI>73850 && TI <=131875)
            rate=36;
        if(TI>121875)
            rate=39.6;
    }

    //determine rate they entered status 4
    if (stat==4)
    {
        if(TI<+32150)
            rate=15;
        if(TI>32150 && TI<=83050)
            rate=28;
        if(TI>83050 && TI<=134500)
            rate=31;
        if(TI>124500 && TI<=263750)
            rate=36;
        if(TI>263750)
            rate=39.6;
    }


    return rate;
}


float calc(int stat, float TI, int rate)
{
    float tax, rrate;

    //calculate the tax based on status and TI
    if(stat==1)
    {
        //I only did this cause writing out the whole expression was annoying
        rrate=rate/(float)100;

       switch(rate)
       {
       case 15:
        tax=rrate*TI;
        break;
       case 28:
        tax=3600+(TI-24000)*rrate;
        break;
       case 31:
        tax=13162+(TI-58150)*rrate;
        break;
       case 36:
        tax=32738.50+(TI-121300)*rrate;
        break;
       case 39:
        tax=84020.50+(TI-263750)*39.6/(float)100;
        break;
       }


    }

    //calculate the tax if user entered status 2
    if(stat==2)
    {
        rrate=rate/(float)100;
        switch(rate)
        {
        case 15:
            tax=TI*rrate;
            break;
        case 28:
            tax=6015+(TI-40100)*rrate;
            break;
        case 31:
            tax=21919+(TI-96900)*rrate;
            break;
        case 36:
            tax=37667+(TI-147700)*rrate;
            break;
        case 39:
            tax=79445+(TI-263750)*39.6/(float)100;
            break;
        }
    }

    //calculate the tax if user entered status 3
    if(stat==3)
    {
        rrate=rate/(float)100;
        switch (rate)
        {
        case 15:
            tax=TI*rrate;
            break;
        case 28:
            tax=3007.50+(TI-20050)*rrate;
            break;
        case 31:
            tax=10959.50+(TI-48450)*rrate;
            break;
        case 36:
            tax=18833+(TI-73850)*rrate;
            break;
        case 39:
            tax=39722.50+(TI-131875)*39.6/(float)100;
            break;
        }
    }

    //calculate the tax if user entered status 4
    if(stat==4)
    {
        rrate=rate/(float)100;
        switch(rate)
        {
        case 15:
            tax=TI*rrate;
            break;
        case 28:
            tax=4822.50+(TI-32150)*rrate;
            break;
        case 31:
            tax=19074.50+(TI-83050)*rrate;
            break;
        case 36:
            tax=35074+(TI-134500)*rrate;
            break;
        case 39:
            tax=81554+(TI-263750)*39.6/(float)100;
        }
    }
    return tax;
}
