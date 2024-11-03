#ifndef CITY_H
#define CITY_H

#include "Government.h"
#include <memory>
#include "BuildingCollection.h"
#include "BuildingType.h"
#include "TaxAuthority.h"
#include "FactoryFactory.h"
#include "LandmarkFactory.h"
#include "ResidentialFactory.h"
#include "CommercialFactory.h"
#include "ServiceFactory.h"
#include "Building.h"
#include "Commercial.h"
#include "BuildingType.h"
#include "Citizen.h"
#include "TaxStrategy.h"
#include "BrickFactory.h"
#include "WoodFactory.h"
#include "SteelFactory.h"
#include "Residential.h"
#include "Landmark.h"
#include "EducationService.h"
#include "HealthService.h"
#include "PoliceService.h"
#include "VehicleType.h"

enum CityState {
    Happy,
    Normal,
    Upset
};

class City {
private:
    std::shared_ptr<Government> government;

    FactoryFactory* factory_factory;
    LandmarkFactory* landmark_factory;
    ResidentialFactory* residential_factory;
    CommercialFactory* commercial_factory;
    ServiceFactory* service_factory;

    int citizen_happiness;
    CityState state;

public:
    City();

     ~City();
    void addBuilding(BuildingType type);

    void setState();

    CityState getState() const; 

    void removeLastBuilding();//test

    int getCitizenHappiness() const;//test

    void setCitizenHappiness(int happiness);

    void calculateHappiness();

    void checkUtilityUsage();

    void repairUtilities();

    int checkCityFunds() const;//tested

    void startTaxCycle();

    void increaseTransport(VehicleType type);

    void changeTaxStrategy(std::unique_ptr<TaxStrategy> taxStrategy);

    int getBuildingCount();
    int getCitizenCount();
    int getWorkerCount();

};

#endif // CITY_H
