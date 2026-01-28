#include "Utils.hpp"

#include <iostream>
#include <ostream>

int Utils::catchInputInt(int* input){
    std::cin >> input;
    
    if (std::cin.fail()) {
        std::cout << "error: Input failed" << std::endl;
        return 1;
    }

    return 0;
}

int Utils::catchReturn(int renum){
    if (renum != 0) {
        std::cout << "Received error signal, sending further" << std::endl;
    }
    return 0;
}
