#include "Game.hpp"

#include <cstdlib>
#include <cstdio>
#include <iostream>


void Game::displayBoard() {
    for (int i = 0; i < boardHeight; i++) {
        for (int j = 0; j < boardWidth; j++)
            putchar(tileMap[i][j]);
        putchar('\n');
    }
}