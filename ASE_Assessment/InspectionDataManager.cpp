#include "InspectionDataManager.h"

void InspectionDataManager::addToList(Condition i)
{
	link.add(i);
}

void InspectionDataManager::removeFromList(Condition c)
{
	link.remove(c);
}

void InspectionDataManager::display()
{
	link.display();
}

void InspectionDataManager::saveToFile()
{
	link.saveToFile();
}

int InspectionDataManager::searchList(int x)
{
	link.searchList(x);
	return 0;
}

