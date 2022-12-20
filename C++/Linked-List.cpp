//Andrew Broek
#include<iostream>

using namespace std;

class Node
{
public:
	int data;
	Node* next;
};
void push(Node** hRef, int new_data)
{
	
	Node* n = new Node();

	n->data = new_data;

	n->next = (*hRef);

	
	(*hRef) = n;
}
void print(Node* n)
{
	while (n != NULL) {
		cout << n->data << " ";
		n = n->next;
	}
}

int main()
{
	int user;
	cout << "Enter a number or -1 to quit ";
	cin >> user;

	Node* head = NULL;
	
	
	while (user != -1)
	{
		push(&head, user);
		cout << "enter another number or -1 to quit ";
		cin >> user;
	}
	print(head);
}
