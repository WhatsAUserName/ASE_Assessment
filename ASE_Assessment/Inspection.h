#pragma once
#include <iostream>
#include <string>
class Inspection
{
public:
	virtual ~Inspection() {};
	virtual void setup() = 0;
};

