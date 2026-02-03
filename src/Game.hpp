#pragma once

class Game {
private:
    static constexpr int MAX_W = 32;
    static constexpr int MAX_H = 32;

    int boardWidth;
    int boardHeight;

    bool bombMap[MAX_H][MAX_W];
    int tileMap[MAX_H][MAX_W];
    bool revealed[MAX_H][MAX_W];

    int mines;

public:
    bool inGame;

    int editDiff();
    void initDiff(int diff);
    void initBoard();
    void updateBoard();
    void displayBoard();
    int bombCheck(int x, int y);
    void input();
};

