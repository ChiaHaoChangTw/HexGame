// Name: Chia-Hao Chang
// GitHub: ChiaHaoChangTw
// Hex Board Game with AI Player by Monte Carlo Method
// Fall 2021

/** 
 * class HexBoard
 * A hex board, with n * n size, enables users to set or get values on it.
 * Hex board could also be printed on users' terminals.
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <assert.h>

#define RESET "\033[0m" 
#define RED   "\033[31m"    
#define BLUE  "\033[34m"  

using namespace std;

class HexBoard{
public:
	HexBoard();
	HexBoard(int userDefinedSize);
	~HexBoard();
	void printHexBoard();
	int getHexBoardSize();
	char getHexBoardPoint(int x, int y);
	bool setHexBoardPoint(int x, int y, char val);

	/**
	 * Representation invariants:
	 * a) hexBoardSize should >= 2
	 * b) hexBoardDetails.size() should == hexBoardSize
	 * c) hexBoardDetails[0].size() should == hexBoardSize
	 * 
	 */

private:
	int hexBoardSize;
	vector<vector<char>> hexBoardDetails;
	bool isValidHexBoard();
};

/** 
 * Create a default HexBoard object with 5 * 5 board size.
 *
 */
HexBoard::HexBoard(){
	this->hexBoardSize = 5;
	this->hexBoardDetails = vector<vector<char>>(this->hexBoardSize, vector<char>(this->hexBoardSize, '.'));
}

/** 
 * Create an user-defined HexBoard object with board size defined by user.
 *
 */
HexBoard::HexBoard(int userDefinedSize){
	this->hexBoardSize = userDefinedSize;
	this->hexBoardDetails = vector<vector<char>>(this->hexBoardSize, vector<char>(this->hexBoardSize, '.'));
}

/** 
 * Deconstruct HexBoard object.
 */
HexBoard::~HexBoard(){}

/** 
 * Print out hex board details on user's terminal.
 * x axis as BLUE, and y axis as RED.
 *
 */
void HexBoard::printHexBoard(){
	string indent = "    ";
	cout << BLUE << "  x" << endl << RED << "y" << endl << RESET;
	for(int i = 0; i < this->hexBoardSize; ++i){
		cout << indent;
		for(int j = 0; j < this->hexBoardSize; ++j){
			cout << this->hexBoardDetails[i][j];
			if(j < this->hexBoardSize - 1){
				cout << " - ";
			}
		}
		indent += " ";
		cout << " " << RED << i << RESET << endl << indent;
		if(i != this->hexBoardSize - 1){
			cout << "\\ ";
			for(int j = 1; j < this->hexBoardSize; ++j){
				cout << "/ \\ ";
			}
		}
		else{
			for(int j = 0; j < this->hexBoardSize; ++j){
				cout << BLUE << j << RESET << ((j >= 10) ? "  " : "   ");
			}
		}
		cout << endl;
		indent += " "; 
	}
	assert(isValidHexBoard());
	return;
}

/** 
 * Return side length of HexBoard object.
 *
 */
int HexBoard::getHexBoardSize(){
	assert(isValidHexBoard());
	return this->hexBoardSize;
}

/** 
 * Return char value of point (x, y) on HexBoard object.
 * x is horizontal axis, and y is vertical axis.
 * 
 * PRE1: 0 <= x < hexBoardSize
 * PRE2: 0 <= y < hexBoardSize
 *
 */
char HexBoard::getHexBoardPoint(int x, int y){
	assert(x >= 0 && x < this->hexBoardSize && y >= 0 && y < this->hexBoardSize);
	assert(isValidHexBoard());
	return this->hexBoardDetails[y][x];
}

/** 
 * Return true if successfully set point (x, y) val on HexBoard object.
 * Otherwise, retrun false.
 * x is horizontal axis, and y is vertical axis.
 *
 * PRE1: 0 <= x < hexBoardSize
 * PRE2: 0 <= y < hexBoardSize
 *
 */
bool HexBoard::setHexBoardPoint(int x, int y, char val){
	assert(x >= 0 && x < this->hexBoardSize && y >= 0 && y < this->hexBoardSize);
	if(x < 0 || x >= this->hexBoardSize || y < 0 || y >= this->hexBoardSize){
		assert(isValidHexBoard());
		return false;
	}
	this->hexBoardDetails[y][x] = val;
	assert(isValidHexBoard());
	return true;
}

/** 
 * Return true if HexBaord object data is in valid state.
 * (See representation invariant comment for details.)
 *
 */
bool HexBoard::isValidHexBoard(){
	if(this->hexBoardSize < 2 || this->hexBoardDetails.size() != this->hexBoardSize || this->hexBoardDetails[0].size() != this->hexBoardSize){
		return false;
	}
	return true;
}


