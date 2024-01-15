#include <iostream>
#include "output.h"
#include "mainMenu.h"

using namespace std;

int main()
{
	system("CLS");

	cout << "\n\n\n\n";
	printWelcomeMessage();

	string mainMenuOptions[] = { "Log in", "Register", "Exit" };
	mainMenu(mainMenuOptions);
}