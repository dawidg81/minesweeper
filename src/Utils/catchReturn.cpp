#include "Utils.hpp"

#include <iostream>
#include <ostream>

int Utils::catchReturn(int renum){
    if (renum != 0) {
        std::cout << "Received error signal, sending further" << std::endl;
    }
    return 0;
}