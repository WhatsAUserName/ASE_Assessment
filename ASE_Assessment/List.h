#pragma once

#include "Link.h"

class List
{
private:
	Link * head;
public:
	List();
	~List();
	int add(int x);
	void display();
	int remove(int value);
	void clear();

};

