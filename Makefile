#HexGame
HexGame: HexGame.o AiSimulator.o HexBoard.o
	g++ -std=c++11 -Wall -ggdb HexGame.o AiSimulator.o HexBoard.o -o HexGame

HexGame.o: HexGame.cpp AiSimulator.h HexBoard.h
	g++ -std=c++11 -Wall -ggdb -c HexGame.cpp

#AiSimulatorTester
AiSimulatorTester: AiSimulatorTester.o AiSimulator.o HexBoard.o
	g++ -std=c++11 -Wall -ggdb AiSimulatorTester.o AiSimulator.o HexBoard.o -o AiSimulatorTester

AiSimulatorTester.o: AiSimulatorTester.cpp AiSimulator.h HexBoard.h
	g++ -std=c++11 -Wall -ggdb -c AiSimulatorTester.cpp

AiSimulator.o: AiSimulator.cpp AiSimulator.h HexBoard.h
	g++ -std=c++11 -Wall -ggdb -c AiSimulator.cpp

#HexBoardTester
HexBoardTester: HexBoardTester.o HexBoard.o
	g++ -std=c++11 -Wall -ggdb HexBoardTester.o HexBoard.o -o HexBoardTester

HexBoardTester.o: HexBoardTester.cpp HexBoard.h
	g++ -std=c++11 -Wall -ggdb -c HexBoardTester.cpp

HexBoard.o: HexBoard.cpp HexBoard.h
	g++ -std=c++11 -Wall -ggdb -c HexBoard.cpp
