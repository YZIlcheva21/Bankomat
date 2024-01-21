#include <iostream>
#include <windows.h>
#include "output.h"
#include "programLogic.h"

using namespace std;

// Structure representing user information
struct UserInfo {
	string name;
	string surname;
	string password;
	UserInfo* next;
};

// Global variable to keep track of the head of the user list
UserInfo* userListHead = nullptr;

// Function to add a new user to the linked list
void addUserToList(const string& name, const string& surname, const string& password) {
	UserInfo* newUser = new UserInfo;
	newUser->name = name;
	newUser->surname = surname;
	newUser->password = password;
	newUser->next = userListHead;
	userListHead = newUser;
}

// Function to check if a user with a given name exists in the list
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

// Function to check if a user with a given name and password exists in the list
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

// Function to register a new user
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

// Function to handle user login
void login() {
    string username, password;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    // Check if login is successful
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
