#ifndef BUILDINGFACTORY_H
#define BUILDINGFACTORY_H

#include "Building.h"
#include "BuildingType.h"
#include "TaxAuthority.h"
#include <memory>

/**
 * @brief Factory class responsible for constructing buildings.
 */
class BuildingFactory {
public:
    std::shared_ptr<TaxAuthority> taxAuthority; ///< Shared pointer to the associated TaxAuthority.

    /**
     * @brief Constructs a new BuildingFactory object.
     * @param taxAuthority Shared pointer to a TaxAuthority.
     */
    BuildingFactory(std::shared_ptr<TaxAuthority> taxAuthority) : taxAuthority(taxAuthority) {}

    /**
     * @brief Destroys the BuildingFactory object.
     */
    virtual ~BuildingFactory() = default;

    /**
     * @brief Starts the construction process for the factory.
     */
    void startConstruction() {}

    /**
     * @brief Pure virtual function to create a Building.
     * @param name Name of the building.
     * @param type Type of the building.
     * @param owner Reference to the owner of the building.
     * @return Pointer to the created Building object.
     */
    virtual Building* createBuilding(const std::string& name, BuildingType type, Citizen& owner) = 0;
};

#endif // BUILDINGFACTORY_H
