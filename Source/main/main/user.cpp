#include <iostream>
#include <windows.h>
#include "output.h"
#include "programLogic.h"

using namespace std;

struct UserInfo {
	string name;
	string surname;
	string password;
	UserInfo* next;
};


UserInfo* userListHead = nullptr;


void addUserToList(const string& name, const string& surname, const string& password) {
	UserInfo* newUser = new UserInfo;
	newUser->name = name;
	newUser->surname = surname;
	newUser->password = password;
	newUser->next = userListHead;
	userListHead = newUser;
}

bool checkLoginTransaction(const string& name) {
	UserInfo* current = userListHead;
	while (current != nullptr) {
		if (current->name == name) {
			return true;
		}
		current = current->next;
	}
	return false;
}

bool checkLoginUser(const string& name, const string& password) {
	UserInfo* current = userListHead;
	while (current != nullptr) {
		if (current->name == name && current->password == password) {
			return true;
		}
		current = current->next;
	}
	return false;
}

void registerUser() {
    string name, surname, password;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your surname: ";
    cin >> surname;
    cout << "Enter your password: ";
    cin >> password;


    addUserToList(name, surname, password);
    centerText("Registration successful! You can log in your account now.");

    while (true) {
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            cout << "Esc key pressed. Exiting..." << endl;
            system("cls");
            break;
        }
    }
}

void login() {
    string username, password;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    bool loginSuccess = checkLoginUser(username, password);
    string appOptions[] = { "", "Register", "Exit" };
    if (loginSuccess) {

        cout << "Login successful. Welcome, " << username << "!" << endl;
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
