// Name: Chia-Hao Chang
// GitHub: ChiaHaoChangTw
// Hex Board Game with AI Player by Monte Carlo Method
// Fall 2021

#ifndef HEXBOARDGAME_H
#define HEXBOARDGAME_H

class HexBoardGame{
public:
	bool findPath(int x, int y, char symbol, std::vector<std::vector<bool>>& visited);
	bool checkWin(int turn);
	void move(int& turn, bool& gameOver);
	void humMove(int& turn, bool& gameOver);
	void aiMove(int& turn, bool& gameOver);
	void play();
	void playWithAi();
private:
};

#endif