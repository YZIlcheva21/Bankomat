#pragma once
#include <string>
using namespace std;

//Displays the menu options with highlighting for the selected option
void printMenuOptions(string menuOptions[], int selectedOption);

//Displays the app options with highlighting for the selected option
void printAppOptions(string menuOptions[], int selectedOption);

//Displays the main menu and handles user input to navigate through options
void mainMenu(string menuOptions[]);

void printWelcomeMessage();