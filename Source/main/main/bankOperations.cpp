#include <iostream>
#include <windows.h>
#include <string>
#include "user.h"

using namespace std;

int userBalance = 10000;
int newBalance = userBalance;

void balance() {
	system("CLS");
	cout << "Your Current Balance: " << userBalance << " lv.";

	while (true) {
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
			cout << "Esc key pressed. Exiting..." << endl;
			system("cls");
			break;
		}
	}


}

void transactions(const string& username) {
	system("CLS");

	string recipientName;
	int amount;

	cout << "Enter the name of the recipient: ";
	cin >> recipientName;


	if (!checkLoginTransaction(recipientName) ){
		cout << "Recipient not found. Transaction failed." << endl;
		while (true) {
			if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
				cout << "Esc key pressed. Exiting..." << endl;
				system("cls");
				break;
			}
		}
	}

	cout << "Enter the amount to send: ";
	cin >> amount;


	if (amount <= userBalance && amount >= 0) {

		userBalance -= amount;


		cout << "Transfer to " << recipientName << " of " << amount << " lv is successful." << endl;
	}
	else {
		cout << "Transaction failed. Please check your balance and the entered amount." << endl;
	}

	while (true) {
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
			cout << "Esc key pressed. Exiting..." << endl;
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
	

	
	
	if (amountToLeave <= newBalance && amountToLeave > 0) {
		
		updateBalance(newBalance, -amountToLeave);


		cout << inheritorFullName << " will inherit " << amountToLeave << " lv." << endl;
	}
	else {

		cout << "Not enough money. Please check your balance and the entered amount." << endl;
	}
	

	while (true) {
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
			cout << "Esc key pressed. Exiting..." << endl;
			system("cls");
			break;
		}
	}
}

