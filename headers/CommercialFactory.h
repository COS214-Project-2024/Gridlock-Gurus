#ifndef COMMERCIALFACTORY_H
#define COMMERCIALFACTORY_H

#include <memory>
#include "BuildingFactory.h"
#include "BuildingType.h"
#include "TaxAuthority.h"

/**
 * @brief Factory class for creating Commercial buildings.
 */
class CommercialFactory : public BuildingFactory {
public:
    /**
     * @brief Constructs a CommercialFactory with a tax authority.
     * @param taxAuthority Shared pointer to a TaxAuthority object.
     */
    CommercialFactory(std::shared_ptr<TaxAuthority> taxAuthority) : BuildingFactory(taxAuthority) {}

    /**
     * @brief Default destructor.
     */
    ~CommercialFactory() override = default;

    /**
     * @brief Creates a new commercial building.
     * @param name Name of the building.
     * @param type Type of the building.
     * @param owner Owner of the building.
     * @return Pointer to the newly created building.
     */
    Building* createBuilding(const std::string& name, BuildingType type, Citizen& owner) override;
};

#endif // COMMERCIALFACTORY_H
