//array based stack
#include <cstddef> 

#include<iostream>
using namespace std;

class aStack
{
public:
	
	int const maxSize= 10;
	int arr[10], count=-1;
	void push(int);
	int pop();
	bool isEmpty();
};



bool aStack::isEmpty()
{
	if (count<0)
		return true;
	else
		return false;
}
void aStack::push(int n)
{
	if (count >= maxSize - 1)
		cout << "Pool's closed";
	if (isEmpty() == true)
		arr[++count] = n;
	
	
	
}

int aStack::pop()
{
	if (isEmpty() == false)
		return arr[count--];
	else if (isEmpty() == true)
		cout << "The stack is empty";
	return 0;
}

int main()
{
	aStack fun;
	fun.push(10);
	fun.push(20);
	fun.push(100);
	fun.push(19);
	fun.push(87);
	fun.push(1031);
	
	cout << "pop: " << fun.pop() << endl;
}
