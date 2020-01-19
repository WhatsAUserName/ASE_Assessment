#include "Condition.h"

Condition::Condition() 
{
	this->num = NULL;
	this->date = "";
	this->condition = NULL;
	this->secondDate = "";
	this->isUseable = 1;
}

void Condition::setup(int a, string b, int c) 
{
	this->num = a;
	this->date = b;
	this->condition = c;
}

void Condition::setup(int a, string b, string c, bool d)
{
	this->num = a;
	this->date = b;
	this->secondDate = c;
	this->isUseable = d;
}

bool operator==(const Condition& c1, const Condition& c2)
{
	return (c1.condition==c2.condition && c1.date == c2.date && c1.num == c2.num && c1.secondDate == c2.secondDate && c1.isUseable == c2.isUseable);
}

ostream& operator<<(ostream& os, Condition& c1)
{
	string useable;
	if (c1.isUseable) 
	{
		useable = "Useable";
	}
	else 
	{
		useable = "Un-useable";
	}
	os << c1.num << " " << c1.date << " " << c1.condition << " " << c1.secondDate << " " << useable;
	return os;
}
