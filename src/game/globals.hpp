#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>

class Game {
private:
    static constexpr int MAX_W = 32;
    static constexpr int MAX_H = 32;

    int boardWidth;
    int boardHeight;

    bool bombMap[MAX_H][MAX_W];
    int tileMap[MAX_H][MAX_W];

    int mines;

public:
    void initDiff(int diff);
    void initBoard();
    void displayBoard();
};

#endif
