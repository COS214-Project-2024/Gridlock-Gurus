#include "TaxAuthority.h"
#include "FlatTaxStrategy.h"
#include "ProgressiveTaxStrategy.h"
#include <algorithm>

/**
 * @brief Constructs a new TaxAuthority object with default settings.
 *        Initializes the building collection, sets the tax strategy to flat, and
 *        initializes the collected tax amount to zero.
 */
TaxAuthority::TaxAuthority(){
    this->buildings = std::make_unique<BuildingCollection>();
    this->strategy = std::make_unique<FlatTaxStrategy>();
    this->collectedTax = 0;
}

/**
 * @brief Registers a building within the tax authority, allowing it to be managed
 *        for taxation purposes.
 * @param building The building to register.
 */
void TaxAuthority::registerBuilding(Building& building) {
    this->buildings->addBuilding(building);
}

/**
 * @brief Registers a citizen within the tax authority, enabling the citizen
 *        to be taxed.
 * @param citizen The citizen to register.
 */
void TaxAuthority::registerCitizen(Citizen& citizen) {
    this->citizens.push_back(&citizen);
}

/**
 * @brief Collects taxes from all registered buildings and citizens.
 * @return The total collected tax amount.
 */
int TaxAuthority::collectTaxes() {
    this->collectedTax = 0;

    this->notifyBuildings();
    this->notifyCitizens();

    return this->collectedTax;
}

/**
 * @brief Notifies each citizen to pay taxes based on their funds.
 */
void TaxAuthority::notifyCitizens() {
    for(auto c : this->citizens) {
        c->payTaxes(calculateCitizenTax(c->getFunds()));
    }
}

/**
 * @brief Notifies each building to pay taxes based on their value.
 */
void TaxAuthority::notifyBuildings() {
    int counter = 0;
    for(auto it = buildings->begin(); it != buildings->end(); ++it) {
        counter++;
        auto building = *it;
        building->payTax(calculateBuildingTax(building->getCost()));
    }
}

/**
 * @brief Sets the tax strategy for the tax authority.
 * @param taxStrategy The new tax strategy to be applied.
 */
void TaxAuthority::setStrategy(std::unique_ptr<TaxStrategy> taxStrategy) {
    this->strategy = std::move(taxStrategy);
}

/**
 * @brief Calculates the tax for a building based on its value.
 * @param value The value of the building.
 * @return The calculated tax amount.
 */
int TaxAuthority::calculateBuildingTax(int value) {
    return this->strategy->calculateBuildingTax(value);
}

/**
 * @brief Calculates the tax for a citizen based on their earnings.
 * @param earnings The earnings of the citizen.
 * @return The calculated tax amount.
 */
int TaxAuthority::calculateCitizenTax(int earnings) {
    return this->strategy->calculateCitizenTax(earnings);
}

/**
 * @brief Adds an amount to the total collected tax.
 * @param amount The tax amount to be added.
 */
void TaxAuthority::sendTax(int amount) {
    this->collectedTax += amount;
}

/**
 * @brief Retrieves the total amount of collected tax.
 * @return The total collected tax amount.
 */
int TaxAuthority::getCollectedTax() {
    return this->collectedTax;
}

/**
 * @brief Gets the total number of registered buildings.
 * @return The number of buildings.
 */
int TaxAuthority::getSize() {
    return this->buildings->getSize();
}

/**
 * @brief Removes the last registered building from the collection.
 */
void TaxAuthority::removeLastBuilding() {
    buildings->removeLastBuilding();
}

/**
 * @brief Retrieves the total water usage of all buildings in the city.
 * @return The total water usage.
 */
int TaxAuthority::getWaterUsage() const {
    return buildings->getCityWaterConsumption();
}

/**
 * @brief Retrieves the total power usage of all buildings in the city.
 * @return The total power usage.
 */
int TaxAuthority::getPowerUsage() const {
    return buildings->getCityPowerConsumption();
}

/**
 * @brief Unregisters a citizen from the tax authority.
 * @param citizen The citizen to be unregistered.
 */
void TaxAuthority::unregisterCitizen(Citizen& citizen) {
    auto it = std::remove(citizens.begin(), citizens.end(), &citizen);
    if (it != citizens.end()) {
        citizens.erase(it, citizens.end());
    }
}

/**
 * @brief Deregisters all citizens from the tax authority.
 */
void TaxAuthority::deregisterAllCitizens() {
    citizens.clear();
}

/**
 * @brief Gets the collection of registered buildings.
 * @return A reference to the vector of buildings.
 */
std::vector<Building*>& TaxAuthority::getBuildings() {
    return buildings->getBuildings();
}
