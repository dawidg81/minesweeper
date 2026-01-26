#include "Game.hpp"

#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

void Game::editDiff(){
    cout << "Now editing custom difficulty" << endl;
}

void Game::initBoard() {
    for (int i = 0; i < boardHeight; i++)
        for (int j = 0; j < boardWidth; j++)
            bombMap[i][j] = rand() % 2;

    for (int i = 0; i < boardHeight; i++)
        for (int j = 0; j < boardWidth; j++)
            tileMap[i][j] = 0;
}

void Game::displayBoard() {
    for (int i = 0; i < boardHeight; i++) {
        for (int j = 0; j < boardWidth; j++)
            putchar(tileMap[i][j]);
        putchar('\n');
    }
}
