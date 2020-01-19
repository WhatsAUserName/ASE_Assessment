#include <iostream>
#include <fstream>
#include <string>
#include "Condition.h"
#include "Alert.h"
#include "Link.h"
#include "List.h"
#include "InspectionDataManager.h"

using namespace std;

bool exitMenu = false;

InspectionDataManager manager;

string input;
string test;
ifstream dataIn;
int engineNum;
char date[20];
char date2[10];
char date3[10];
char newDate[20];
char newDate2[10];
char newDate3[10];
int condition;
bool useable;
bool flag = false;
bool flag2 = true;
char filename[80] = "TestList.txt";
char textLine[128];
string tempDate;
string tempDate2;
string tempDate3;
string finalDate;
string secondFinalDate;

Condition c;

int loadFile()
{
	
	int count = 0;
	dataIn.open(filename);
	if (!dataIn)
	{
		cerr << "Unable to open file " << filename << endl;
		return 1;
	}
	dataIn.getline(textLine, sizeof(textLine), '\n');
	while (!dataIn.eof()) {
		dataIn.getline(textLine, sizeof(textLine), '\n');
		//cout << textLine << endl;
		char* temp[10];
		char* pch;
		pch = strtok_s(textLine," ",temp);
		while (pch != NULL) 
		{
			if (count == 0) 
			{
				engineNum = atoi(pch);
			}
			if (count == 1) 
			{
				strcpy_s(date,10, pch);
				tempDate = string(date);
			}
			if (count == 2) 
			{
				strcpy_s(date2, 10, pch);
				tempDate2 = string(date2);
			}
			if (count == 3)
			{
				strcpy_s(date3, 10, pch);
				tempDate3 = string(date3);
				finalDate = tempDate + " " + tempDate2 + " " + tempDate3;
				strcpy_s(date, 20, finalDate.c_str());
			}
			if (count == 4) 
			{
				condition = atoi(pch);
				//condition = NULL;
				strcpy_s(newDate, 10, pch);
				tempDate = string(newDate);
			}
			if (count == 5)
			{
				strcpy_s(newDate2, 10, pch);
				tempDate2 = string(newDate2);
			}
			if (count == 6)
			{				
				strcpy_s(newDate3, 10, pch);
				tempDate3 = string(newDate3);
				secondFinalDate = tempDate + " " + tempDate2 + " " + tempDate3;
				strcpy_s(newDate, 20, secondFinalDate.c_str());
			}
			if (count == 7)
			{
				useable = atoi(pch);
				condition = 0;
				flag = true;
			}
			
			pch = strtok_s(NULL, " ",temp);
			count++;
		}
		if (flag)
		{
			c.setup(engineNum, finalDate, secondFinalDate, useable);
			finalDate.clear();
			secondFinalDate.clear();
			manager.addToList(c);
			c.setup(0, "", "", 1);
		}
		else
		{
			c.setup(engineNum, finalDate, condition);
			finalDate.clear();
			manager.addToList(c);

		}
		flag = false;
		count = 0;
	}
	//do something with heading files

}

void mainMenu() 
{
	cout << "Q-Quit" << endl;
	cout << "I-Insert" << endl;
	cout << "D-Delete" << endl;
	cout << "C-Contents" << endl;
	cout << "S-Save to file" << endl;
	cout << "L-Load from file" << endl;
	cout << "R-Linear Search" << endl;
	getline(cin, input);

	if (input == "Q" || input == "q") 
	{
		exitMenu = true;
	}

	if (input == "I" || input == "i") 
	{
		cout << " Please input engine number"<<endl;
		getline(cin, input);
		engineNum = stoi(input);
		cout << "Please input last date"<<endl;
		getline(cin, input);
		finalDate = input;
		strcpy_s(date, 20, finalDate.c_str());
		cout << "Does the car have a fault?" << endl;
		getline(cin, input);
		if (input == "yes" || input == "Yes")
		{
			cout << "Please give next check up date"<<endl;
			getline(cin, input);
			finalDate = input;
			strcpy_s(newDate, 20, finalDate.c_str());
			cout << "Is the car useable? Please type 0 for no, or 1 for yes" << endl;
			getline(cin, input);
			useable = stoi(input);
			c.setup(engineNum, date, newDate, useable);
			manager.addToList(c);
			cout << "Added " << c << "to the list"<<endl;
		}
		if (input == "no" || input == "No") 
		{
			cout << "please rate the condition from 1-5" << endl;
			getline(cin, input);
			condition = stoi(input);
			c.setup(engineNum, date, condition);
			manager.addToList(c);
			cout << "Added " << c << "to the list" << endl;
		}
		
	}

	if (input == "D" || input == "d")
	{
		cout << "Provide details of car to delete from list" << endl;
		cout << "Please input engine number" << endl;
		getline(cin, input);
		engineNum = stoi(input);
		cout << "Please input last date" << endl;
		getline(cin, input);
		finalDate = input;
		strcpy_s(date, 20, finalDate.c_str());
		cout << "Does the car have a fault?" << endl;
		getline(cin, input);
		if (input == "yes" || input == "Yes")
		{
			cout << "Please give next check up date" << endl;
			getline(cin, input);
			finalDate = input;
			strcpy_s(newDate, 20, finalDate.c_str());
			cout << "Is the car useable? Please type 0 for no, or 1 for yes" << endl;
			getline(cin, input);
			useable = stoi(input);
			c.setup(engineNum, date, newDate, useable);
			manager.removeFromList(c);
		}
		if (input == "no" || input == "No")
		{
			cout << "please rate the condition from 1-5" << endl;
			getline(cin, input);
			condition = stoi(input);
			c.setup(engineNum, date, condition);
			manager.removeFromList(c);
		}
	}

	if (input == "C" || input == "c")
	{
		manager.display();
	}

	if (input == "S" || input == "s")
	{
		manager.saveToFile();
	}

	if (input == "L" || input == "l")
	{
		loadFile();

	}

	if (input == "R" || input == "r")
	{
		cout << "Please input engine number you wish to search for" << endl;
		cin >> input;
		manager.searchList(stoi(input));
	}
}


int main() 
{
	
	cout << "Test Menu"<<endl;
	while (true) 
	{
		//cout << endl;
		if (exitMenu == true) 
		{
			break;
		}
		mainMenu();
	}
}
