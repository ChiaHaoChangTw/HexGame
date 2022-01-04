// Name: Chia-Hao Chang
// GitHub: ChiaHaoChangTw
// Hex Board Game with AI Player by Monte Carlo Method
// Fall 2021

#include "HexBoard.h"
#include "AiSimulator.h"

#include <iostream>
using namespace std;

class HexBoardGame(){
public:
	HexBoardGame();
	~HexBoardGame();
	void playWithHuman();
	void playWithAi();
private:
	void humanMove(char& player, bool& gameOver);
	void aiMove(char& player, bool& gameOver);
}

void HexBoardGame::humanMove(HexBoard*& hexBoard, char& player, bool& gameOver){
	int x, y;
	cout << "Current hex board: " << endl;
	hexBoard->printHexBoard();
	cout << "Human player using " << player << ", your turn: ";
	bool done = false;
	while(!done){
		cin >> x >> y;
		if(cin.fail() || x < 0 || x >= hexBoard->getHexBoardSize() || y < 0 || y >= hexBoard->getHexBoardSize() || hexBoard->getHexBoardPoint(x, y) != '.'){
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Invalid move. Please try again." << endl;
		}
		else{
			cin.ignore(INT_MAX, '\n');
			done = true;
		}
	}
	hexBoard->getHexBoardPoint(x, y) = player;
	gameOver = hexBoard->isWin(player);
	cout << endl << endl;
	if(!gameOver){
		player = (player == 'x') ? 'o' : 'x';
	}
	return;
}

int main(){

}