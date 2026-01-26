#include "Game.hpp"
#include "../Utils/Utils.hpp"

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>

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