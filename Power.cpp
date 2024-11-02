#include "Power.h"
#include <iostream>
#include <string>


void Power::checkCapacity() const {
    Utilities::checkCapacity();
    std::cout << "Additional checks specific to Power utility." << std::endl;
}

void Power::shed() {
    Utilities::shed();
    std::cout << "Power utility is reducing energy distribution." << std::endl;
}

void Power::breakUtility() {
    Utilities::breakUtility();
    std::cout << "Alert: Power utility outage reported!" << std::endl;
}

void Power::repair() {
    Utilities::repair();
    std::cout << "Power utility restored. Energy generation stabilized." << std::endl;
}