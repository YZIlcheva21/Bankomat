#include <iostream>
#include <conio.h>
#include <windows.h>
#include "output.h"
#include "bankOperations.h"
#include "mainMenu.h"
#include "user.h"

using namespace std;

// Function to handle the main application logic
void app(const string& username) {
    system("cls");
    centerText("Welcome, " + username + "!");

    int selectedOption = 0;
    char pressedKey = ' ';
    bool exitStatement = true;

    string options[] = { "My Balance", "My Will", "Transactions", "Logout" };

    printAppOptions(options, selectedOption);

    string mainMenuOptions[] = { "Log in", "Register", "Exit" };

    // Main loop for handling user input and navigation
    while (exitStatement)
    {

        printAppOptions(options, selectedOption);

        pressedKey = _getch();

        // Update the selected option based on arrow key input
        if (pressedKey == (char)72 && selectedOption > 0)
        {
            selectedOption--;
        }

        if (pressedKey == (char)80 && selectedOption < 3)
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
                transactions(username);
                break;

            case 3:
                system("CLS");
                mainMenu(mainMenuOptions);
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

