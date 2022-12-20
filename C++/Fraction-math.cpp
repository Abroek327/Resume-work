#include<iostream>
using namespace std;

class Fraction
{
	friend ostream& operator<<(ostream&, const Fraction&);
	friend istream& operator>>(istream&, Fraction&);

public:
	Fraction(int = 1, int = 1);
	

	Fraction operator+(const Fraction& rhs)const
	{
		if (dem != rhs.dem)
			return Fraction((rhs.dem * (num)+dem * (rhs.num)), dem * rhs.dem);
		else
			return Fraction(num + rhs.num,dem);

	}
	Fraction operator-(const Fraction& rhs)const
	{
		if (dem != rhs.dem)
			return Fraction((rhs.dem * (num)-dem * rhs.num), dem * rhs.dem);
		else
			return Fraction(num - rhs.num, dem);
	}
	Fraction operator*(const Fraction& rhs)const
	{
		return Fraction(num * rhs.num, dem * rhs.dem);
	}
	Fraction operator/(const Fraction& rhs)const
	{
		return Fraction(num * rhs.dem, dem * rhs.num);
	}
	

	bool operator==(const Fraction& rhs)const
	{
		return (num / (float)dem) == (rhs.num / (float)rhs.dem);
	}
	bool operator!=(const Fraction& rhs)const
	{
		return (num / (float)dem) != (rhs.num / (float)rhs.dem);
	}

	Fraction& operator++();
	Fraction operator++(int);

private:
	int num, dem;
};

ostream& operator<<(ostream& output, const Fraction& f)
{
	output << f.num << " / " << f.dem << endl;
	return output;
}

istream& operator>>(istream& input, Fraction& f)
{
	input >> f.num >> f.dem;
	return input;
}

Fraction::Fraction(int n, int d)
{
	num = n;
	dem = d;
}

Fraction& Fraction::operator++()
{
	num++;
	dem++;
	return *this;
}

Fraction Fraction::operator++(int)
{
	Fraction temp = *this;
	num++;
	dem++;
	return temp;
}



int main()
{
	Fraction a, b, sum, diff, prod, quo;
	cout << "Enter first num and dem  ";
	cin >> a;
	cout << endl << "Enter second num and dem  ";
	cin >> b;
	cout << endl << "first fraction is  " << a;
	cout << endl << "second fraction is  " << b << endl;
	sum = a + b;
	diff = a - b;
	prod = a * b;
	quo = a / b;
	
	cout << "sum is  " << sum << endl;
	cout << "diff is  " << diff << endl;
	cout << "prod is  " << prod << endl;
	cout << "quo is  " << quo << endl;

	if (a == b)
		cout << "fractions are equal" << endl;
	if (a != b)
		cout << "fractions are not equal" << endl;

	cout << "preincrement:  " << ++a << ++b << endl;
	cout << "postincrement:  " << a++ << b++ << endl;
	cout << "after postincrement:  " << a << b << endl;

	return 0;
}

