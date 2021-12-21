#include "HexBoard.h"
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

	return 0;
}