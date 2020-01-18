#pragma once
#include "Inspection.h"
class Condition :
	public Inspection
{
	Condition(int eNum, char* insDate, int cond);

	void addElements();
	virtual void setup();
};

