// Name: Chia-Hao Chang
// GitHub: ChiaHaoChangTw
// Hex Board Game with AI Player by Monte Carlo Method
// Fall 2021

#include "HexBoard.h"
#include "AiSimulator.h"

using namespace std;

int AiSimulator::simulate(const HexBoard& currHexBoard, int x, int y, int player){

}

void AiSimulator::findEmpty(const HexBoard& currHexBoard){
	for(int x = 0; x < currHexBoard.getHexBoardSize(); ++x){
		for(int y = 0; y < currHexBoard.getHexBoardSize(); ++y){
			if(getHexBoardPoint(x, y) == '.'){
				emptySet.push_back(intPair(i, j));
				emptySetShuffle.push_back(intPair(i, j));
			}
		}
	}
}