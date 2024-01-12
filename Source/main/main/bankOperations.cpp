#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

int userBalance = 10000;

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


	
	
	if (amountToLeave <= userBalance && amountToLeave > 0) {

		updateBalance(userBalance, -amountToLeave);


		cout << "Transfer to " << inheritorFullName << " of " << amountToLeave << " lv is successful." << endl;
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

