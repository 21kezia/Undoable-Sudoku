#pragma once
#include "board.h"
#include "player.h"

class gameManager
{
	board b;
	player p;
	string username;
	string playBoard[9][9];

public:
	gameManager();
	gameManager(player Player, board Board);
	void play();
	bool checkWin();
};
