/*
Andrew Broek 
Jacob Carlton
Xuancun Dong
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<time.h>
using namespace std; 

class player
{
public:
	player(const char*); 
	~player()
	{
		delete[]name;
	}
	 void bonus(float);
private:
	char* name; 
};

player::player(const char* n)
{
	name = new char[strlen(n) + 1];
	strcpy(name, n);
}

class chuck :public player
{
public:
	chuck(const char*, int, float, int);
	void roll();
	void winnings(int);
	void bonus(float);

private:
	float bet, win;
	int want, choice, count;
};

chuck::chuck(const char* n, int w, float b, int c)
	:player(n)
{
	cout << "How many times do you want to play chuck a luck? ";
	cin >> w;
	want = w;
	for (int i = 1; i <= want-1; i++)
	{
		roll();
	}
	
}
void chuck::roll()
{
	int r1, r2, r3, r4, r5;
	srand((unsigned int)time(NULL));
	
	cout << "How much would you like to bet? ";
	cin >> bet;
	cout << "What number would you like to bet on? ";
	cin >> choice;
		r1 = rand() % 6 + 1;
		if (choice == r1)
		{
			count++;
		}
		r2 = rand() % 6 + 1;

		if (choice == r2)
		{
			count++;
		}
		r3 = rand() % 6 + 1;

		if (choice == r3)
		{
			count++;
		}
		r4 = rand() % 6 + 1;

		if (choice == r4)
		{
			count++;
		}
		r5 = rand() % 6 + 1;

		if (choice == r5)
		{
			count++;
		}
		cout << "The dice came up " << r1 << " " << r2 << " " << r3 << " " << r4 << " " << r5 << endl;
		winnings(count);
		count = 0;
	
}

void chuck::winnings(int c)
{
	win = 0;
	if (count >= 1)
	{
		win = count * bet;
		cout << "You win $" << win << endl;
		bonus(win);
	}
	else
	{
		win += bet;
		cout << "You lost $" << win << endl;
	}
	
}
void chuck::bonus(float w)
{
	float bonus_win, new_win;
	if (win <= 50.00)
	{
		bonus_win = 0.015;
	}
	if (win >= 50.01 && win<= 100.00)
	{
		bonus_win = 0.019;
	}
	if (win >= 100.01 && win <= 1000.00)
	{
		bonus_win = 0.025;
	}
	if (win > 1000.00)
	{
		bonus_win = 0.029;
	}
	new_win = win * bonus_win;
	win += new_win;
	
	cout << "bonous of $" << new_win << " and a new total of $" << win << endl;
}
int main()
{
	player p("Andoi Block");
	chuck c("Andoi Block", 2, 100.00, 3);
	c.roll();
}

