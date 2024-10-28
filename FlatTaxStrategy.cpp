#include "FlatTaxStrategy.h"

FlatTaxStrategy::FlatTaxStrategy(int flatRate) : flatRate(flatRate / 100) {}

int FlatTaxStrategy::calculateBuildingTax(int value) {
    return value * flatRate;
}

int FlatTaxStrategy::calculateCitizenTax(int earnings) {
    return earnings * flatRate;
}

void FlatTaxStrategy::adjustRate(int percentage){
    this->flatRate = percentage / 100;
}
