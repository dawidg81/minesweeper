#include "Game.hpp"
#include "../utils/Utils.hpp"

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>

int Game::editDiff(){
    Utils util;

    std::cout << "Now editing custom difficulty" << std::endl;

    std::cout << "Board width: ";
    util.catchInputInt(Game::boardWidth);
    if(util.catchReturn(util.catchInputInt(Game::boardWidth)) != 0) return 1;

    std::cout << "Board height: ";
    util.catchInputInt(Game::boardHeight);
    if(util.catchReturn(util.catchInputInt(Game::boardHeight)) != 0) return 1;

    std::cout << "Mines: ";
    util.catchInputInt(Game::mines);
    if(util.catchReturn(util.catchInputInt(Game::mines)) != 0) return 1;

    return 0;
}