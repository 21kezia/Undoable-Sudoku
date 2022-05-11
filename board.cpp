#include "board.h"

board::board() {
    char aBoard[9][9] = { { '5', '3', '.', '.', '7', '.', '.', '.', '.' },
                        { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
                        { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
                        { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
                        { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
                        { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
                        { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
                        { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
                        { '.', '.', '.', '.', '8', '.', '.', '7', '9' } };
}
bool board::notInRow(char arr[][9], int row) {
    // Set to store characters seen so far.
    set<char> st;
    
    for (int i = 0; i < 9; i++) {
        // If already encountered before, return false
        if (st.find(arr[row][i]) != st.end())
            return false;

        // If it is not an empty cell, insert value
        // at the current cell in the set
        if (arr[row][i] != '.')
            st.insert(arr[row][i]);
    }
    return true;
}
bool board::notInColumn(char arr[][9], int col) {
    set<char> st;

    for (int i = 0; i < 9; i++) {

        // If already encountered before, return false
        if (st.find(arr[i][col]) != st.end())
            return false;

        // If it is not an empty cell,
        // insert value at the current cell in the set
        if (arr[i][col] != '.')
            st.insert(arr[i][col]);
    }
    return true;
}
bool board::notInBox(char arr[][9], int startRow, int startCol) {
    set<char> st;

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            char curr = arr[row + startRow][col + startCol];

            // If already encountered before, return false
            if (st.find(curr) != st.end())
                return false;

            // If it is not an empty cell,
            // insert value at current cell in set
            if (curr != '.')
                st.insert(curr);
        }
    }
    return true;}
bool board::isValid(char arr[][9], int row, int col) {
    return notInRow(arr, row) && notInColumn(arr, col) &&
        notInBox(arr, row - row % 3, col - col % 3);
}
bool board::isValidConfig() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {

            // If current row or current column or
            // current 3x3 box is not valid, return false
            if (!isValid(aBoard, i, j))
                return false;
        }
    }
    return true;
}
bool board::isAvailableAtIndex(int x, int y) {
    if (aBoard[x][y] == '.')
        return true;
    else
        return false;
}
bool board::isEmpty() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {

            if (aBoard[i][j] != '.')
                return false;
        }
    }
    return true;
}
bool board::isFull() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {

            if (aBoard[i][j] == '.')
                return false;
        }
    }
    return true;
}
void board::setValueAtIndex(int x, int y, char value) {
    aBoard[x][y] = value;
}
char board::getValueAtIndex(int x, int y) {
    return aBoard[x][y];
}
void board::boardLoader(string fileName) {

    ifstream readBoard(fileName);
    string line;
    if (readBoard.is_open()) {


        for (int row = 0; getline(readBoard, line); row++) {
            for (int i = 0; i < 9; i++) {

                int found = line.find_first_of(" ");

                pBoard[row][i].assign(line, 0, found);

                line.erase(0, found + 1);
            }
        }

        readBoard.close();
    }
    else {
        cout << "Unable to open file\n\n";
    }
}

void board::displayBoard() {
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0 && i != 0) {
            cout << endl;
        }
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0 && j != 0) {
                cout << "\t";
            }
            cout << aBoard[i][j];
        }
        cout << endl;
    }
}
