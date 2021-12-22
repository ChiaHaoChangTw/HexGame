HexBoardTester: HexBoardTester.o HexBoard.o
	g++ -std=c++11 -Wall -ggdb HexBoardTester.o HexBoard.o -o HexBoardTester

HexBoardTester.o: HexBoardTester.cpp HexBoard.h
	g++ -std=c++11 -Wall -ggdb -c HexBoardTester.cpp

HexBoard.o: HexBoard.cpp HexBoard.h
	g++ -std=c++11 -Wall -ggdb -c HexBoard.cpp