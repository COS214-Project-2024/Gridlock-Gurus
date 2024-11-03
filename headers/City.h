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

/**
 * @brief Represents the entire city, managing citizens, buildings, and services.
 *
 * Subject in the Observer pattern, notifying its observers (Government) about changes in the state.
 */
class City {
private:
    std::shared_ptr<Government> government;  ///< Pointer to the government managing the city.

    FactoryFactory* factory_factory;
    LandmarkFactory* landmark_factory;
    ResidentialFactory* residential_factory;
    CommercialFactory* commercial_factory;
    ServiceFactory* service_factory;

    int citizen_happiness;
    CityState state;

public:
    /**
     * @brief Constructs a new City object.
     */
    City();
    
    /**
     * @brief Destroys the City object.
     */
     ~City();

    /**
     * @brief Adds a new building to the city's collection of buildings.
     */
    void addBuilding(BuildingType type);

    /**
     * @brief Sets the state of citizen happiness in the city.
     * @param citizenHappiness The new citizen happiness level.
     */
    void setState();

    /**
     * @brief Gets the current state of citizen happiness in the city.
     * @return The current citizen happiness level.
     */
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

    void changeTaxStrategy();

    int getBuildingCount();
    int getCitizenCount();
    int getWorkierCount();

};

#endif // CITY_H
