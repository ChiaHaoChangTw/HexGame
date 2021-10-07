/*
Topic: Implement Monte Carlo Hex move evaluation
Author: Chia-Hao Chang
Date: Jan 12, 2021

Notes:
a) The player should be able to interact with the program and choose its “color” with blue (or x) going first and red (or o) going second.
b) When it is the “AI”’s turn, it is to evaluate all legal available next moves and select a “best” move.
c) Each legal move will be evaluated using  ~1000 or more trials.
d) To evaluate a specific trial, fill up the remaining empty squares on the board and evaluate the filled up board for who won.
e) The ratio: wins/trials are the AI’s metric for picking which next move to make.
f) Be careful about computational cost – do not regenerate boards in making next move calculations.
g) If available, use the new C++11 <random> library to get experience with it.
*/

#include<iostream>
#include<vector>

#include<string>
#include<utility>
#include<queue>
#include<cstdlib>
#include<ctime>
#include<random>
#include<algorithm>
//->
using namespace std;

typedef pair<int, int> intPair;

//Hex game class
class hexG{
	public:
		hexG(); //Default constructor
		hexG(int size); //Parameterized constructor
		~hexG(); //Destructor
		void print(); //Print the hex board
		bool findPath(int x, int y, char symbol, vector<vector<bool>>& visited); //Check if there exists a winning path for a player
		bool checkWin(int turn); //Check if any player wins
		void move(int& turn, bool& gameOver); //Make a move (2 human players)
		void humMove(int& turn, bool& gameOver); //Make a move by the human player (human plays with AI)
		void aiMove(int& turn, bool& gameOver); //Make a move by the computer AI (human plays with AI)
		void play(); //2 humans play
		void playWithAi(); //human plays with AI

	private:
		int size; //The side length of the hex board 
		vector<vector<char>> field; //The hex board details
		vector<intPair> emptySet; //Set to store the empty points in the current hex board
		vector<intPair> emptySetShuffle; //Set to simulate randomized results on the current empty points
		void findEmpty(); //Function to create the emptySet and emptySetShuffle		
		int exeSimu(int x, int y, int turn); //Simulate the result of making the next move to be (x, y)
};

//Default constructor
hexG::hexG(){
	this->size = 7; //Assign the side length of the hex board as 7
	this->field = vector<vector<char>>(this->size, vector<char>(this->size, '.')); //Assign all the points as empty, shown as '.' 
}

//Parameterized constructor
hexG::hexG(int size){
	this->size = size; //Assign the side length of the hex board 
	this->field = vector<vector<char>>(size, vector<char>(size, '.')); //Assign all the points as empty, shown as '.' 
}
//<-
//Destructor
hexG::~hexG(){}

void hexG::print(){
	string indent = "";
	for(int i = 0; i < this->size; ++i){
		cout << indent;
		indent += " ";
		for(int j = 0; j < this->size; ++j){
			cout << this->field[i][j] << " ";
			if(j < this->size - 1){
				cout << "- ";
			}
		}
		cout << endl << indent;
		indent += " ";
		if(i != this->size - 1){
			for(int j = 0; j < this->size; ++j){
				if(j == 0){
					cout << "\\ ";
				}
				else{
					cout << "/ \\ ";
				}
			}
		}
		cout << endl;
	}
}

bool hexG::findPath(int x, int y, char symbol, vector<vector<bool>>& visited){
	if((symbol == 'x' && y == this->size - 1)||symbol == 'o' && x == this->size - 1)
		return true;
	vector<pair<int, int>>cur_set = {
		{x - 1, y}, {x - 1, y + 1}, {x, y - 1}, {x, y + 1}, {x + 1, y - 1}, {x + 1, y}
	};
	visited[x][y] = true;
	bool found = false;
	for(pair<int, int> node:cur_set){
		if(node.first < 0 || node.first >= this->size || node.second < 0 || node.second >= this->size)
			continue;
		if(visited[node.first][node.second])
			continue;
		if(this->field[node.second][node.first] != symbol){
			visited[node.first][node.second] = true;
			continue;
		}
		found = findPath(node.first, node.second, symbol, visited);
		if(found)
			break;
	}
	return found;
}

bool hexG::checkWin(int turn){
	char symbol = (turn == 0) ? 'x' : 'o';
	vector<vector<bool>>visited = vector<vector<bool>>(this->size, vector<bool>(this->size, false));
	bool found = false;
	for(int i = 0; i < this->size; ++i){
		if(turn == 0){
			if(visited[i][0])
				continue;
			if(this->field[0][i] != 'x'){
				visited[i][0] = true;
				continue;
			}
			found = this->findPath(i, 0, symbol, visited);
			if(found)
				break;
		}
		else if(turn == 1){
			if(visited[0][i])
				continue;
			if(this->field[i][0] != 'o'){
				visited[0][i] = true;
				continue;
			}
			found = this->findPath(0, i, symbol, visited);
			if(found)
				break;
		}
	}
	return found;
}

void hexG::move(int& turn, bool& gameOver){
	int x, y;
	cout << "Field:" << endl;
	this->print();
	cout << "Player " << turn << ", your turn:" << endl;
	while(true){
		cin >> y >> x;
		if(cin.fail() || (x < 0 || x >= this->size || y < 0 || y >= this->size) || this->field[x][y] != '.'){
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Invalid move. Try again." << endl;
		}
		else{
			cin.ignore(32767, '\n');
			break;
		}
	}
	this->field[x][y] = (turn == 0) ? 'x':'o';
	gameOver = this->checkWin(turn);
	cout << endl << endl;
	if(gameOver == false)
		turn = !turn;
}

void hexG::humMove(int& turn, bool& gameOver){
	int x, y;
	cout << "Field:" << endl;
	this->print();
	cout << "Human player, your turn:" << endl;
	while(true){
		cin >> y >> x;
		if(cin.fail() || (x < 0 || x >= this->size || y < 0 || y >= this->size) || this->field[x][y] != '.'){
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Invalid move. Try again." << endl;
		}
		else{
			cin.ignore(32767, '\n');
			break;
		}
	}
	this->field[x][y] = (turn == 0) ? 'x':'o';
	gameOver = this->checkWin(turn);
	cout << endl << endl;
	if(gameOver == false)
		turn = !turn;
}

void hexG::findEmpty(){
	for(int i = 0; i < this->size; ++i){
		for(int j = 0; j < this->size; ++j){
			if(field[i][j] == '.'){
				emptySet.push_back(intPair(i, j));
				emptySetShuffle.push_back(intPair(i, j));
			}
		}
	}
}

int hexG::exeSimu(int x, int y, int turn){
	int numSimu = 0, numWin = 0, xSimu, ySimu;
	const int targetSimu = 10000;
	vector<intPair> simuFill;
	srand(time(0));
	while(numSimu < targetSimu){
		random_shuffle(emptySetShuffle.begin(), emptySetShuffle.end());
		auto itr = emptySetShuffle.begin();
		int countSpace = 0, spacesToFill = static_cast<int>((emptySet.size() - 1) / 2);
		while(countSpace < spacesToFill && itr != emptySetShuffle.end()){
			xSimu = itr->second;
			ySimu = itr->first;
			if(xSimu != x || ySimu != y && field[ySimu][xSimu] == '.'){
				simuFill.push_back(intPair(*itr));
				countSpace++;
			}
			itr++;
		}
		for(auto itr = simuFill.begin(); itr < simuFill.end(); ++itr){
			xSimu = itr->second;
			ySimu = itr->first;
			field[ySimu][xSimu] = (turn == 0) ? 'x':'o';
		}
		field[y][x] = (turn == 0) ? 'x':'o';
		if(checkWin(turn)){
			numWin += 1;
		}
		numSimu++;
		for(auto itr = simuFill.begin(); itr < simuFill.end(); ++itr){
			xSimu = itr->second;
			ySimu = itr->first;
			field[ySimu][xSimu] = '.';
		}
		field[y][x] = '.';
		simuFill.clear();
	}
	return numWin;
}

void hexG::aiMove(int& turn, bool& gameOver){
	cout << "Field:" << endl;
	this->print();
	cout << "Computer AI is playing..." << endl;
	int x, y, bestX, bestY;
	pair<int, intPair> bestP;
	priority_queue<pair<int, intPair>> pq;
	findEmpty();
	for(auto i = emptySet.begin(); i < emptySet.end(); ++i){
		x = i->second;
		y = i->first;
		int numWin = exeSimu(x, y, turn);
		pq.push(make_pair(numWin, intPair(x, y)));
	}
	bestP = pq.top();
	bestX = bestP.second.first;
	bestY = bestP.second.second;
	while(this->field[bestY][bestX] != '.'){
		pq.pop();
		bestP = pq.top();
		bestX = bestP.second.first;
		bestY = bestP.second.second;
	}
	this->field[bestY][bestX] = (turn == 0) ? 'x':'o';
	while(!pq.empty()){
		pq.pop();
	}
	emptySet.clear();
	emptySetShuffle.clear();
	
	gameOver = this->checkWin(turn);
	cout << endl << endl;
	if(gameOver == false)
		turn = !turn;
}

void hexG::play(){
	bool gameOver = false;
	int turn = 0;
	cout << "Player 0 should connect the North and the South sides of the field to win" << endl;
	cout << "Player 1 should connect the West and the East sides of the field to win" << endl;
	cout << "Your input should look like: x y" << endl;
	
	while(gameOver == false)
		this->move(turn, gameOver);
		
	this->print();
	cout << "Congratulations, Player " << turn << "! You win!" << endl << endl;
}

void hexG::playWithAi(){
	bool gameOver = false;
	int turn = 0;
	char humFirst = 'N';
	cout << "Please choose whether you want to move first or not. Input Y if you want to move first, and input N if you want AI to move first: ";
	cin >> humFirst;
	cout << endl;
	
	if(humFirst == 'N'){
		cout << "AI should connect the North and the South sides of the field to win. AI's symbol is x." << endl;
		cout << "You should connect the West and the East sides of the field to win. Your symbol is o. Your input should look like: x y" << endl << endl;
		while(gameOver == false){
			if(turn == 0){
				this->aiMove(turn, gameOver);
			}
			else{
				this->humMove(turn, gameOver);
			}
		}
		this->print();
		if(turn == 0){
			cout << "AI win!" << endl << endl;
		}
		else{
			cout << "Congratulations, You win!" << endl << endl;
		}
	}
	
	if(humFirst == 'Y'){
		cout << "You should connect the North and the South sides of the field to win. Your symbol is x. Your input should look like: x y" << endl;
		cout << "AI should connect the West and the East sides of the field to win. AI's symbol is o." << endl << endl;
		while(gameOver == false){
			if(turn == 1){
				this->aiMove(turn, gameOver);
			}
			else{
				this->humMove(turn, gameOver);
			}
		}
		this->print();
		if(turn == 1){
			cout << "AI win!" << endl << endl;
		}
		else{
			cout << "Congratulations, You win!" << endl << endl;
		}
	}	
}
//->
//The main function
int main(void){
	int size; //The size of the hex game
	char who; //Determine players
	cout << "======================================================================================" << endl;
	cout << "Welcome to the game!" << endl;
	cout << "Please enter a size of the hex board game." << endl;
	cout << "If the entry is less than 2 or lager than 10, the game will use 7 as the default." \
				<< endl \
				<< "Please enter here: ";
	cin >> size; //User defines the game size
	cout << "======================================================================================" << endl;
	cout << "Do you want to paly with the AI?" << endl;
	cout << "Input Y if you want to paly with the AI, and input N if you want to play with a human: " \
				<< endl;
	cin >> who; //User decides the players
	if(who == 'Y'){ //Play with the AI
		if(size < 2 || size > 10){ //If the size is out of the scope or too big
			hexG game; //Initialize the hex game
			game.playWithAi();
			return 0;
		}
		else{ //Use the user-defined size
			hexG game(size); //Initialize the hex game
			game.playWithAi();
			return 0;
		}
	}
	if(who == 'N'){ //Two humans play
		if(size < 2 || size > 10){ //If the size is out of the scope or too big
			hexG game; //Initialize the hex game
			game.play();
			return 0;
		}
		else{ //Use the user-defined size
			hexG game(size); //Initialize the hex game
			game.play();
			return 0;
		}
	}
}
//<-