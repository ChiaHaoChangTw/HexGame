// Name: Chia-Hao Chang
// GitHub: ChiaHaoChangTw
// Hex Board Game with AI Player by Monte Carlo Method
// Fall 2021

#include "HexBoard.h"
#include "AiSimulator.h"

#include <random>
#include <vector>
#include <pair>

using namespace std;

int AiSimulator::simulate(HexBoard& currHexBoard, int x, int y, int player){
	int numSim = 0, numWin = 0;
	vector<pair<int, int>> shuffleEmptyPos = emptyPositions, simPlayerPos;
	srand(time(0));
	while(numSim < TARGET_NUM_SIM){
		random_shuffle(shuffleEmptyPos.begin(), shuffleEmptyPos.end());
		int i = 0, numFilled = 0, numToFill = static_cast<int> ((shuffleEmptyPos.size() - 1) / 2);
		//start here
		++numSim;
	}	
	return numWin;
}

void AiSimulator::findEmpty(const HexBoard& currHexBoard){
	for(int x = 0; x < currHexBoard.getHexBoardSize(); ++x){
		for(int y = 0; y < currHexBoard.getHexBoardSize(); ++y){
			if(currHexBoard.getHexBoardPoint(x, y) == '.'){
				emptyPositions.push_back(make_pair(x, y));
			}
		}
	}
	return;
}
