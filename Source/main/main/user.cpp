#include <iostream>
#include <windows.h>
#include "output.h"
#include "programLogic.h"

using namespace std;

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
			cout << "Esc key pressed. Exiting..." << endl;
			system("cls");
			break;
		}
	}
}