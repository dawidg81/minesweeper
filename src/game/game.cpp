#include <cstdlib>
#include <iostream>
#include <sys/stat.h>
#include "globals.hpp"
using namespace std;

bool inGame = false;

class Game{
private:
	static constexpr int MAX_W = 32;
	static constexpr int MAX_H = 32;

	int boardWidth;
	int boardHeight;

	bool bombmap[MAX_H][MAX_W];
	int displaymap[MAX_H][MAX_W];

	int mines;

public:
	void initDiff(int diff){
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

	void initBoard(){
		for(int i = 0; i < boardHeight; i++){
			for(int j = 0; j < boardWidth; j++){
				bombmap[i][j] = rand() % 1;
			}
		}
	}
};
