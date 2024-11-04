#include "Power.h"
#include <iostream>
#include <string>

/**
 * @brief Checks the capacity of the power utility.
 */
void Power::checkCapacity() const {
    Utilities::checkCapacity();
}

/**
 * @brief Reduces the distribution of energy as a response to excess demand.
 */
void Power::shed() {
    Utilities::shed();
    std::cout << "Power utility is reducing energy distribution." << std::endl;
}

/**
 * @brief Simulates a power outage.
 */
void Power::breakUtility() {
    Utilities::breakUtility();
    std::cout << "Alert: Power utility outage reported!" << std::endl;
}

/**
 * @brief Repairs the power utility and restores normal operation.
 */
void Power::repair() {
    Utilities::repair();
    std::cout << "Power utility restored. Energy generation stabilized." << std::endl;
}
