// Name: Chia-Hao Chang
// GitHub: ChiaHaoChangTw
// Hex Board Game with AI Player by Monte Carlo Method
// Fall 2021

#ifndef HEXBOARD_H
#define HEXBOARD_H

/** 
 * class HexBoard
 * A hex board, with n * n size, enables users to set or get values on it.
 * Hex board could also be printed on users' terminals.
 *
 */

#include <vector>

#define RESET "\033[0m" 
#define RED   "\033[31m"    
#define BLUE  "\033[34m"  

class HexBoard{
public:
	/** 
 	 * Default size of board.
 	 * Beginning of two-digit number.
     *
     */
	static const int DEFAULT_BOARD_SIZE = 5;
	static const int TWO_DIGITS = 10;
	/** 
 	 * Create a default HexBoard object with 5 * 5 board size.
     *
     */
	HexBoard();
	/** 
     * Create an user-defined HexBoard object with board size defined by user.
     *
     */
	HexBoard(int userDefinedSize);
	/** 
     * Deconstruct HexBoard object.
     */
	~HexBoard();
	/** 
     * Print out hex board details on user's terminal.
 	 * x axis as BLUE, and y axis as RED.
 	 *
 	 */
	void printHexBoard();
	/** 
 	 * Return side length of HexBoard object.
 	 *
 	 */
	int getHexBoardSize();
	/** 
 	 * Return char value of point (x, y) on HexBoard object.
 	 * x is horizontal axis, and y is vertical axis.
 	 * 
 	 * PRE1: 0 <= x < hexBoardSize
 	 * PRE2: 0 <= y < hexBoardSize
 	 *
 	 */
	char getHexBoardPoint(int x, int y);
	/** 
 	 * Return true if successfully set point (x, y) val on HexBoard object.
 	 * Otherwise, retrun false.
 	 * x is horizontal axis, and y is vertical axis.
 	 *
 	 * PRE1: 0 <= x < hexBoardSize
 	 * PRE2: 0 <= y < hexBoardSize
 	 *
 	 */
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
	std::vector<std::vector<char>> hexBoardDetails;
	/** 
 	 * Return true if HexBaord object data is in valid state.
 	 * (See representation invariant comment for details.)
 	 *
 	 */
	bool isValidHexBoard();
};

#endif