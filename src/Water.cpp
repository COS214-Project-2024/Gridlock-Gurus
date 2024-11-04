#include "Water.h"
#include <iostream>

/**
 * @brief Checks the production capacity of the water utility.
 *
 * Extends the base utility check with additional water-specific checks.
 */
void Water::checkCapacity() const {
    Utilities::checkCapacity();
    std::cout << "Additional checks specific to Water utility." << std::endl;
}

/**
 * @brief Activates load shedding for the water utility.
 *
 * Reduces water flow to conserve resources.
 */
void Water::shed() {
    Utilities::shed();
    std::cout << "Water utility is reducing water flow to conserve resources." << std::endl;
}

/**
 * @brief Marks the water utility as broken.
 *
 * Activates load shedding and notifies of the breakdown.
 */
void Water::breakUtility() {
    Utilities::breakUtility();
    std::cout << "Alert: Water utility malfunction detected!" << std::endl;
}

/**
 * @brief Repairs the water utility and restores normal water flow.
 */
void Water::repair() {
    Utilities::repair();
    std::cout << "Water utility restored. Water flow normalized." << std::endl;
}

