#pragma once

class Link
{
	friend class List;

private:
	int X;
	Link* Next;

public:
	Link(int);
};