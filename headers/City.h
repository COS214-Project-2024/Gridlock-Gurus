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

    /**
     * @brief Adds a new building to the city's collection of buildings.
     */
    void addBuilding(const std::string & name,BuildingType type);

    void setState();

    CityState getState() const; 

    void removeLastBuilding();//test

    int getCitizenHappiness() const;//test

    void setCitizenHappiness(int happiness);

    void calculateHappiness();

    //UTILITIES
    /**
    * Determines if the utilites are functional or under strain.
    */
    void checkUtilityUsage();

    void getUtilityStats(std::string& temp);

    void upgradeUtilities();

    void repairUtilities();

    //TAX

    int checkCityFunds() const;//tested

    void startTaxCycle();

    void increaseTransport(VehicleType type);

    //Tested
    void changeTaxStrategy(std::unique_ptr<TaxStrategy> taxStrategy);

    int getBuildingCount();

    int getCitizenCount();

    int getWorkerCount();

    void generateReport(std::string& temp);

    std::vector<Building*>& getBuildings();

    std::vector<Citizen*>& getCitizens();

    std::vector<Vehicle*>& getVehicles();

    Citizen& getCitizen(int id);

    std::string createCitizen(CitizenType type, int satisfaction, int funds);

    std::string getCitizenDetails(int id);

    std::string addNewBuilding(const std::string & name,BuildingType type);

    std::shared_ptr<DepartmentOfWaterPowerAndSanitation> getDepartmentOfWaterPowerAndSanitation() const {
        return government->getDepartmentOfWaterPowerAndSanitation();
    }

    std::shared_ptr<TaxAuthority> getTaxAuthority() const {
        return government->getTaxAuthority();
    }

    std::shared_ptr<DepartmentOfHomeAffairs> getDepartmentOfHomeAffairs() const {
        return government->getDepartmentOfHomeAffairs();
    }

     std::shared_ptr<TransportDepartment> getTransportDepartment() const {
        return government->getTransportDepartment();
    }

    std::shared_ptr<BudgetDepartment> getBudgetDepartment() const {
        return government->getBudgetDepartment();
    }

 std::vector<std::string>& getBuildingNames();
   
};

#endif // CITY_H
