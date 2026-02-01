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
    for (int i = 0; i < boardHeight; i++) {
        for (int j = 0; j < boardWidth; j++) {
            bombMap[i][j] = rand() % 2;
        }
    }

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

void Game::displayBoard() {
    for (int i = 0; i < boardHeight; i++) {
        for (int j = 0; j < boardWidth; j++)
            putchar(tileMap[i][j]);
        putchar('\n');
    }
}