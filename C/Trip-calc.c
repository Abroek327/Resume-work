#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
    //declaration
    char city1,city2,trans,hotel,meal;
    int days, meal_num, meal_charge;
    float trans_cost, hotel_cost, hotel_total, food_charges,Total_charge;
    char city1_name[25];


    //Welcome screen
    printf("\n\n\n\n**************************************\n\n\n\n");
    printf("WELCOME TO THE EXPENSE TRIP CALCULATOR\n\n\n\n");
    printf("***************************************");
    getchar();
    system("cls");

    //Start city selection
    printf("\n\nENTER THE SOURCE CITY :\n\n");
    printf("B FOR BALTIMORE\n\n");
    printf("C FOR CHATTANOOGA\n\n");
    printf("N FOR NASHVILLE\n\n");
    printf("P FOR PASADENA\n\n\n");
    scanf("%c",&city1);
    getchar();
    system("cls");


    //Destination city selection
    printf("\n\nENTER THE DESTINATION CITY\n\n");
    printf("D FOR DENVER\n\n");
    printf("M FOR MADISON\n\n");
    printf("C FOR CLARKSVILLE\n\n");
    printf("K FOR KNOXVILLE\n\n");
    scanf("%c",&city2);
    getchar();
    system("cls");


    //Transportation selection
    printf("\n\nENTER THE MODE OF TRANSPORTATION\n\n");
    printf("A FOR AIR\n\n");
    printf("R FOR TRAIN\n\n");
    printf("B FOR BUS\n\n");
    scanf("%c",&trans);
    getchar();
    system("cls");


    //Hotel grade selection
    printf("\n\nENTER THE TYPE OF HOTEL\n\n");
    printf("F for five star\n\n");
    printf("T for three star\n\n");
    printf("O for ordinary\n\n");
    scanf("%c",&hotel);
    getchar();
    system("cls");

    //Number of days
    printf("\n\nENTER THE NUMBER OF DAYS OF STAY\n\n");
    scanf("%d",&days);
    getchar();
    system("cls");

    //Food selection
    printf("\n\nENTER THE TYPE OF FOOD\n\n");
    printf("V for veg\n\n");
    printf("N for non-veg\n\n");
    printf("C for Continental\n\n");
    scanf("%c",&meal);
    getchar();
    system("cls");

    //Number of meals
    printf("\n\n how many meals would you like to take in the Hotel?\n\n");
    scanf("%d",&meal_num);
    getchar();
    system("cls");

    //starting city
    switch(city1)
    {
    case 'B':case 'b':
        strcpy(city1_name,"Baltimore");
        break;
    case 'C': case 'c':
        strcpy(city1_name,"Chattanooga");
        break;
    case 'N':case 'n':
        strcpy(city1_name,"Nashville");
        break;
    case 'P':case 'p':
        strcpy(city1_name,"Pasadena");
        break;
    }



   //determine transportation cost using
   //both starting and ending city as
   //well as the transportation type
   switch (city1)
   {
        //Baltimore
        case 'b':case'B':
            switch (city2)
		{
		    //Denver
            case'd':case 'D':

                switch (trans)
			{
                case 'a':case 'A':
                    trans_cost=5000;
                    break;
                case 'r':case 'R':
                    trans_cost=2500;
                    break;
                case 'b':case 'B':
                    trans_cost=2000;
                    break;
			}
			break;
        //Madison
		case 'm':case 'M':
			switch (trans)
			{
                case 'a':case 'A':
                    trans_cost=4000;
                    break;
                case 'r':case 'R':
                    trans_cost = 2000;
                    break;
                case 'b':case 'B':
                    trans_cost=1000;
                    break;
			}
			break;
        //Clarkson
		case 'c':case 'C':
			switch (trans)
			{
                case 'a':case 'A':
                    trans_cost=2500;
                    break;
                case 'r':case 'R':
                    trans_cost=800;
                    break;
                case 'b':case 'B':
                    trans_cost=1000;
                    break;
			}
			break;
        //Knoxville
		case 'k':case 'K':
			switch (trans)
			{
                case 'a':case 'A':
                    trans_cost=5000;
                    break;
                case 'r':case 'R':
                    trans_cost=2500;
                    break;
                case 'b':case 'B':
                    trans_cost=2000;
                    break;
			}

			break;
		}
		break;
    //Chattanooga
	case 'c':case 'C':
		switch (city2)
		{
            //Denver
            case 'd':case 'D':
                switch (trans)
                {
                case 'a':case 'A':
                    trans_cost=2500;
                    break;
                case 'r':case 'R':
                    trans_cost=500;
                    break;
                case 'b':case 'B':
                    trans_cost=600;
                    break;
			}
			break;

        //Madison
		case 'm':case 'M':
			switch (trans)
			{
                case 'a':case 'A':
                    trans_cost=4000;
                    break;
                case 'r':case 'R':
                    trans_cost=2300;
                    break;
                case 'b':case 'B':
                    trans_cost=1300;
                    break;
			}
			break;
        //Clarksville
            case 'c':case 'C':
			switch (trans)
			{
                case 'a':case 'A':
                    trans_cost=6000;
                    break;
                case 'r':case 'R':
                    trans_cost=2000;
                    break;
                case 'b':case 'B':
                    trans_cost=1700;
                    break;
			}

			break;
        //Knoxville
		case 'k':case 'K':
			switch (trans)
			{
                case 'a':case 'A':
                    trans_cost=4000;
                    break;
                case 'r':case 'R':
                    trans_cost=1600;
                    break;
                case 'b':case 'B':
                    trans_cost=1400;
                    break;
			}
			break;
		}
		break;
    //Nashville
	case 'n':case 'N':
		switch (city2)
		{
		    //Denver
            case 'd':case 'D':
                switch (trans)
                {
                    case 'a':case 'A':
                        trans_cost=5000;
                        break;
                    case 'r':case 'R':
                        trans_cost=1500;
                        break;
                    case 'b':case 'B':
                        trans_cost=1400;
                        break;
			}
			break;
        //Madison
		case 'm':case 'M':
			switch (trans)
			{
                case 'a':case 'A':
                    trans_cost=2500;
                    break;
                case 'r':case 'R':
                    trans_cost=900;
                    break;
                case 'b':case 'B':
                    trans_cost=700;
                    break;
			}
			break;
        //Clarksville
		case 'c':case 'C':
			switch (trans)
			{
                case 'a':case 'A':
                    trans_cost=4500;
                    break;
                case 'r':case 'R':
                    trans_cost=1700;
                    break;
                case 'b':case 'B':
                    trans_cost=1300;
                    break;
			}
			break;
        //Knoxville
		case 'k':case 'K':
			switch (trans)
			{
                case 'a':case 'A':
                    trans_cost=4000;
                    break;
                case 'r':case 'R':
                    trans_cost=1500;
                    break;
                case 'b':case 'B':
                    trans_cost=1000;
                    break;
			}
			break;
		}
		break;
    //Pasadena
	case 'p':case 'P':
		switch (city2)
		{
		    //Denver
            case 'd':case 'D':

			switch (trans)
			{
                case 'a':case 'A':
                    trans_cost=5000;
                    break;
                case 'r':case 'R':
                    trans_cost=2000;
                    break;
                case 'b':case 'B':
                    trans_cost=1400;
                    break;
			}
			break;
        //Madison
		case 'm':case 'M':
			switch (trans)
			{
                case 'a':case 'A':
                    trans_cost=4500;
                    break;
                case 'r':case 'R':
                    trans_cost=1900;
                    break;
                case 'b':case 'B':
                    trans_cost=1300;
                    break;
			}
			break;
        //Clakrsville
		case 'c':case 'C':
			switch (trans)
			{
                case 'a':case 'A':
                    trans_cost=4500;
                    break;
                case 'r':case 'R':
                    trans_cost=1700;
                    break;
                case 'b':case 'B':
                    trans_cost=1300;
                    break;
			}
			break;
        //Knoxville
		case 'k':case 'K':
			switch (trans)
			{
                case 'a':case 'A':
                    trans_cost=3000;
                    break;
                case 'r':case 'R':
                    trans_cost=1200;
                    break;
                case 'b':case 'B':
                    trans_cost=800;
                    break;
			}

			break;
		}
		break;
	}



    //hotel grade
    switch(hotel)
    {
    case 'F':case 'f':
        hotel_cost=500;
        break;
    case 'T':case 't':
        hotel_cost=300;
        break;
    case 'O':case 'o':
        hotel_cost=100;
        break;
    }


    //food cost
    switch (meal)
    {
    case 'V': case 'v':
        meal_charge=15;
        break;
    case 'N': case 'n':
        meal_charge=30;
        break;
    case 'C':case 'c':
        meal_charge=10;
        break;
    }




    //calculations

    hotel_total=days*hotel_cost;

    food_charges=meal_charge*meal_num*days;

    Total_charge=trans_cost+hotel_total+food_charges;

    //final display

    printf("\n\n*************************************************\n\n");
    printf("TOTAL EXPENSES TO TRAVEL FROM %s is :\n\n",city1_name);
    printf("**************************************************\n\n");
    printf("TRANSPORTATION CHARGES = %.2f\n\n",trans_cost);
    printf("NUMBER OF DAYS OF STAY = %d\n\n",days);
    printf("NUMBER OF MEALS IN A DAY = %d\n\n",meal_num);
    printf("ROOM CHARGES = %.2f\n\n",hotel_total);
    printf("FOOD CHARGES = %.2f\n\n",food_charges);
    printf("HOTEL CHARGES = %.2f\n\n",hotel_total);
    printf("*************************************************\n\n");
    printf("TOTAL CHARGES = %.2f\n\n",Total_charge);
    printf("***************************************************");
    getchar();
    system("cls");

    return 0;

}
