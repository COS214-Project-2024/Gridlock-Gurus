#ifndef FACTORYFACTORY_H
#define FACTORYFACTORY_H

#include "BuildingFactory.h"
#include "TaxAuthority.h"
#include "BuildingType.h"
#include <memory>

/**
 * @class FactoryFactory
 * @brief Class for creating building instances.
 */
class FactoryFactory : public BuildingFactory {
public:
    /**
     * @brief Constructor for FactoryFactory.
     * @param taxAuthority A shared pointer to the TaxAuthority used for building creation.
     */
    FactoryFactory(std::shared_ptr<TaxAuthority> taxAuthority) : BuildingFactory(taxAuthority) {}

    /** 
     * @brief Default destructor for FactoryFactory.
     */
    ~FactoryFactory() override = default;

    /**
     * @brief Create a building of the specified type.
     * @param name The name of the building.
     * @param type The type of building to create.
     * @param owner The owner of the building.
     * @return A pointer to the created Building instance.
     */
    Building* createBuilding(const std::string& name, BuildingType type, Citizen& owner) override;
};

#endif // FACTORYFACTORY_H

