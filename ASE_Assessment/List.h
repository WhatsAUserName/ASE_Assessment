#pragma once

#include "Link.h"

class List
{
private:
	Link * head;
	int count;
public:
	List();
	~List();
	int add(Condition x);
	void display();
	void saveToFile();
	int searchList(int x);
	int remove(Condition value);
	void clear();

};

