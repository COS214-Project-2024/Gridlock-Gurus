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

    Building* createBuilding(BuildingType type, Citizen& owner) override;
};

#endif // SERVICEFACTORY_H
