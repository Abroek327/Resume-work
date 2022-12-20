#include<stdio.h>

int main()
{
    //declaration
    float salary, rate, new_sal,tot_sal,tot_raise=0,new_tot_sal=0,raise;
    int want;

    //input

    printf("How many salaries do you want to enter ");
    scanf("%d",&want);


    //first two rows of the display
    printf("\t\t\t Salary \t Rate \t Raise \t        New Salary \n ");
    printf("--------------------------------------------------------------------------\n");

    for (int i=0;i<want;i++)
    {
        //ask for salary
        printf("Salary: ");
        scanf("%f",&salary);

        //determine the rate
        if (salary>=0&&salary<=30000)
            rate=7;
        if (salary>30000&&salary<=40000)
            rate=5.5;
        if (salary>40000)
            rate=4;

        //calculations
        raise=salary*rate/100;
        new_sal=salary+raise;
        new_tot_sal+=new_sal;
        tot_raise+=raise;
        tot_sal+=salary;

        //display calculated values based on salary input
        printf("\t\t\t %.2f \t %.2f \t %.2f \t%.2f\n",salary,rate,raise,new_sal);

    }

     //display the totals
     printf("--------------------------------------------------------------------------\n");
     printf("\t\tTotal \t%.2f \t\t %.2f \t%.2f",tot_sal,tot_raise,new_tot_sal);


return 0;
}
