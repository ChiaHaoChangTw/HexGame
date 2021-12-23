// Name: Chia-Hao Chang
// GitHub: ChiaHaoChangTw
// Hex Board Game with AI Player by Monte Carlo Method
// Fall 2021

#include "HexBoard.h"

#ifndef AISIMULATOR_H
#define AISIMULATOR_H

#include <vector>
#include <utility>

class AiSimulator{
public:
	static const int TARGET_NUM_SIM = 10000;
	int simulate(HexBoard& currHexBoard, int x, int y, int player);
private:
	std::vector<std::pair<int, int>> emptyPositions;
	void findEmpty(const HexBoard& currHexBoard);
};

#endif
