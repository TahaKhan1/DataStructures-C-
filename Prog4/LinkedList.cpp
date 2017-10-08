#include<iostream>
#include "LinkedList.h"
#include <cmath>
#include <assert.h>
#include "limits.h"
using namespace std;
LinkedList::LinkedList()
{
	pred = 0;
	current = 0;
	first = 0;
}
bool LinkedList::Empty() const
{
	return first == 0;
};
bool LinkedList::AtEnd() const
{
	return current == 0;
};
void LinkedList::Skip()
{
	assert(!AtEnd()); 
	pred = current;
	current = current->next;

};
NodeData LinkedList::CurrentEntry() const
{
	assert(current->data.X() >= 0);
	assert(current->data.Y() >= 0);
	return current->data;
};
void LinkedList::Insert(const NodeData &d)
{
	Node *newNode = 0;                 // Create a New Node
	if (pred== 0|| Empty())            // Case: First node & empty list
	{
		Node *newNode = new(nothrow) Node(d, first);
		first = newNode;
		pred = newNode;
		current = newNode;
	}
	else{
		Node *newNode = new(nothrow) Node(d, pred->next);
		current = newNode;
		pred->next = newNode;
		pred = newNode;
	}
};
void LinkedList::Delete()
{
	// Check whether the correct data exist
	assert(current->data.X() >= 0);
	assert(current->data.Y() >= 0);

	// deleting first element
	if(current==first)
	{
		first = current->next;
		delete current;
		current = first;
	} // delete element at the middle or end of the linkedlist
	else
	{                                 
			pred->next = current->next;
			delete current;
			current = pred->next;
	};
};