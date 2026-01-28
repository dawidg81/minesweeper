#include "Game.hpp"
#include "../Utils/Utils.hpp"

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
    Utils util;

    std::cout << "Now editing custom difficulty" << std::endl;

    std::cout << "Board width: ";
    if(util.catchReturn(util.catchInputInt(Game::boardWidth)) != 0) return 1;
    std::cout << Game::boardWidth;

    std::cout << "Board height: ";
    if(util.catchReturn(util.catchInputInt(Game::boardHeight)) != 0) return 1;

    std::cout << "Mines: ";
    if(util.catchReturn(util.catchInputInt(Game::mines)) != 0) return 1;

    return 0;
}

void Game::displayBoard() {
    for (int i = 0; i < boardHeight; i++) {
        for (int j = 0; j < boardWidth; j++)
            putchar(tileMap[i][j]);
        putchar('\n');
    }
}