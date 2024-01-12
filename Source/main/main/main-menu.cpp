#include <iostream>
#include "output.h"
#include "mainMenu.h"

using namespace std;

int main()
{
	system("CLS");

	string mainMenuOptions[] = { "Log in", "Register", "Exit" }; 
	centerText("-----------------------------");
	centerText("Welcome to Bankomat!");
	centerText("-----------------------------");
	mainMenu(mainMenuOptions);
}