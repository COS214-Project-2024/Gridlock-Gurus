#include "Resources.h"
#include <iostream>

/**
 * @brief Constructs a Resources object with specified energy, water, and sanitation availability.
 *
 * @param energy The initial amount of energy resources.
 * @param water The initial amount of water resources.
 * @param sanitationAvailable Indicates if sanitation services are available.
 */
Resources::Resources(int energy, int water, bool sanitationAvailable): energy(energy), water(water), sanitationAvailable(sanitationAvailable) {}

/**
 * @brief Manages resource consumption by reducing available energy and water.
 *
 * This function decreases energy and water resources by specified amounts and updates
 * the sanitation availability based on remaining water levels.
 *
 * @param energyUsed The amount of energy to be consumed.
 * @param waterUsed The amount of water to be consumed.
 */
void Resources::manageConsumption(int energyUsed, int waterUsed) {
    energy -= energyUsed;
    water -= waterUsed;
    sanitationAvailable = (waterUsed < water);

    std::cout << "Resources after consumption -> Energy: " << energy
              << ", Water: " << water << ", Sanitation available: " 
              << (sanitationAvailable ? "Yes" : "No") << std::endl;
}

