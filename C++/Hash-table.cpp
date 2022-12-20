//Andrew Broek
#include <iostream>
using namespace std;



class table
{
public:
	int arr[27] = { 0 };
	int hash(int n)
	{
		return n % 27;
	}
	void add(int n)
	{
		int slot;
		slot=hash(n);
		if(arr[slot]==0)
			arr[slot] = n;
		else
		{
			slot += 1;
			arr[slot] = n;
			
		}
	}
	int search(int n)
	{
		int slot = hash(n);
		for (int i = 0; i < 27; i++)
		{
			if (arr[slot] != n)
			{
				cout << "not found" << endl;
				return -1;
			}
		}
		cout << "index: " << slot << endl;
		
		return slot;
	}
};

int main()
{
	table t; 
	t.add(10);
	t.add(27);
	t.add(3);
	t.add(64);
	t.add(829);
	t.add(40000);
	t.add(2983);
	t.add(54);
	
	for (int i = 0; i < 27; i++)
	{
		cout << t.arr[i] << " ";
	}
	cout << endl;
	t.search(3);
	t.search(78);
}
