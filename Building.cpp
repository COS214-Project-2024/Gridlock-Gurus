#include "Building.h"

void Building::payTax(int amount){
    this->owner->payTaxes(taxAuthority->calculateBuildingTax(getCost()));
}


int Building::getCost() {
    return this->cost;
}