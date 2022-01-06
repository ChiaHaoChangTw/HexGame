// Name: Chia-Hao Chang
// GitHub: ChiaHaoChangTw
// Hex Board Game with AI Player by Monte Carlo Method
// Fall 2021

/** 
 * class AiSimulator
 * A simulator to randomly generate the results of a certain computer AI move.
 *
 */

#include "HexBoard.h"
#include "AiSimulator.h"

#include <random>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

/** 
 * Create an AI simulator object.
 *
 */
AiSimulator::AiSimulator(HexBoard*& currHexBoard){
	this->findEmpty(currHexBoard);
}

/** 
 * Deconstruct AiSimulator object.
 */
AiSimulator::~AiSimulator(){}

/** 
 * Return empty position pairs.
 *
 */
vector<pair<int, int>> AiSimulator::getEmptyPositions(){
	return emptyPositions;
}

/** 
 * Return the number of winning simlualtion.
 *
 */
int AiSimulator::simulate(HexBoard*& currHexBoard, int x, int y, char player){
	int numSim = 0, numWin = 0;
	vector<pair<int, int>> shuffleEmptyPos = emptyPositions;
	srand(time(0));
	while(numSim < TARGET_NUM_SIM){
		vector<pair<int, int>> simPlayerPos;
		random_shuffle(shuffleEmptyPos.begin(), shuffleEmptyPos.end());
		int pos = 0, numFilled = 0, numToFill = static_cast<int> ((shuffleEmptyPos.size() - 1) / 2);
		currHexBoard->setHexBoardPoint(x, y, player);
		while(pos < shuffleEmptyPos.size() && numFilled < numToFill){
			int xSim = shuffleEmptyPos[pos].first, ySim = shuffleEmptyPos[pos].second;
			if((xSim != x || ySim != y) && currHexBoard->getHexBoardPoint(xSim, ySim) == '.'){
				simPlayerPos.push_back(make_pair(xSim, ySim));
				currHexBoard->setHexBoardPoint(xSim, ySim, player);
				++numFilled;
			}
			++pos;
		}
		if(currHexBoard->isWin(player)){
			++numWin;
		}
		currHexBoard->setHexBoardPoint(x, y, '.');
		for(int i = 0; i < simPlayerPos.size(); ++i){
			currHexBoard->setHexBoardPoint(simPlayerPos[i].first, simPlayerPos[i].second, '.');
		}
		++numSim;
	}	
	return numWin;
}

/** 
 * Helper function to find and create a set of empty positions.		
 *
 */
void AiSimulator::findEmpty(HexBoard*& currHexBoard){
	emptyPositions.clear();
	for(int x = 0; x < currHexBoard->getHexBoardSize(); ++x){
		for(int y = 0; y < currHexBoard->getHexBoardSize(); ++y){
			if(currHexBoard->getHexBoardPoint(x, y) == '.'){
				emptyPositions.push_back(make_pair(x, y));
			}
		}
	}
	return;
}