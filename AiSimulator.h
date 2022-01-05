// Name: Chia-Hao Chang
// GitHub: ChiaHaoChangTw
// Hex Board Game with AI Player by Monte Carlo Method
// Fall 2021

#include "HexBoard.h"

#ifndef AISIMULATOR_H
#define AISIMULATOR_H

/** 
 * class AiSimulator
 * A simulator to randomly generate the results of a certain computer AI move.
 *
 */

#include <vector>
#include <utility>

class AiSimulator{
public:
	/** 
 	 * How many times to simulate.
     *
     */
	static const int TARGET_NUM_SIM = 10000;
	/** 
 	 * Create an AI simulator object.
     *
     */
	AiSimulator();
	/** 
     * Deconstruct AiSimulator object.
     */
	~AiSimulator();
	/** 
 	 * Return empty position pairs.
 	 *
 	 */
	std::vector<std::pair<int, int>> getEmptyPositions();
	/** 
 	 * Return the number of winning simlualtion.
 	 *
 	 */
	int simulate(HexBoard*& currHexBoard, int x, int y, char player);
private:
	std::vector<std::pair<int, int>> emptyPositions;
	/** 
 	 * Helper function to find and create a set of empty positions.		
 	 *
 	 */
	void findEmpty(HexBoard*& currHexBoard);
};

#endif