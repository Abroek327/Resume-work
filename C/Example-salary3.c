#include<stdio.h>
#define SIZE 7

//create a struct for employee information
typedef struct
{
    char names[7][25];
    float sal, raise, rate,nsal;

}employee;

//prototyping
void load(employee e[], int);
void getrate(employee e[], int);
void sort(employee e[], int);
void calc(employee e[], int, float *, float *, float *);
void prnt(employee e[], int, float, float, float);
void savebin(employee e[], int , float, float, float);
void getbin(employee e[], int , float, float, float);

int main()
{
    //create an array of struct
    employee e[SIZE];
    //create the total variables (not part of struct so they could be initialized to 0)
    float tnsal, tsal, traise;

    //call the functions
    load(e,SIZE);
    getrate(e,SIZE);

    sort(e,SIZE);
    calc(e,SIZE, &tsal, &tnsal, &traise);

    savebin(e, SIZE, tsal, tnsal, traise);
    getbin(e, SIZE, tsal, tnsal, traise);

    prnt(e,SIZE, tsal, tnsal, traise);


}

void load(employee e[], int n)
{
    //get employee data using a while loop
    int count=0;
    while (count<n)
    {
        printf("Enter employee name: ");
        gets(e[count].names);

        printf("Enter salary: ");
        scanf("%f",&e[count].sal);

        count++;
        getchar();
    }
}

void getrate(employee e[], int n)
{
    //determine the rate based on salary
    for (int i=0; i<n; i++)
    {
        if(e[i].sal < 30000)
            e[i].rate=.07;
        else if (e[i].sal >= 30000 && e[i].sal <= 40000 )
             e[i].rate=.055;
        else if (e[i].sal > 40000)
            e[i].rate=.04;


    }
}

void sort(employee e[], int n)
{
    int i, j;
    //create a temporary struct for the swap
   employee t[SIZE];

   //organize the array of struct based on name
   for(i=0;i<n-1;i++)
   {
       for(j=0;j<n-1;j++)
       {
           if (e[j].names < e[j+1].names)
           {
               t[j]=e[j];
               e[j]=e[j+1];
               e[j+1]=t[j];
           }
       }
   }
}

void calc(employee e[], int n, float *tsal, float *tnsal, float *traise)
{
    //initialize the total values
     *tsal=0;
     *tnsal=0;
     *traise=0;
     //perform the calculations
    for (int i=0; i<n; i++)
    {
        e[i].raise=e[i].sal*e[i].rate;
        *tsal+=e[i].sal;
        *traise+=e[i].raise;
        e[i].nsal=e[i].raise+e[i].sal;
        *tnsal+=e[i].nsal;

    }
}

void savebin(employee e[], int n, float tsal, float tnsal, float traise)
{
    //save the data to a bin file
    FILE *f;

    f=fopen("C:\\School\\CS36\\Homework\\Files\\Employee.bin","wb");
    fwrite(&e,sizeof(e[0]),n,f);
    fwrite(&tsal,1,n,f);
    fwrite(&tnsal,1,n,f);
    fwrite(&traise,1,n,f);
    fclose(f);

}

void getbin(employee e[], int n, float tsal, float tnsal, float traise)
{
    //pull the information from the bin file
    FILE *f;
    f=fopen("C:\\School\\CS36\\Homework\\Files\\Employee.bin","rb");
    fread(&e,sizeof(e[0]),n,f);
    fread(&tsal,1,n,f);
    fread(&tnsal,1,n,f);
    fread(&traise,1,n,f);
    fclose(f);
}





void prnt(employee e[], int n, float tsal, float tnsal, float traise)
{
    //display employee information
    printf("Name\tSalary\t\tRate %\tRaise\t\tNew Salary\n");
    for(int i=0; i<n; i++)
    {
      printf("%s\t%.2f\t%.2f\t%.2f\t\t%.2f\n",e[i].names,e[i].sal,e[i].rate*100,e[i].raise,e[i].nsal);

    }
    printf("Total\t%.2f\t\t%.2f\t%.2f",tsal,traise,tnsal);

}

