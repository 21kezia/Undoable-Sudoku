#pragma once
#include <string>
#include <fstream>
#include <set>
#include <iostream>
using namespace std;

class board
{
private:
	char aBoard[9][9] = {};
	string pBoard[9][9];

public:
	board();
	bool notInRow(char arr[][9], int row);
	bool notInColumn(char arr[][9], int col);
	bool notInBox(char arr[][9], int startRow, int startCol);
	bool isValid(char arr[][9], int row, int col);
	bool isValidConfig();
	bool isAvailableAtIndex(int x, int y);
	bool isEmpty();
	bool isFull();
	void setValueAtIndex(int x, int y, char value);
	char getValueAtIndex(int x, int y);
	void boardLoader(string fileName);
	void displayBoard();
};
