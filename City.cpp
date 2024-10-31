#include "City.h"
#include <algorithm>

City::City(Government *g, BuildingCollection *b, int h) : government(g), buildings(b), citizenSatisfaction(h) {
}

City::~City() {
    delete this->government;
    delete this->buildings;
    this->government = nullptr;
    this->buildings = nullptr;
}

void City::addObserver(const Citizen &observer) {
    observingCitizens.push_back(observer);
}

void City::removeObserver(const Citizen &observer) {
    observingCitizens.erase(std::remove(observingCitizens.begin(), observingCitizens.end(), observer), observingCitizens.end());
}

void City::notifyObservers() {
    for (Citizen c : observingCitizens) {
        c.update();
    }
}

void City::addBuilding(Building *b) const {
    buildings->addBuilding(b);
}

void City::calcOverallCitizenSatisfaction() {
    //should call notifyObservers()
    //probably use citizen iterator
}

void City::setState(int s) {
    this->citizenSatisfaction = s;
}

int City::getState() const {
    return citizenSatisfaction;
}
