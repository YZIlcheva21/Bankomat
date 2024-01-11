#include "main-menu.h";
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <windows.h>
#include <stdlib.h>
#include <conio.h.>

using namespace std;
const int consoleWidth = 80;
int userBalance = 10000;


void outputPosition(int x, int y)
{
	COORD position;
	position.X = x;
	position.Y = y;
	if (SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position))
	{
		return;
	}
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

void centerText(const string& text) {
	int padding = (consoleWidth - text.length()) / 2;
	cout << setw(padding + text.length()) << text << endl;
}

void registerUser() {
	string name, surname, dob, password;
	cout << "Enter your name: ";
	cin >> name;
	cout << "Enter your surname: ";
	cin >> surname;
	cout << "Enter your date of birth: ";
	cin >> dob;
	cout << "Enter your password: ";
	cin >> password;


	centerText("Registration successful! You can log in your account now.");

	while (true) {
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
			cout << "Esc key pressed. Exiting..." << std::endl;
			system("cls");
			break;
		}
	}
}

void balance() {
	system("CLS");
	cout << "Your Current Balance: " << userBalance << " lv.";

	while (true) {
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
			cout << "Esc key pressed. Exiting..." << std::endl;
			system("cls");
			break;
		}
	}


}


void transactions() {
	system("CLS");

	string recipientName;
	int amount;

	
	cout << "Enter the name of the recipient: ";
	cin >> recipientName;

	
	cout << "Enter the amount to send: ";
	cin >> amount;

	
	if (amount <= userBalance && amount > 0) {
		
		userBalance -= amount;

		
		cout << "Transfer to " << recipientName << " of " << amount << " lv is successful." << endl;
	}
	else {
		
		cout << "Transaction failed. Please check your balance and the entered amount." << endl;
	}

	while (true) {
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
			cout << "Esc key pressed. Exiting..." << std::endl;
			system("cls");
			break;
		}
	}
}


void updateBalance(int& balance, int amount) {
	balance += amount;
}

void will() {
	system("CLS");

	string inheritorFullName;
	int amountToLeave;

	
	cout << "Enter the full name of the person to inherit your money: ";
	cin.ignore();  
	getline(cin, inheritorFullName);

	
	cout << "Enter the amount to leave for " << inheritorFullName << ": ";
	cin >> amountToLeave;

	
	updateBalance(userBalance, -amountToLeave);

	
	cout << "Your will is successfully processed. " << inheritorFullName << " will inherit " << amountToLeave << " lv." << endl;

	while (true) {
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
			cout << "Esc key pressed. Exiting..." << std::endl;
			system("cls");
			break;
		}
	}
}

void app(const string& username) {
	system("cls");
	centerText("Welcome, " + username + "!");
	

	int selectedOption = 0;
	char pressedKey = ' ';
	bool exitStatement = true;
	string options[] = { "My Balance", "My Will", "Transactions",  "Logout"};

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

void login()
{
	string username, password;
	cout << "Enter your username: ";
	cin >> username;
	cout << "Enter your password: ";
	cin >> password;


	bool loginSuccess = true;

	if (loginSuccess) {
		app(username);
	}
	else {
		cout << "Login failed. Please try again." << endl;
	}

	while (true) {
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
			cout << "Esc key pressed. Exiting..." << std::endl;
			system("cls");
			break;
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




int main()
{
	system("CLS");

	string mainMenuOptions[] = { "Log in", "Register", "Exit" }; 
	centerText("-----------------------------");
	centerText("Welcome to Bankomat!");
	centerText("-----------------------------");
	mainMenu(mainMenuOptions);
}