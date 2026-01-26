#include "Game.hpp"

#include <cstdlib>
#include <cstdio>
#include <iostream>

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
    for (int i = 0; i < boardHeight; i++)
        for (int j = 0; j < boardWidth; j++)
            bombMap[i][j] = rand() % 2;

    for (int i = 0; i < boardHeight; i++)
        for (int j = 0; j < boardWidth; j++)
            tileMap[i][j] = 0;
}