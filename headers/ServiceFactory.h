#ifndef SERVICEFACTORY_H
#define SERVICEFACTORY_H

#include "BuildingFactory.h"
#include "BuildingType.h"
#include "TaxAuthority.h"
#include <memory>

/**
 * @class ServiceFactory
 * @brief Factory for creating service buildings such as schools, hospitals, and police stations.
 */
class ServiceFactory : public BuildingFactory {
private:
    int numberOfSchools;        ///< Number of schools created.
    int numberOfHospitals;      ///< Number of hospitals created.
    int numberOfPoliceStations; ///< Number of police stations created.

public:
    /**
     * @brief Constructs a new ServiceFactory object.
     * @param taxAuthority Shared pointer to the tax authority.
     */
    ServiceFactory(std::shared_ptr<TaxAuthority> taxAuthority) : BuildingFactory(taxAuthority), numberOfSchools(0), numberOfHospitals(0), numberOfPoliceStations(0) {}

    /**
     * @brief Destroys the ServiceFactory object.
     */
    ~ServiceFactory() override = default;

    /**
     * @brief Creates a service building.
     * 
     * @param name The name of the building.
     * @param type The type of service building to create.
     * @param owner Reference to the owner of the building.
     * @return Pointer to the created service building object.
     */
    Building* createBuilding(const std::string& name, BuildingType type, Citizen& owner) override;
};

#endif // SERVICEFACTORY_H
