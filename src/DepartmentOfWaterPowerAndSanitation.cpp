#include "DepartmentOfWaterPowerAndSanitation.h"
#include <iostream>


void DepartmentOfWaterPowerAndSanitation::addUtilities(Utilities* utility) {
    utilities.push_back(utility);
}

void DepartmentOfWaterPowerAndSanitation::updateCitizenCount(int citizenCount) {
    int waterConsumption = citizenCount * 2;
    int energyConsumption = citizenCount * 3;
    resources->manageConsumption(energyConsumption, waterConsumption);
}

void DepartmentOfWaterPowerAndSanitation::repair() {
    for (auto& utility : utilities) {
        utility->repair();
    }
}

void DepartmentOfWaterPowerAndSanitation::checkNetwork() const {
    for (const auto& utility : utilities) {
        utility->checkCapacity();
    }
}

DepartmentOfWaterPowerAndSanitation::~DepartmentOfWaterPowerAndSanitation() {
    for (auto utility : utilities) {
        delete utility;
    }
}
