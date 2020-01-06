//

#include<iostream>
#include "List.h"

using namespace std;

List::List()
{
	cout << "Constructor called: empty list" << endl;
	// 'head' points to 0 initially and when the list is empty.  
	// Otherwise 'head' points to most recently added object
	head = 0;
}

int List::add(int x)
{
	cout << "Adding " << x << endl;
	// pointer 'temp' used to instantiate objects to add to list 
	Link* temp;
	// memory allocated and the object is given a value
	temp = new Link(x);
	if (temp == 0)
	{
		return 0;  // shows error in memory allocation
	}
	// the pointer in the object is set to whatever 
	// 'head' is currently pointing at
	temp->Next = head;
	// 'head' is re-directed to point to the last created object
	head = temp;
	return 1;
}

void List::display()
{
	cout << "Displaying list:" << endl;
	// pointer 'temp' used to iterate through the list 
	Link* temp;
	// 'head' points to last object.  The rest can only be located 
	// by pointers inside other objects. Now iterate back through 
	// the linked list until reach the last pointer (which is 0)
	for (temp = head; temp != 0; temp = temp->Next)
	{
		cout << "Value of object is " << temp->X << endl;
	}
}


int List::remove(int value)
{
	// CODE FOR REMOVE FUNCTION: PASS value AS A PARAMETER
	// This function attempts to remove the first object containing ‘value’
	// It returns 1 if successful and 0 otherwise
	Link* temp;
	Link* current;

	if (head == 0)		// check for empty list 
	{
		return 0;
	}

	if (head->X == value)	// check first object
	{
		temp = head;		// point to one to remove (i.e. first)
		head = head->Next;	// point head second object 
		cout << "Deleting object containing " << temp->X << endl;
		delete temp;		// free the memory
		return 1;
	}

	// check the rest of the list
	// (Notice that where the 'if' above had 'head' the 'if' inside the 
	//  loop has 'current->Next'.  This is pointing to the object to be
	//  removed)
	for (current = head; current->Next != 0; current = current->Next)
	{
		if (current->Next->X == value)
		{ // remove the object AFTER the one to which current points
			temp = current->Next;		// point to one to remove
			current->Next = temp->Next; // make link to one after 
			cout << "Deleting object containing " << temp->X << endl;
			delete temp;			    // free the memory
			return 1;
		}
	}

	return 0;		// return value indicates whether successful
}
void List::clear()
{
	// CODE FOR CLEAR FUNCTION
	Link* temp;

	cout << "Clear called" << endl;
	while (head != 0)
	{
		temp = head;
		head = head->Next;
		cout << "Deleting object containing " << temp->X << endl;
		delete temp;
	}
}
List::~List() {
	// CODE FOR DESTRUCTOR
	cout << "Destructor called" << endl;
	List::clear();
}
