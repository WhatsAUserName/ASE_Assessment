#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool exitMenu = false;

string input;
string test;
ifstream dataIn;
int engineNum;
char date[10];
char date2[10];
char date3[10];
char newDate[10];
char newDate2[10];
char newDate3[10];
int condition;
bool useable;
char filename[80] = "TestList.txt";
char textLine[128];


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
		cout << textLine << endl;
		char* temp[10];
		char* pch;
		pch = strtok_s(textLine," ",temp);
		while (pch != NULL) 
		{
			if (count == 0) 
			{
				engineNum = atoi(pch);
				cout << engineNum << endl;

			}
			if (count == 1) 
			{
				strcpy_s(date,10, pch);
				cout << date << endl;

			}
			if (count == 2) 
			{
				strcpy_s(date2, 10, pch);
				cout << date2 << endl;

			}
			if (count == 3)
			{
				strcpy_s(date3, 10, pch);
				cout << date3 << endl;

			}
			if (count == 4) 
			{
				condition = atoi(pch);
				if (condition > 5) 
				{
					condition = NULL;
					strcpy_s(newDate, 10, pch);
					cout << newDate << endl;

				}
				cout << condition << endl;

			}
			if (count == 5)
			{
				condition = atoi(pch);
				if (condition > 5)
				{
					condition = NULL;
					strcpy_s(newDate2, 10, pch);
					cout << newDate2 << endl;

				}
				cout << condition << endl;

			}
			if (count == 6)
			{
				condition = atoi(pch);
				if (condition > 5)
				{
					condition = NULL;
					strcpy_s(newDate3, 10, pch);
					cout << newDate3 << endl;

				}
				cout << condition << endl;

			}
			if (count == 7)
			{
				useable = atoi(pch);
				cout << useable << endl;

			}
			//cout << pch << endl;
			pch = strtok_s(NULL, " ",temp);
			count++;
		}
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
	cin >> input;

	if (input == "Q" || input == "q") 
	{
		exitMenu = true;
	}

	if (input == "I" || input == "i") 
	{

	}

	if (input == "D" || input == "d")
	{

	}

	if (input == "C" || input == "c")
	{

	}

	if (input == "S" || input == "s")
	{

	}

	if (input == "L" || input == "l")
	{
		loadFile();

	}

	if (input == "R" || input == "r")
	{

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
