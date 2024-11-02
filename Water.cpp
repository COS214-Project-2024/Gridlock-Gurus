#include "Water.h"
#include <iostream>

void Water::checkCapacity() const {
    Utilities::checkCapacity();
    std::cout << "Additional checks specific to Water utility." << std::endl;
}

void Water::shed() {
    Utilities::shed();
    std::cout << "Water utility is reducing water flow to conserve resources." << std::endl;
}

void Water::breakUtility() {
    Utilities::breakUtility();
    std::cout << "Alert: Water utility malfunction detected!" << std::endl;
}

void Water::repair() {
    Utilities::repair();
    std::cout << "Water utility restored. Water flow normalized." << std::endl;
}