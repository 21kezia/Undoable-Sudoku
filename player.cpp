#include "player.h"


player::player() {
	matchCount = 0;
	winCount = 0;
}
player::player(string username, int MatchCount, int WinCount) {
	matchCount = MatchCount;
	winCount = WinCount;
}
void player::setMatchCount(int match) {
	matchCount = match;
}
int player::getMatchCount() {
	return matchCount;
}
void player::setUsername(string name) {
	username = name;
}
string player::getUsername() {
	return username;
}
void player::setWinCount(int WinCount) {
	winCount = WinCount;
}
int player::getWinCount() {
	return winCount;
}
