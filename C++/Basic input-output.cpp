#include <iostream>

#include <iomanip>

using namespace std;



void getname(char*);

void getinfo(float&, float&, float&, float&, float&);

void calc(float, float, float, float, float, float&, float&, float&);

void getletter(float, char&);

void print(string, float, float, float, char);

void avg(float&, float&, float&, float&, float, float, int);

void calcletter(char, int&, int&, int&, int&, int&, int);





int main()

{

	char name[35];

	char letter{};

	float hwk1, hwk2, hwk3, exam1, exam2, hwkt, examt, classper, toe1, toe2, aoe1, aoe2;

	int count = 0, a_num, b_num, c_num, d_num, f_num;

	while (count < 5)

	{

		getname(name);

		getinfo(hwk1, hwk2, hwk3, exam1, exam2);

		cin.ignore(35, '\n');

		calc(hwk1, hwk2, hwk3, exam1, exam2, hwkt, examt, classper);

		getletter(classper, letter);

		print(name, hwkt, examt, classper, letter);

		count++;

		avg(toe1, toe2, aoe1, aoe2, exam1, exam2, count);

		calcletter(letter, a_num, b_num, c_num, d_num, f_num, count);

	}

	return 0;



}



void getname(char* name)

{



	cout << "Enter the student's name" << endl;

	cin.getline(name, 35);

}



void getinfo(float& hwk1, float& hwk2, float& hwk3, float& exam1, float& exam2)

{

	cout << "Enter the three homework grades" << endl;

	cin >> hwk1 >> hwk2 >> hwk3;

	cout << "Enter the two exam scores" << endl;

	cin >> exam1 >> exam2;

}



void calc(float hwk1, float hwk2, float hwk3, float exam1, float exam2, float& hwkt, float& examt, float& classper)

{

	hwkt = hwk1 + hwk2 + hwk3;

	examt = exam1 + exam2;

	classper = (hwkt / 1.875) + (examt / 3.333);

	cout << classper << endl;

}



void getletter(float percent, char& letter)

{

	if (percent >= 90 && percent < 100)

		letter = 'A';

	else if (percent >= 80 && percent < 90)

		letter = 'B';

	else if (percent >= 70 && percent < 80)

		letter = 'C';

	else if (percent >= 60 && percent < 70)

		letter = 'D';

	else if (percent < 60)

		letter = 'F';

	cout << letter << endl;

}



void print(string name, float hwkt, float examt, float classper, char letter)

{

	cout << "The data of " << name << " are listed below" << '\n';

	cout << "The total homework points are " << hwkt << '\n';

	cout << "The total exam points are " << examt << '\n';

	cout << "The class percentage is " << classper << '\n';

	cout << "The letter grade is " << letter << '\n' << '\n' << '\n';

}



void avg(float& toe1, float& toe2, float& aoe1, float& aoe2, float exam1, float exam2, int count)

{

	if (count == 1)

	{

		toe1 = exam1;

		toe2 = exam2;

	}

	else if (count < 5)

	{

		toe1 += exam1;

		toe2 += exam2;

	}

	else

	{

		toe1 += exam1;

		toe2 += exam2;

		aoe1 = toe1 / 5;

		aoe2 = toe2 / 5;

		cout << "The total score of exam 1 is " << toe1 << '\n';

		cout << "The total score of exam 2 is " << toe2 << '\n';

		cout << "The average of the exam 1 score is " << aoe1 << '\n';

		cout << "The average of the exam 2 score is " << aoe2 << '\n';

	}

}



void calcletter(char letter, int& a_num, int& b_num, int& c_num, int& d_num, int& f_num, int count)

{

	if (count == 1)

	{

		a_num = b_num = c_num = d_num = f_num = 0;

		if (letter == 'A')

			a_num++;

		else if (letter == 'B')

			b_num++;

		else if (letter == 'C')

			c_num++;

		else if (letter == 'D')

			d_num++;

		else

			f_num++;

	}

	else if (count < 5)

	{

		if (letter == 'A')

			a_num++;

		else if (letter == 'B')

			b_num++;

		else if (letter == 'C')

			c_num++;

		else if (letter == 'D')

			d_num++;

		else

			f_num++;

	}

	else

	{

		if (letter == 'A')

			a_num++;

		else if (letter == 'B')

			b_num++;

		else if (letter == 'C')

			c_num++;

		else if (letter == 'D')

			d_num++;

		else

			f_num++;

		cout << "There are " << a_num << " A's, " << b_num << " B's, " << c_num << " C's, " << d_num << " D's, " << "and " << f_num << " F's." << '\n';

	}

}
