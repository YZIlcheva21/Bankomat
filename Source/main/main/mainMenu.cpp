#include <iostream>
#include <conio.h>
#include "output.h"
#include "user.h"

using namespace std;
void printWelcomeMessage() {
	cout << R"(
 ___       __   _______   ___       ________  ________  _____ ______   _______           _________  ________          ________  ________  ________   ___  __    ________  _____ ______   ________  _________   
|\  \     |\  \|\  ___ \ |\  \     |\   ____\|\   __  \|\   _ \  _   \|\  ___ \         |\___   ___\\   __  \        |\   __  \|\   __  \|\   ___  \|\  \|\  \ |\   __  \|\   _ \  _   \|\   __  \|\___   ___\ 
\ \  \    \ \  \ \   __/|\ \  \    \ \  \___|\ \  \|\  \ \  \\\__\ \  \ \   __/|        \|___ \  \_\ \  \|\  \       \ \  \|\ /\ \  \|\  \ \  \\ \  \ \  \/  /|\ \  \|\  \ \  \\\__\ \  \ \  \|\  \|___ \  \_| 
 \ \  \  __\ \  \ \  \_|/_\ \  \    \ \  \    \ \  \\\  \ \  \\|__| \  \ \  \_|/__           \ \  \ \ \  \\\  \       \ \   __  \ \   __  \ \  \\ \  \ \   ___  \ \  \\\  \ \  \\|__| \  \ \   __  \   \ \  \  
  \ \  \|\__\_\  \ \  \_|\ \ \  \____\ \  \____\ \  \\\  \ \  \    \ \  \ \  \_|\ \           \ \  \ \ \  \\\  \       \ \  \|\  \ \  \ \  \ \  \\ \  \ \  \\ \  \ \  \\\  \ \  \    \ \  \ \  \ \  \   \ \  \ 
   \ \____________\ \_______\ \_______\ \_______\ \_______\ \__\    \ \__\ \_______\           \ \__\ \ \_______\       \ \_______\ \__\ \__\ \__\\ \__\ \__\\ \__\ \_______\ \__\    \ \__\ \__\ \__\   \ \__\
    \|____________|\|_______|\|_______|\|_______|\|_______|\|__|     \|__|\|_______|            \|__|  \|_______|        \|_______|\|__|\|__|\|__| \|__|\|__| \|__|\|_______|\|__|     \|__|\|__|\|__|    \|__|
                                                                                                                                                                                                               
                                                                                                                                                                                                               
                                                                                                                                                                                                               
)";
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;

}
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

void printAppOptions(string menuOptions[], int selectedOption)
{
	for (int i = 0; i < 4; i++)
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
				exit(0);
				break;

			default:
				system("CLS");
				break;
			}
		}
	}
}