#include <iostream>

#include "Game.hpp"

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