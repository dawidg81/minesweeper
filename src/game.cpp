#include <iostream>
#include "game.hpp"
using namespace std;

bool inGame = false;

void game(int diff){
	int boardWidth;
	int boardHeight;
	int board[boardWidth][boardHeight];
	int mines;

	switch(diff){
		case 0:
			boardWidth  = 9;
			boardHeight = 9;
			mines       = 9;
			break;

		case 1:
			boardWidth  = 16;
			boardHeight = 16;
			mines       = 12;
			break;

		case 2:
			boardWidth  = 30;
			boardHeight = 16;
			mines       = 16;
			break;

		case 3:
			cout << "Editing game parameters\n";
			
			cout << "Board Width: ";
			cin >> boardWidth;

			if(boardWidth > 32){
				cout << "Board width can't be more than 32 cells.\n";
			} else if(boardWidth < 8){
				cout << "Board width can't be less than 8 cells.\n";
			}

			cout << "Board Height: ";
			cin >> boardHeight;

			if(boardHeight > 32){
				cout << "Board height can't be more than 32 cells.\n";
			}else if(boardHeight < 8){
				cout << "Board height can't be less than 8 cells.\n";
			}

			cout << "Mines: ";
			cin >> mines;

			if(mines > 16){
				cout << "There can't be more than 16 mines.\n";
			}

			break;
	}
}