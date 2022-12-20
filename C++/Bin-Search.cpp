//Binary Search

#include<iostream>
using namespace std;

int binSearch(int arr[], int len, int find)
{
	int mid =  len/ 2;
	if (len > 1)
	{
		if (arr[mid] == find)
			return mid;
		if (arr[mid] > find)
			 binSearch(arr, len - 1, find);
		else if (arr[mid] < find)
			 binSearch(arr, len + 1, find);
		
	}
	else
		return -1;
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int find;
	cout << "enter a number 1-9 ";
	cin >> find;
	
	cout<<find<<" is at index "<<binSearch(arr,8,find);
