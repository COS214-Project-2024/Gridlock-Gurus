#ifndef SERVICEFACTORY_H
#define SERVICEFACTORY_H

#include "BuildingFactory.h"
#include "BuildingType.h"
#include "TaxAuthority.h"
#include <memory>


class ServiceFactory : public BuildingFactory {
    int numberOfSchools;
    int numberOfHospitals;
    int numberOfPoliceStations;
public:
    ServiceFactory(std::shared_ptr<TaxAuthority> taxAuthority) : BuildingFactory(taxAuthority), numberOfSchools(0),numberOfHospitals(0),numberOfPoliceStations(0) {}
    ~ServiceFactory() override = default;
    
    /**
     * @brief Creates a service building.
     * @param type The type of service building to create.
     * @return Pointer to the created service building object.
     *
     * This method overrides the factory method to create a service building.
     */
    Building* createBuilding(const std::string& name, BuildingType type, Citizen& owner) override;
};

#endif // SERVICEFACTORY_H
