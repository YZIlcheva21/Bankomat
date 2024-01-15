#include <iostream>
#include <conio.h>
#include "output.h"
#include "user.h"
#include <Windows.h>

using namespace std;

void printWelcomeMessage() {
	cout << R"(
 _______    ______   __    __  __    __   ______   __       __   ______   ________ 
/       \  /      \ /  \  /  |/  |  /  | /      \ /  \     /  | /      \ /        |
$$$$$$$  |/$$$$$$  |$$  \ $$ |$$ | /$$/ /$$$$$$  |$$  \   /$$ |/$$$$$$  |$$$$$$$$/ 
$$ |__$$ |$$ |__$$ |$$$  \$$ |$$ |/$$/  $$ |  $$ |$$$  \ /$$$ |$$ |__$$ |   $$ |   
$$    $$< $$    $$ |$$$$  $$ |$$  $$<   $$ |  $$ |$$$$  /$$$$ |$$    $$ |   $$ |   
$$$$$$$  |$$$$$$$$ |$$ $$ $$ |$$$$$  \  $$ |  $$ |$$ $$ $$/$$ |$$$$$$$$ |   $$ |   
$$ |__$$ |$$ |  $$ |$$ |$$$$ |$$ |$$  \ $$ \__$$ |$$ |$$$/ $$ |$$ |  $$ |   $$ |   
$$    $$/ $$ |  $$ |$$ | $$$ |$$ | $$  |$$    $$/ $$ | $/  $$ |$$ |  $$ |   $$ |   
$$$$$$$/  $$/   $$/ $$/   $$/ $$/   $$/  $$$$$$/  $$/      $$/ $$/   $$/    $$/    
                                                                                                                                                                                                                                                                              
                                                                                                                                                                                                               
                                                                                                                                                                                                               
)";
}

void printMenuOptions(string menuOptions[], int selectedOption) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int i = 0; i < 3; i++) {
		outputPosition(1, i + 1);

		if (i == selectedOption) {
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
			cout << "-> " << menuOptions[i];
		}
		else {
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout << "   " << menuOptions[i];
		}
	}

	// Reset text color to default
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void printAppOptions(string menuOptions[], int selectedOption) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int i = 0; i < 4; i++) {
		outputPosition(1, i + 1);

		if (i == selectedOption) {
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
			cout << "-> " << menuOptions[i];
		}
		else {
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout << "   " << menuOptions[i];
		}
	}

	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
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