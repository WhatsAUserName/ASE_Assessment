#pragma once
#include "Condition.h"

class Link
{
	friend class List;

private:
	Condition X;
	Link* Next;

public:
	Link(Condition c);
};