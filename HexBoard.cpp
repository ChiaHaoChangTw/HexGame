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

#include "HexBoard.h"

#include <iostream>
#include <vector>
#include <string>
#include <assert.h>

using namespace std;

/** 
 * Create a default HexBoard object with 5 * 5 board size.
 *
 */
HexBoard::HexBoard(){
	this->hexBoardSize = DEFAULT_BOARD_SIZE;
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
				cout << BLUE << j << RESET << ((j >= TWO_DIGITS) ? "  " : "   ");
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
 * Return true if the player wins.
 *
 */
bool HexBoard::isWin(char player){
	vector<vector<bool>> visited = vector<vector<bool>>(this->hexBoardSize, vector<bool>(this->hexBoardSize, false));
	bool foundPath = false;
	for(int i = 0; i < this->hexBoardSize; ++i){
		if(player == 'x'){
			if(visited[i][0]){
				continue;
			}
			if(this->hexBoardDetails[i][0] != 'x'){
				visited[i][0] = true;
				continue;
			}
			foundPath = this->hasPath(i, 0, player, visited);
			if(foundPath){
				break;
			}
		}
		else{
			if(visited[0][i]){
				continue;
			}
			if(this->hexBoardDetails[0][i] != 'o'){
				visited[0][i] = true;
				continue;
			}
			foundPath = this->hasPath(0, i, player, visited);
			if(foundPath){
				break;
			}
		}
	}
	return foundPath;
}

/**
 * Return true if there exists a winning path for the player.
 *
 */
bool HexBoard::hasPath(int i, int j, char player, std::vector<std::vector<bool>>& visited){
	if((player == 'x' && j == this->hexBoardSize - 1) || (player == 'o' && i == this->hexBoardSize - 1)){
		return true;
	}
	vector<vector<int>> offsets = {{0,1},{1,0},{0,-1},{-1,0},{1,-1},{-1,1}};
	visited[i][j] = true;
	bool foundPath = false;
	for(auto& offset: offsets){
		int ii = i + offset[0], jj = j + offset[1];
		if(ii < 0 || ii >= this->hexBoardSize || jj < 0 || jj >= this->hexBoardSize || visited[ii][jj]){
			continue;
		}
		if(this->hexBoardDetails[ii][jj] != player){
			visited[ii][jj] = true;
			continue;
		}
		foundPath = hasPath(ii, jj, player, visited);
		if(foundPath){
			break;
		}
	}
	return foundPath;
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
