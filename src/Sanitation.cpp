#include "Sanitation.h"
#include <iostream>

/**
 * @brief Checks the current capacity of the sanitation system.
 *
 * Displays the sanitation system's maximum processing capacity.
 */
void Sanitation::checkCapacity() const {
    Utilities::checkCapacity();
    std::cout << "Sanitation system processing capacity: " << maxProduction << " liters per minute." << std::endl;
}

/**
 * @brief Reduces the operating capacity of the sanitation utility.
 *
 * Sets the sanitation system to operate at a reduced capacity.
 */
void Sanitation::shed() {
    Utilities::shed();
    std::cout << "Sanitation utility is operating at reduced capacity." << std::endl;
}

/**
 * @brief Simulates a failure in the sanitation utility.
 *
 * Marks the sanitation utility as broken and displays an alert.
 */
void Sanitation::breakUtility() {
    Utilities::breakUtility();
    std::cout << "Alert: Sanitation utility failure!" << std::endl;
}

/**
 * @brief Repairs the sanitation utility.
 *
 * Restores the sanitation utility to full capacity and stabilizes waste processing.
 */
void Sanitation::repair() {
    Utilities::repair();
    std::cout << "Sanitation utility restored. Waste processing stabilized." << std::endl;
}

