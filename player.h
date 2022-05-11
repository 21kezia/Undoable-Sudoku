#pragma once
#include <iostream>
#include <string>
using namespace std;

class player
{
	string username;
	int matchCount;
	int winCount;
	
public:
	player();
	player(string username, int MatchCount, int WinCount);
	void setMatchCount(int match);
	int getMatchCount();
	void setUsername(string name);
	string getUsername();
	void setWinCount(int winCount);
	int getWinCount();
};
