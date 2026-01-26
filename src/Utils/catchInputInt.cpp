#include "Utils.hpp"

#include <cstdio>
#include <iostream>

int Utils::catchInputInt(int* input){
    std::cin >> input;
    
    if (std::cin.fail()) {
        std::cout << "error: Input failed" << std::endl;
        return 1;
    }

    return 0;
}