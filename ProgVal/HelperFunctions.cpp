#include <Windows.h>
#include <cstdio>
#include <string>

void gotoxy(short x, short y) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { x, y };
	SetConsoleCursorPosition(hStdout, position);
}
void printColouredText(std::string text, int colour) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
	printf(text.c_str());
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); //Default colour
}
