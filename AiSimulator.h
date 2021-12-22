// Name: Chia-Hao Chang
// GitHub: ChiaHaoChangTw
// Hex Board Game with AI Player by Monte Carlo Method
// Fall 2021

#include "HexBoard.h"

#ifndef AISIMULATOR_H
#define AISIMULATOR_H

class AiSimulator{
public:
	int simulate(const HexBoard& currHexBoard, int x, int y, int player);
private:
	void findEmpty();
};

#endif