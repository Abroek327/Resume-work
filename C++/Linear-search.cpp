//Andrew Broek 
#include <iostream>

using namespace std;

int lineSearch(int n, int arr[])
{
	for (int i = 0; i <=10; i++)
	{
		if (arr[i] == n)
			return i;
		
	}
	return -1;
}
int main()
{
	int n;
	int arr[10];
	cout << "Enter 10 numbers ";
	for (int i = 0; i <= 9; i++)
	{
		cin >> arr[i];
	}

	
	cout << "What value you looking for? ";
	cin >> n;
	
	cout << n << " is at index " << lineSearch(n, arr) << endl;
	

}
