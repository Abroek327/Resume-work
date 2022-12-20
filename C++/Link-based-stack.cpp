//Andrew Broek 

#include<iostream>
using namespace std;

class node
{
public:
	int data;
	node* next;
};

class list
{
public:
	node* top=NULL;
	int count = 0;
	void push(node**, int);
	int pop(node* );
	bool isEmpty(node*);
};



void list::push(node** head, int val)
{
	node* n = new node;
	n->data = val;
	*head = n;
	top = n;
	
	count++;
}

int list::pop(node* nood)
{
	if (!nood)
	{
		cout << "stack empty" << endl;
		return NULL;
	}

	else
	{
		node* temp = new node;
		temp->data = top->data;
		top->next;
		return temp->data;
	}
}

bool list::isEmpty(node* crain)
{
	if (crain->next == NULL)
		return true;
	else
		return false;
}
int main()
{
	list l;
	node* head = NULL;
	l.push(&head,10);
	l.push(&head, 7);
	cout << l.pop(head) << endl;
	cout << "there are " << l.count << " items total";
}
	
