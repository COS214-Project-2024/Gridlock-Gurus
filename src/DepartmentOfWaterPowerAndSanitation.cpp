#include "DepartmentOfWaterPowerAndSanitation.h"
#include <iostream>

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

void DepartmentOfWaterPowerAndSanitation::reviewWaterUsage(int totalWater) {
    if(totalWater >= water->getMax()) {
        water->breakUtility();
        water->shed();
    }
}

void DepartmentOfWaterPowerAndSanitation::reviewPowerUsage(int totalPower) {
    if(totalPower >= power->getMax()) {
        power->breakUtility();
        power->shed();
    }
}

void DepartmentOfWaterPowerAndSanitation::upgrade() {
    power->upgradeProduction();
    water->upgradeProduction();
}
