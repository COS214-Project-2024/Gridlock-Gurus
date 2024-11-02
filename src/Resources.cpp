#include "Resources.h"
#include <iostream>

Resources::Resources(int energy, int water, bool sanitationAvailable)
    : energy(energy), water(water), sanitationAvailable(sanitationAvailable) {}

void Resources::manageConsumption(int energyUsed, int waterUsed) {
    energy = std::max(0, energy - energyUsed);
    water = std::max(0, water - waterUsed);
    sanitationAvailable = (water > 0);

    std::cout << "Resources after consumption -> Energy: " << energy
              << ", Water: " << water << ", Sanitation available: " 
              << (sanitationAvailable ? "Yes" : "No") << std::endl;
}

Resources::~Resources() {}
