#include <iostream>
#include <string>

using namespace std;

bool exitMenu = false;

string input;
string test;

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
