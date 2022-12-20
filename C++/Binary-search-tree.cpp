//Binary Search Tree

#include<iostream>
using namespace std;

class node
{
public:
	int data;
	node* left=NULL; 
	node* right=NULL;
};

class BinST
{
public:
	node* con;
	void add(int);
	
	void print(node*);
};


void BinST::add(int val)
{
	node* t = con;
	if (!con) 
	{
		t = new node;
		t->data = val;
		
	}
	while (t != NULL)
	{
		if (val > t->data)
		{
			t = t->right;
		}
		else
		{
			t = t->left;
		}
	}
	
	
}

void BinST::print(node* at)
{
	if (!at)
		return;
	print(at->left);
	cout << at->data << " ";
	print(at->right);
}
int main()
{
	node *n=NULL;
	BinST tree;
	tree.add(10);
	tree.add(5);
	tree.add(7);
	tree.print(n);
}
