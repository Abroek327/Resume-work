//Array Based Queue 
#include <iostream>
#include<array>
using namespace std;


class q
{
public:
	int const MaxSize = 10;
	int arr[10];
	int count=0, front = 0, back = 9;
	int* enq(int);
	int deq();
	bool isEmpty();

};

bool q::isEmpty()
{
	if (arr == NULL)
		return true;
	else
		return false;
}

int* q:: enq(int in)
{
	if (isEmpty()==false)
	{
		arr[count] = in;
		count++;
		
		return arr;
	}
	else if (count>10)
	{
		cout << "Error queue full" << endl;
	}
	
}

int q:: deq()
{
	if (isEmpty())
	{
		cout << "Error: queue empty" << endl;
	}
	else
	{
		int first;
		first = arr[front];
		arr[front] = NULL;
		count--;
		return first;
	}
}

int main()
{
	q trial;
	trial.enq(1);
	trial.enq(2);
	trial.enq(3);
	trial.enq(4);
	trial.enq(5);
	trial.enq(6);
	trial.enq(7);
	trial.enq(8);
	trial.enq(9);
	trial.enq(10);
	for (int i = 0; i < trial.MaxSize; i++)
	{
		cout << trial.arr[i]<<" ";
	}
	trial.deq();
	
	
}
