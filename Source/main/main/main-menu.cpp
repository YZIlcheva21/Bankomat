#include "main-menu.h";
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int consoleWidth = 80; 

void centerText(const string& text) {
    int padding = (consoleWidth - text.length()) / 2;
    cout << setw(padding + text.length()) << text << endl;
}

void app(const string& username) {
    system("cls"); 
    centerText("Welcome, " + username + "!");
    cout << "\n1. My Balance" << endl;
    cout << "2. My Will" << endl;
    cout << "3. Transactions" << endl;
    cout << "0. Logout" << endl;
}

void login() {
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
}


int main() {
    while (true) {
        system("cls"); 
        centerText("Welcome to Your App");

        cout << "\n1. Log In" << endl;
        cout << "2. Register" << endl;
        cout << "0. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            login();
            break;
        case 2:
            registerUser();
            break;
        case 0:
            cout << "Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

        system("pause");
    }

    return 0;
}
