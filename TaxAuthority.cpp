#include "TaxAuthority.h"
#include "Citizen.h"

TaxAuthority::TaxAuthority() : buildings(nullptr), strategy(nullptr), collectedTax(0) {}

TaxAuthority::~TaxAuthority() {
    delete buildings;
    delete strategy;
}

void TaxAuthority::registerBuilding(Building* building) {
    if (buildings) {
        buildings->addBuilding(building);
    }
}

void TaxAuthority::registerCitizen(Citizen* citizen) {
    if (citizen) {
        citizens.push_back(citizen);
    }
}

void TaxAuthority::notifyCitizens() {
    for (Citizen* citizen : citizens) {
        citizen->update();
    }
}

void TaxAuthority::notifyBuildings() {
    if (buildings) {
        buildings->update();
    }
}

void TaxAuthority::setStrategy(TaxStrategy* taxStrategy) {
    strategy = taxStrategy;
}

int TaxAuthority::calculateBuildingTax(int value) {
    if (strategy) {
        return strategy->calculateBuildingTax(value);
    }
    return 0;
}

int TaxAuthority::calculateCitizenTax(int earnings) {
    if (strategy) {
        return strategy->calculateCitizenTax(earnings);
    }
    return 0;
}

void TaxAuthority::changeRate(int percentage) {
    if (strategy) {
        strategy->adjustRate(percentage);
    }
}

int TaxAuthority::collectTaxes() {
    return collectedTax;
}

void TaxAuthority::receiveTaxes(int paidTaxes) {
    collectedTax += paidTaxes;
}