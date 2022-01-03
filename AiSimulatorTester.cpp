#include "AiSimulator.h"
#include "HexBoard.h"
#include <iostream>
using namespace std;

int main(){
	HexBoard* hexBoard = new HexBoard();
	hexBoard->setHexBoardPoint(0,1,'o'), hexBoard->setHexBoardPoint(0,2,'o');
	hexBoard->setHexBoardPoint(0,3,'x'), hexBoard->setHexBoardPoint(0,0,'x');
	cout << "Current hex board:" << endl;
	hexBoard->printHexBoard();
	AiSimulator* simulator = new AiSimulator();
	cout << "1st simulation for x at positon (1,3): ";
	cout << simulator->simulate(hexBoard,1,3,'x') << endl;
	cout << "2nd simulation for x at positon (1,3): ";
	cout << simulator->simulate(hexBoard,1,3,'x') << endl;
	cout << "3rd simulation for x at positon (1,3): ";
	cout << simulator->simulate(hexBoard,1,3,'x') << endl;
	cout << "1st simulation for o at positon (1,3): ";
	cout << simulator->simulate(hexBoard,1,3,'o') << endl;
	cout << "2nd simulation for o at positon (1,3): ";
	cout << simulator->simulate(hexBoard,1,3,'o') << endl;
	cout << "3rd simulation for o at positon (1,3): ";
	cout << simulator->simulate(hexBoard,1,3,'o') << endl;
}