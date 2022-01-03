#include "HexBoard.h"
#include <iostream>
using namespace std;

int main(){

	HexBoard* myDefaultHexBoard = new HexBoard();
	myDefaultHexBoard->printHexBoard();
	cout << "Size of this board is [exp: 5]: " << myDefaultHexBoard->getHexBoardSize() << endl;
	cout << "Get char val at point (1, 2) [exp: '.']: " << myDefaultHexBoard->getHexBoardPoint(1, 2) << endl;
	cout << "Set point (1, 2) as x: " << myDefaultHexBoard->setHexBoardPoint(1, 2, 'x') << endl;
	cout << "Get char val at point (1, 2) [exp: 'x']: " << myDefaultHexBoard->getHexBoardPoint(1, 2) << endl << "New board: " << endl;
	myDefaultHexBoard->printHexBoard();

	HexBoard* myDefinedHexBoard = new HexBoard(13);
	myDefinedHexBoard->printHexBoard();
	cout << "Size of this board is [exp: 13]: " << myDefinedHexBoard->getHexBoardSize() << endl;
	cout << "Get char val at point (0, 0) [exp: '.']: " << myDefinedHexBoard->getHexBoardPoint(0, 0) << endl;
	cout << "Set point (10, 9) as o: " << myDefinedHexBoard->setHexBoardPoint(10, 9, 'o') << endl;
	cout << "Get char val at point (10, 9) [exp: 'o']: " << myDefinedHexBoard->getHexBoardPoint(10, 9) << endl << "New board: " << endl;
	myDefinedHexBoard->printHexBoard();

	cout << "Current hex board: " << endl;
	myDefaultHexBoard->printHexBoard();
	cout << "x wins in current hex board [exp: 0]:" << endl;
	cout << myDefaultHexBoard->isWin('x') << endl;
	cout << "o wins in current hex board [exp: 0]:" << endl;
	cout << myDefaultHexBoard->isWin('o') << endl << endl;

	myDefaultHexBoard->setHexBoardPoint(0,2,'x'), myDefaultHexBoard->setHexBoardPoint(2,1,'x');
	myDefaultHexBoard->setHexBoardPoint(3,0,'x'), myDefaultHexBoard->setHexBoardPoint(4,0,'x');
	cout << "Current hex board: " << endl;
	myDefaultHexBoard->printHexBoard();
	cout << "x wins in current hex board [exp: 1]:" << endl;
	cout << myDefaultHexBoard->isWin('x') << endl;
	cout << "o wins in current hex board [exp: 0]:" << endl;
	cout << myDefaultHexBoard->isWin('o') << endl << endl;

	myDefaultHexBoard->setHexBoardPoint(0,3,'o'), myDefaultHexBoard->setHexBoardPoint(1,3,'o');
	myDefaultHexBoard->setHexBoardPoint(2,3,'o'), myDefaultHexBoard->setHexBoardPoint(3,3,'o'), myDefaultHexBoard->setHexBoardPoint(4,3,'o');
	cout << "Current hex board: " << endl;
	myDefaultHexBoard->printHexBoard();
	cout << "x wins in current hex board [exp: 1]:" << endl;
	cout << myDefaultHexBoard->isWin('x') << endl;
	cout << "o wins in current hex board [exp: 0]:" << endl;
	cout << myDefaultHexBoard->isWin('o') << endl << endl;
	
	myDefaultHexBoard->setHexBoardPoint(0,0,'o'), myDefaultHexBoard->setHexBoardPoint(0,1,'o');
	myDefaultHexBoard->setHexBoardPoint(0,2,'o'), myDefaultHexBoard->setHexBoardPoint(3,4,'o');
	cout << "Current hex board: " << endl;
	myDefaultHexBoard->printHexBoard();
	cout << "x wins in current hex board [exp: 0]:" << endl;
	cout << myDefaultHexBoard->isWin('x') << endl;
	cout << "o wins in current hex board [exp: 1]:" << endl;
	cout << myDefaultHexBoard->isWin('o') << endl << endl;

	return 0;
}