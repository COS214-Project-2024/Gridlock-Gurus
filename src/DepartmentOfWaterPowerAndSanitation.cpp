#include "DepartmentOfWaterPowerAndSanitation.h"
#include <iostream>

/**
 * @brief Repairs broken facilities and calculates the total repair bill.
 *
 * This function checks if the water and power facilities are broken.
 * If a facility is broken, it repairs the facility and adds the repair cost
 * to the total repair bill. The function returns the total repair bill.
 *
 * @return The total cost incurred for repairing the broken facilities.
 */
int DepartmentOfWaterPowerAndSanitation::repair() {
    int repairBill = 0;

    if(water->isBroken()) {
        water->repair();
        repairBill += water->getCost();
    }

    if(power->isBroken()) {
        power->repair();
        repairBill += power->getCost();
    }

    return repairBill;
}

/**
 * @brief Checks the status of the water and power networks.
 *
 * This function evaluates the current status of the water and power facilities,
 * indicating whether they are broken or shedding. It returns a string detailing
 * the status of the facilities.
 *
 * @return A string summarizing the state of broken and shedding facilities.
 */
std::string DepartmentOfWaterPowerAndSanitation::checkNetwork() const {
    std::string ret = "Broken Facilities:\n"; 

    if(water->isBroken()) {
       ret += "Water Facilities are broked waiting for repair!\n"; 
    } 

    if(power->isBroken()) {
       ret += "Power Facilities are broked waiting for repair!\n";    
    }

    ret += "Shedding Facilities:\n"; 

    if(water->isShedding()) {
       ret += "Water usage is currently limited.\n"; 
    } 

    if(power->isShedding()) {
       ret += "Power usage is currently limited.\n";    
    }

    return ret;
}

/**
 * @brief Reviews and manages water usage.
 *
 * This function assesses the total water usage. If the total water usage
 * exceeds the maximum limit defined for the water utility, it breaks the
 * utility and initiates water shedding to manage consumption.
 *
 * @param totalWater The total amount of water usage to review.
 */
void DepartmentOfWaterPowerAndSanitation::reviewWaterUsage(int totalWater) {
    if(totalWater >= water->getMax()) {
        water->breakUtility();
        water->shed();
    }
}

/**
 * @brief Reviews and manages power usage.
 *
 * This function assesses the total power usage. If the total power usage
 * exceeds the maximum limit defined for the power utility, it breaks the
 * utility and initiates power shedding to manage consumption.
 *
 * @param totalPower The total amount of power usage to review.
 */
void DepartmentOfWaterPowerAndSanitation::reviewPowerUsage(int totalPower) {
    if(totalPower >= power->getMax()) {
        power->breakUtility();
        power->shed();
    }
}

/**
 * @brief Upgrades the production capabilities of both water and power facilities.
 *
 * This function calls the upgrade functions for both water and power utilities
 * to enhance their production capabilities.
 */
void DepartmentOfWaterPowerAndSanitation::upgrade() {
    power->upgradeProduction();
    water->upgradeProduction();
}
