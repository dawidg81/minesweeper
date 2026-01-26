#include <iostream>
#include "Game/Game.hpp"
using namespace std;

int main(){
	Game game;
	int choice;

	cout << "Welcome to minesweeper 0.1.0\n";
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
	} else if(choice == 2){
		game.initDiff(1);
	} else if(choice == 3){
		game.initDiff(2);
	} else if(choice == 4){
		game.initDiff(3);
	}

	return 0;
}
