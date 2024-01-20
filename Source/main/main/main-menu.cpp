#include <iostream>
#include <windows.h>
#include "output.h"
#include "mainMenu.h"
#include "user.h"

using namespace std;

int main()
{
	system("CLS");

	cout << "\n\n\n\n";
	printWelcomeMessage();

	string mainMenuOptions[] = { "Log in", "Register", "Exit" };
	mainMenu(mainMenuOptions);
}