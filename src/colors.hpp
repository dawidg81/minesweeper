#pragma once

#define COL_BLACK  "\e[0;30m"
#define COL_RED    '\e[0;31m'
#define COL_GREEN  "\e[0;32m"
#define COL_YELLOW '\e[0;33m'
#define COL_BLUE   '\e[0;34m'
#define COL_PURPLE '\e[0;35m'
#define COL_CYAN   '\e[0;36m'
#define COL_WHITE  '\e[0;37m'

#define COL_RESET  '\e[0m'

void changeColorWin(int col);
void changeColor(int col);