#include "Game.hpp"

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ostream>
#include <string>

void Game::initDiff(int diff) {
	switch (diff) {
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
	}
}

void Game::initBoard() {
	for (int y=0; y < boardHeight; y++) {
		for (int x=0; x < boardWidth; x++) {
			bombMap[y][x] = false;
			revealedMap[y][x] = false;
			tileMap[y][x] = 0;
			flagMap[y][x] = false;
		}
	}

	int placed = 0;
	while (placed < mines) {
		int x = rand() % boardWidth;
		int y = rand() % boardHeight;

		if (!bombMap[y][x]) {
			bombMap[y][x] = true;
			placed++;
		}
	}
}

void Game::updateBoard() {
	for (int y=0; y < boardHeight; y++) {
		for (int x=0; x < boardWidth; x++) {
			if (flagMap[y][x] == true) {
				tileMap[y][x] = 10;
				continue;
			} else if (!flagMap[y][x] && !revealedMap[y][x]) {
				tileMap[y][x] = 0;
				continue;	
			}
			
			else if (!revealedMap[y][x]) continue;

			int bombs = bombCheck(x, y);
			tileMap[y][x] = bombs == 0 ? 1 : bombs + 1;
		}
	}
}

int Game::editDiff() {
	std::cout << "Now editing custom difficulty" << std::endl;

	std::cout << "Board width: ";
	std::cin >> boardWidth;

	if (boardWidth > MAX_W) {
		std::cout << "Board width can't be more than " << MAX_W << " tiles." << std::endl;
		return 1;
	} else if (boardWidth < 4) {
		std::cout << "Board width can't be less than 4 tiles." << std::endl;
	}

	std::cout << "Board height: ";
	std::cin >> boardHeight;

	if (boardHeight > MAX_H) {
		std::cout << "Board height can't be more than " << MAX_H << " tiles." << std::endl;
		return 1;
	} else if (boardHeight < 4) {
		std::cout << "Board height can't be less than 4 tiles." << std::endl;
	}

	std::cout << "Mines: ";
	std::cin >> mines;

	if (mines > 8 || mines > boardWidth * boardHeight) {
		std::cout << "There can't be more than 8 or " << (boardWidth * boardHeight) << "mines." << std::endl;
		return 1;
	} else if (mines < 2) {
		std::cout << "There can't be less than 2 bombs." << std::endl;
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

	std::cout << msg << "\n  ";

	for (int i = 0; i < boardHeight; i++) {
		std::cout << i;
	}

	std::cout << "\n\n";

	for (int y=0; y < boardHeight; y++) {
		std::cout << y << " ";
	
		for (int x = 0; x < boardWidth; x++) {
			if (tileMap[y][x] == 0) putchar('#');
			else if (tileMap[y][x] == 1) putchar('.');
			else if (tileMap[y][x] == 10) putchar('F');
			else putchar('0' + tileMap[y][x] - 1);
		}

		putchar('\n');
	}
	putchar('\n');
}

int Game::bombCheck(int x, int y) {
	int count = 0;

	for (int dy = -1; dy <= 1; dy++) {
		for (int dx = -1; dx <= 1; dx++) {
			if (dx == 0 && dy == 0) continue;

			int nx = x + dx;
			int ny = y + dy;

			if (nx >= 0 && nx < boardWidth && ny >= 0 && ny < boardHeight && bombMap[ny][nx]) {
				count++;
			}
		}
	}

	return count;
}

void Game::revealTile(int y, int x) {
	revealedMap[y][x] = true;

	if (bombCheck(x, y) == 0) {
		for (int dy = -1; dy <= 1; dy++) {
			for (int dx = -1; dx <= 1; dx++) {
				if (dx == 0 && dy == 0) continue;
				int nx = x + dx;
				int ny = y + dy;

				if (nx >= 0 && nx < boardWidth && ny >= 0 && ny < boardHeight && !revealedMap[ny][nx]) {
					revealedMap[ny][nx] = true;
					revealTile(ny, nx);
				}
			}
		}
	}
}

bool Game::hasWon() {
	int revealedTiles = 0;

	for (int y=0; y < boardHeight; y++) {
		for (int x = 0; x < boardWidth; x++) {
			if (revealedMap[y][x]) revealedTiles++;
		}
	}

	if (boardWidth * boardHeight - mines == revealedTiles) {
		std::cout << "You have won!\n";
		inGame = false;
	}
	
	return true;
}

void Game::input() {
	std::string cmd;

	std::cout << "game> ";
	std::cin >> cmd;

	// std::cout << cmd;

	if (std::cin.fail()) {
		std::cout << "Input failed." << std::endl;

		inGame = false;
		return;
	}

	if (cmd == "q") {
		inGame = false;
		return;
	}

	int x, y;
	std::cin >> x >> y;

	if (x < 0 || x >= boardWidth || y < 0 || y >= boardHeight) return;

	if (cmd == "d") {
		if (flagMap[y][x]) {
			msg = "You can't dig on flag.\n";
			return;
		}

		if (bombMap[y][x]) {
			msg = "BOOM! Game over\n";
			inGame = false;
			return;
		}

		if (!revealedMap[y][x]) {
			revealTile(y, x);
		}
	}

	if (cmd == "f") {
		if (revealedMap[y][x]) {
			msg = "You can't place flag on revealed tile.\n";
		}

		if (flagMap[y][x]) {
			flagMap[y][x] = false;
		} else {
			flagMap[y][x] = true;
		}
	}
}
