#include "Game.hpp"

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>

void Game::initDiff(int diff){
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
			std::cout << "Editing game parameters\n";
			break;
	}
}

void Game::initBoard(){
	for(int y=0; y < boardHeight; y++){
		for(int x=0; x < boardWidth; x++){
			bombMap[y][x] = false;
			revealed[y][x] = false;
			tileMap[y][x] = 0;
			flag[y][x] = false;
		}
	}

	int placed = 0;
	while(placed < mines){
		int x = rand() % boardWidth;
		int y = rand() % boardHeight;

		if(!bombMap[y][x]){
			bombMap[y][x] = true;
			placed++;
		}
	}
}

void Game::updateBoard(){
	for(int y=0; y < boardHeight; y++){
		for(int x=0; x < boardWidth; x++){
			if(!revealed[y][x]) continue;
			if(!flag[y][x]) continue;
			else tileMap[y][x] = 10;

			int bombs = bombCheck(x, y);
			tileMap[y][x] = bombs == 0 ? 1 : bombs + 1;
		}
	}
}

int Game::editDiff(){
	std::cout << "Now editing custom difficulty" << std::endl;

	std::cout << "Board width: ";
	std::cin >> boardWidth;

	if(boardWidth > MAX_W){
		std::cout << "Board width can't be more than " << MAX_W << " tiles." << std::endl;
		return 1;
	}

	std::cout << "Board height: ";
	std::cin >> boardHeight;

	if(boardHeight > MAX_H){
		std::cout << "Board height can't be more than " << MAX_H << " tiles." << std::endl;
		return 1;
	}

	std::cout << "Mines: ";
	std::cin >> mines;

	if(mines > 8 || mines > (boardWidth * boardHeight)){
		std::cout << "There can't be more than 8 or " << (boardWidth * boardHeight) << "mines." << std::endl;
		return 1;
	}

	return 0;
}

/* Tile map:

0 - unrevealed tile
1 - revealed tile
2 - revealed tile with 1 bomb around
3 - revealed tile with 2 bomb around
4 - revealed tile with 3 bomb around
5 - revealed tile with 4 bomb around
6 - revealed tile with 5 bomb around
7 - revealed tile with 6 bomb around
8 - revealed tile with 7 bomb around
9 - revealed tile with 8 bomb around
10 - flag
11 - bomb (for DEBUGGING)

*/

void Game::displayBoard() {
	#ifdef _WIN32
	system("cls");
	#else
	system("clear");
	#endif

	for(int y=0; y < boardHeight; y++){
		for(int x = 0; x < boardWidth; x++){
			if(tileMap[y][x] == 0) putchar('#');
			else if(tileMap[y][x] == 1) putchar('.');
			else if(tileMap[y][x] == 10) putchar('F');
			else putchar('0' + tileMap[y][x] - 1);
		}
		putchar('\n');
	}
}

int Game::bombCheck(int x, int y){
	int count = 0;

	for(int dy = -1; dy <= 1; dy++){
		for(int dx = -1; dx <= 1; dx++){
			if(dx == 0 && dy == 0) continue;

			int nx = x + dx;
			int ny = y + dy;

			if(nx >= 0 && nx < boardWidth && ny >= 0 && ny < boardHeight && bombMap[ny][nx]){
				count++;
			}
		}
	}
	return count;
}

void Game::input(){
	std::string cmd;
	std::cout << "game> ";
	std::cin >> cmd;

	if(std::cin.fail()){
		std::cout << "Input failed." << std::endl;
		return;
	}

	if(cmd == "q"){
		inGame = false;
		return;
	}

	int x, y;
	std::cin >> x >> y;
	
	if(x < 0 || x >= boardWidth || y < 0 || y >= boardHeight) return;
	if(cmd == "d"){
		if(bombMap[y][x]){
			std::cout << "BOOM! Game over\n";
			inGame = false;
			return;
		}

		if(!revealed[y][x]){
			revealed[y][x] = true;
			if(bombCheck(x, y) == 0){
				for(int dy = -1; dy <= 1; dy++){
					for(int dx = -1; dx <= 1; dx++){
						int nx = x + dx;
						int ny = y + dy;

						if(nx >= 0 && nx < boardWidth && ny >= 0 && ny < boardHeight && !revealed[ny][nx]){
							revealed[ny][nx] = true;
						}
					}
				}
			}
		}
	}

	if(cmd == "f"){
		flag[y][x] = true;
	}
} 
