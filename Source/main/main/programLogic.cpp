#include <iostream>
#include <conio.h>
#include <windows.h>
#include "output.h"
#include "bankOperations.h"
#include "mainMenu.h"

using namespace std;

void app(const string& username) {
	system("cls");
	centerText("Welcome, " + username + "!");


	int selectedOption = 0;
	char pressedKey = ' ';
	bool exitStatement = true;
	string options[] = { "My Balance", "My Will", "Transactions",  "Logout" };

	printMenuOptions(options, selectedOption);

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

		printMenuOptions(options, selectedOption);


		if (pressedKey == '\r')
		{
			switch (selectedOption)
			{

			case 0:
				system("CLS");
				balance();
				break;

			case 1:
				system("CLS");
				will();
				break;

			case 2:
				system("CLS");
				transactions();
				break;


			default:
				system("CLS");
				break;
			}
		}
	}

	while (true) {
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
			cout << "Esc key pressed. Exiting..." << endl;
			system("cls");
			break;
		}
	}

}