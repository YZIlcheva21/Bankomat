#include <iostream>
#include "output.h"
#include "mainMenu.h"

using namespace std;

int main()
{
	system("CLS");
	

	string mainMenuOptions[] = { "Log in", "Register", "Exit" };
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	printWelcomeMessage();
	
	
	mainMenu(mainMenuOptions);
	
}