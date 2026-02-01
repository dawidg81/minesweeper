#include "Game.hpp"

#include <cstdlib>
#include <cstdio>
#include <iostream>
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
        case 3:
            std::cout << "Editing game parameters\n";
            break;
    }
}

void Game::initBoard() {
    // Bomb map (boolean): 0 or false is no bomb, 1 or true is bomb;
    // clearing bomb map
    for (int i = 0; i < boardHeight; i++) {
        for (int j = 0; j < boardWidth; j++) {
            for(int k = 0; k < mines; k++){
                bombMap[i][j] = 0;
            }
        }
    }

    // initializing bomb map
    for (int i = 0; i < boardHeight; i++) {
        for (int j = 0; j < boardWidth; j++) {
            for(int k = 0; k < mines; k++){
                bombMap[i][j] = rand() % 2;
            }
        }
    }
    
    // initializing tile map for display
    for (int i = 0; i < boardHeight; i++) {
        for (int j = 0; j < boardWidth; j++) {
            tileMap[i][j] = 0;
        }
    }
}

int Game::editDiff(){

    std::cout << "Now editing custom difficulty" << std::endl;

    std::cout << "Board width: ";

    std::cout << "Board height: ";

    std::cout << "Mines: ";

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

*/
void Game::displayBoard() {
    for (int i = 0; i < boardHeight; i++) {
        for (int j = 0; j < boardWidth; j++) {
            if (tileMap[i][j] == 0) {
                putchar('#');
            } else if (tileMap[i][j] == 1) {
                putchar('.');
            } else if (tileMap[i][j] == 2) {
                putchar('1');
            } else if (tileMap[i][j] == 3) {
                putchar('2');
            } else if (tileMap[i][j] == 4) {
                putchar('3');
            } else if (tileMap[i][j] == 5) {
                putchar('4');
            } else if (tileMap[i][j] == 6) {
                putchar('5');
            } else if (tileMap[i][j] == 7) {
                putchar('6');
            } else if (tileMap[i][j] == 8) {
                putchar('7');
            } else if (tileMap[i][j] == 9) {
                putchar('8');
            }
        }
        putchar('\n');
    }
}