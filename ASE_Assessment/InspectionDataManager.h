#pragma once
#include "List.h"
#include "Condition.h"
#include "Alert.h"
class InspectionDataManager
{
protected:
	List link;
public:
	void addToList(Condition i);
	void removeFromList(Condition c);
	void display();
	void saveToFile();
	int searchList(int x);
	
	//List addToList(List l, Alert i);

};

