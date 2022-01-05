// Name: Chia-Hao Chang
// GitHub: ChiaHaoChangTw
// Hex Board Game with AI Player by Monte Carlo Method
// Fall 2021

#include "HexBoard.h"
#include "AiSimulator.h"

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

class HexBoardGame(){
public:
	HexBoardGame();
	~HexBoardGame();
	void playWithHuman(HexBoard*& hexBoard);
	void playWithAi(HexBoard*& hexBoard);
private:
	void humanMove(HexBoard*& hexBoard, char& player, bool& gameOver);
	void aiMove(HexBoard*& hexBoard, char& player, bool& gameOver);
}

HexBoardGame::HexBoardGame(){}

HexBoardGame::~HexBoardGame(){}

void HexBoardGame::playWithHuman(HexBoard*& hexBoard){
	bool gameOver = false;
	char player = 'o';
	cout << "Player using o should connect the North and the South sides of the board to win" << endl;
	cout << "Player using x should connect the West and the East sides of the board to win" << endl;
	cout << "Your inputs should look like: x y" << endl << "Player using o goes first." << endl;
	while(!gameOver){
		humanMove(hexBoard, player, gameOver);
	}
	hexBoard->printHexBoard();
	cout << "Congratulations, player using " << player << "! you won!" << endl << endl;
}

void HexBoardGame::playWithAi(HexBoard*& hexBoard){
	bool gameOver = false;
	char humanFirst = "N";
	cout << "Please choose whether you would like to move first or not. Input Y if you would like to move first, and input N if you would like AI to move first: ";
	cin >> humanFirst;
	cout << endl;
	cout << "AI should connect the North and the South sides of the board to win. AI's symbol is o." << endl;
	cout << "You should connect the West and the East sides of the board to win. Your symbol is x. Your input should look like: x y" << endl << endl;
	char player = (humanFirst == "Y") ? "x" : "o";
	while(!gameOver){
		if(player == "o"){
			aiMove(hexBoard, player, gameOver);
		}
		else{
			humanMove(hexBoard, player, gameOver);
		}
		hexBoard->printHexBoard();
		if(player == "o"){
			cout << "AI won! You lost." << endl << endl;
		}
		else{
			cout << "Congratulations, you won!" << endl << endl;
		}
	}
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

void HexBoardGame::aiMove(HexBoard*& hexBoard, char& player, bool& gameOver){
	cout << "Current hex board: " << endl;
	hexBoard->printHexBoard();
	cout << "Computer AI is playing..." << endl;
	AiSimulator* simulator = new AiSimulator();
	simulator->findEmpty(hexBoard);
	vector<pair<int, int>> emptyPositions = simulator->getEmptyPositions();
	priority_queue<vector<int>> pq;
	for(int i = 0; i < emptyPositions.size(); ++i){
		int x = emptyPositions[i].first, y = emptyPositions[i].second;
		pq.push({simulator->simulate(hexBoard, x, y, player), x, y});
	}
	int bestx = pq.top()[1], bexty = pq.top()[2];
	while(!pq.empty() && hexBoard->getHexBoardPoint(bestx, besty) != '.'){
		pq.pop();
		bestx = pq.top()[1], besty = pq.top()[2];
	}
	hexBoard->getHexBoardPoint(bestx, besty) = player;
	gameOver = hexBoard->isWin(player);
	cout << endl << endl;
	if(!gameOver){
		player = (player == 'x') ? 'o' : 'x';
	}
	return;
}

int main(){
	int hexBoardSize;
	char playWithAi;
	cout << "======================================================================================" << endl;
	cout << "Welcome to the game!" << endl << "Please enter a size of the hex board game." << endl << "If the entry is less than 2 or lager than 10, the game will use 7 as the default." \
		 << endl << "Please enter here: ";
	cin >> hexBoardSize;
	cout << "======================================================================================" << endl;
	cout << "Would you like to paly with AI?" << endl << "Input Y if you would like to paly with AI, and input N if you would like to play between two humans: " << endl;
	cin >> playWithAi;
	HexBoardGame* game = new HexBoardGame();
	HexBoard* hexBoard = (hexBoardSize < 2 || hexBoardSize > 10) ? (new HexBoard()) : (new HexBoard(hexBoardSize));
	if(playWithAi == 'Y'){
		game->playWithAi(hexBoard);
	}
	else{
		game->playWithHuman(hexBoard);
	}
}