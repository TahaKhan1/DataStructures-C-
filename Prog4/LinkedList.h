# ifndef LINKEDLIST_H
# define LINKEDLIST_H
//-----------------------LinkedList.h------------------------//
//Purpose: This header file is the interface to the module "LinkedList.cpp"
#include <cassert>
#include "Point.h"

typedef Point NodeData ;
//-----------Class LinkedList------------------------------------//
class LinkedList
{
	private:
		struct Node
		{
			NodeData data;    // Content of Node
			Node *next;       // Link to the next node

			// Node constructor Functions
			Node() {}
			Node(const NodeData &theData, Node *const TheNext = 0)
				: data(theData), next(TheNext) {}
		};
	public:
		LinkedList();
		bool Empty() const;
		bool AtEnd() const;
		void Rewind() { current = first; pred = 0;}
		void Skip();
		NodeData CurrentEntry() const;
		void Insert(const NodeData &d);
		void Update(NodeData &d) { assert(!AtEnd()); current->data = d; }
		void Delete();
	private:
		Node *first;                 // Points to first node on the list
		Node *current;				 // Points to current node on the list
		Node *pred;					 // Points to node preceding the current entry
};
#endif

