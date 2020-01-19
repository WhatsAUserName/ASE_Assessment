#pragma once
#include <iostream>
#include <string>
using namespace std;
class Inspection
{
public:
	virtual ~Inspection() {};
	virtual void setup(int a, string b, int c) = 0;
	virtual void setup(int a, string b, string c, bool d) = 0;
};

