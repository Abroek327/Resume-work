#include<stdio.h>
//these are for the RNG
#include<stdlib.h>
#include<time.h>

//prototyping
int bigger(int);
int smaller(int);
int user();
int compNum();
void win();

int main()
{
    int num,guess;

    //generate the random number and allow the user to guess
    num=compNum();
    guess=user();


    //call the bigger/smaller functions depending on user input
    if (guess<num)
       guess=smaller(num);
    else if (guess>num)
        guess=bigger(num);

    //tell the user they won
    else if (guess==num)
        win();
}

int compNum()
{
    //praise RNGeus (Generate the random number using time)
     int num;
    time_t t;
    srand((unsigned)time(&t));

    num=rand()%101+1;
    return num;
}

int user()
{
    //ask for the user to guess
    int num;
    printf("Guess the number ");
    scanf("%d",&num);
    return num;
}

int smaller(int num)
{
    //tell the user to guess again
    int input;
    int bigger();
    void win();
    printf("Too low\n");
    printf("Guess again ");
    scanf("%d",&input);

    //recursively call the functions
    if (input<num)
         smaller(num);
    if (input>num)
        bigger(num);
    if (input==num)
        win();


}

int bigger(int num)
{
    //tell the user to guess again
    int input;
    void win();
    int smaller(num);
    printf("Too high\n");
    printf("Guess again ");
    scanf("%d",&input);

    //recursively call the functions
    if (input>num)
        bigger(num);
    if (input<num)
        smaller(num);
    if (input==num)
        win();

}

void win()
{
    //tell the user they won
    printf("You won");
}
