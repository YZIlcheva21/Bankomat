#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;

// Function to set the console cursor position to (x, y)
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

const int consoleWidth = 80;

// Function to center text within the console
void centerText(const string& text) {
	// Calculate the padding needed to center the text
	int padding = (consoleWidth - text.length()) / 2;
	cout << setw(padding + text.length()) << text << endl;
}