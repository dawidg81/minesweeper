#include "Game.hpp"

#include <ctime>
#include <iostream>

using namespace std;

int main(){

	Game game;
	game.inGame = false;
	int choice;

	cout << "Welcome to minesweeper v0.2.0\n";
	cout << "\n";
	cout << "Select difficulty:\n"
		"1. Easy\n"
		"2. Medium\n"
		"3. Hard\n"
		"4. Custom\n";
	cout << "Difficulty: ";
	cin >> choice;

	if(choice == 1){
		game.initDiff(0);
		game.inGame = true;
	} else if(choice == 2){
		game.initDiff(1);
		game.inGame = true;
	} else if(choice == 3){
		game.initDiff(2);
		game.inGame = true;
	} else if(choice == 4){
		game.editDiff();
		game.inGame = true;
	}

	srand(time(nullptr));
	game.initBoard();

	while(game.inGame){
		game.displayBoard();
		game.input();
		game.updateBoard();
		game.hasWon();
		cout << game.msg;
		// cout << game.inGame;
	}

	return 0;
	
}
