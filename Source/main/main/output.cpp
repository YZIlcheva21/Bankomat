#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;

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

void centerText(const string& text) {
	int padding = (consoleWidth - text.length()) / 2;
	cout << setw(padding + text.length()) << text << endl;
}