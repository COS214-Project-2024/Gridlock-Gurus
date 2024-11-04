#include "Utilities.h"
#include <iostream>

/**
 * @brief Checks if the utility is operating at full capacity.
 *
 * Outputs the status of the utility's capacity. If in disrepair, notes that the utility is not fully operational.
 */
void Utilities::checkCapacity() const {
    std::cout << "Checking capacity for utility." << std::endl;
    if (isRepair) {
        std::cout << "Utility is currently in disrepair and not operating at full capacity." << std::endl;
    } else {
        std::cout << "Utility is operating at maximum production of " << maxProduction << "." << std::endl;
    }
}

/**
 * @brief Initiates load shedding to reduce utility load.
 *
 * Changes the shedding status if not already active, indicating the utility is reducing its load.
 */
void Utilities::shed() {
    if (!shedding) {
        shedding = true;
        std::cout << "Utility is now shedding to reduce load." << std::endl;
    } else {
        std::cout << "Utility is already in load shedding mode." << std::endl;
    }
}

/**
 * @brief Repairs the utility, returning it to full operational status.
 *
 * If the utility is in disrepair, this function will reset it to operational mode, removing shedding status.
 */
void Utilities::repair() {
   if (isRepair) {
        isRepair = false;
        shedding = false;
        std::cout << "Utility has been repaired. Cost: " << costOfRepair << std::endl;
    } else {
        std::cout << "Utility is not in disrepair." << std::endl;
    }
}

/**
 * @brief Marks the utility as broken, activating shedding mode.
 *
 * Changes the utility's status to broken if it is not already in disrepair, triggering load shedding.
 */
void Utilities::breakUtility() {
    if (!isRepair) {
        isRepair = true;
        shedding = true;
        std::cout << "Utility has broken down." << std::endl;
    } else {
        std::cout << "Utility is already broken." << std::endl;
    }
}
