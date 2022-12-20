//Andrew Broek
//Sorted linked list
#include <iostream>
using namespace std;

class node
{
public:
	int data;
	node* next;
};

void push(node** hRef, int nData)
{
	node* n = new node();
	n->data = nData;
	n->next = *hRef;
	*hRef = n;
}

node* getEnd(node* fin)
{
	while (fin != NULL && fin->next != NULL)
	{
		fin = fin->next;
	}
	return fin;
}

node* partition(node* start, node** nStart, node* end, node** nEnd)
{
	node* pivot = end;
	node* last=NULL;
	while (start != pivot)
	{
		if (start->data < pivot->data)
		{
			if (*nStart == NULL)
				*nStart = start;
			last = start;
			start = start->next;
		}
		else
			if (last)
			{
				last->next = start->next;
				node* t = start->next;
				start->next = NULL;
				end->next = start;
				end = start;
				start = t;
			}
		
		
	}
	if (*nStart == NULL)
	{
		*nStart = pivot;
	}
	*nEnd = end;
	return pivot;
}
