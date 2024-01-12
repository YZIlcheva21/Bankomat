#include <iostream>
#include <conio.h>
#include "output.h"
#include "user.h"

using namespace std;

void printMenuOptions(string menuOptions[], int selectedOption)
{
	for (int i = 0; i < 3; i++)
	{

		if (i == selectedOption)
		{
			outputPosition(1, i + 1);
			cout << "-> " << menuOptions[i];
		}


		else
		{
			outputPosition(1, i + 1);
			cout << "   " << menuOptions[i];
		}
	}
}

void mainMenu(string menuOptions[])
{

	int selectedOption = 0;
	char pressedKey = ' ';
	bool exitStatement = true;

	printMenuOptions(menuOptions, selectedOption);

	while (exitStatement)
	{
		pressedKey = _getch();


		if (selectedOption != 0 && pressedKey == (char)72)
		{
			selectedOption--;
		}


		if (selectedOption != 2 && pressedKey == (char)80)
		{
			selectedOption++;
		}

		printMenuOptions(menuOptions, selectedOption);


		if (pressedKey == '\r')
		{
			switch (selectedOption)
			{

			case 0:
				system("CLS");
				login();
				break;

			case 1:
				system("CLS");
				registerUser();
				break;

			case 2:
				exitStatement = false;
				system("CLS");
				cout << "Press any key to exit";
				break;

			default:
				system("CLS");
				break;
			}
		}
	}
}