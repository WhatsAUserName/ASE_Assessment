#pragma once
#include "Inspection.h"
#include <iostream>
using namespace std;
class Condition :
	public Inspection
{
public:
	
	
	Condition();

	virtual void setup(int a, string b, int c)override;
	virtual void setup(int a, string b, string c, bool d)override;
	friend bool operator== (const Condition& c1, const Condition& c2);
	friend ostream& operator<<(ostream& os, Condition& c1);
	int num;
protected:
	
	string date;
	int condition;
	string secondDate;
	bool isUseable;
};

