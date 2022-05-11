#include "gameManager.h"

gameManager::gameManager() {
    
}
gameManager::gameManager(player Player, board Board) {
	b = Board;
	p = Player;
}
void gameManager::play() {
    b.boardLoader("sudokuTxt");

    if (p.getUsername() == "") {
        cout << "Insert username: ";
        cin >> username;
        p.setUsername(username);
    }

    while (!checkWin())
    {
        int row, col, value;
        system("cls");
        b.displayBoard();

        cout << endl << endl;
        cout << "Insert row: ";
        cin >> row;
        cout << "Insert column: ";
        cin >> col;
        cout << "Insert value (1-9): ";
        cin >> value;

        b.setValueAtIndex(row - 1, col - 1, value);

    }

    system("cls");
    b.displayBoard();

    cout << "Congratulations! You have completed the Sudoku.\n\n";

    p.setWinCount(p.getWinCount() + 1);
    p.setMatchCount(p.getMatchCount() + 1);

    cout << "Stat: \n";

    cout << p.getUsername() << endl;
    cout << "Match Total: " << p.getMatchCount() << endl;
    cout << "Win Total: " << p.getWinCount() << endl << endl;
}
bool gameManager::checkWin() {
	if (b.isValidConfig() && b.isFull()) {
		return true;
	}
	else
		return false;
}
