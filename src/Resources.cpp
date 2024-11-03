#include "Resources.h"
#include <iostream>

Resources::Resources(int energy, int water, bool sanitationAvailable): energy(energy), water(water), sanitationAvailable(sanitationAvailable) {}

void Resources::manageConsumption(int energyUsed, int waterUsed) {
    energy -= energyUsed;
    water -= waterUsed;
    sanitationAvailable = (waterUsed < water);

    std::cout << "Resources after consumption -> Energy: " << energy
              << ", Water: " << water << ", Sanitation available: " 
              << (sanitationAvailable ? "Yes" : "No") << std::endl;
}

