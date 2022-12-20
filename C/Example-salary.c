#include<stdio.h>

int main()
{
    //declaration
    float salary, rate, new_sal,tot_sal,tot_raise=0,new_tot_sal=0,raise;

    //input

    printf("\t\t\t Salary \t Rate \t Raise \t        New Salary \n ");
    printf("--------------------------------------------------------------------------------\n");

    printf("Salary: ");
    scanf("%f",&salary);



    while (salary>0)
    {
        //determine the rate based on input
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

        //print output
        printf("\t\t\t %.2f \t %.2f \t %.2f \t%.2f\n",salary,rate,raise,new_sal);

        //ask for input again
        printf("Salary: ");
        scanf("%f",&salary);

    }

    //print final sums
     printf("--------------------------------------------------------------------------------\n");
     printf("\t\tTotal \t%.2f \t\t %.2f \t %.2f",tot_sal,tot_raise,new_tot_sal);


     return 0;
}
