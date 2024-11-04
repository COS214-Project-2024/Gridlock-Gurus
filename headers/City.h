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

/**
 * @brief Enumeration of possible city states.
 */
enum CityState {
    Happy,   ///< City is happy.
    Normal,  ///< City is in a normal state.
    Upset    ///< City is upset.
};

/**
 * @brief Represents a city and manages its entities and utilities.
 */
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
    /**
     * @brief Default constructor for City.
     */
    City();

    /**
     * @brief Default destructor for City.
     */
    ~City();

    void addBuilding(const std::string& name, BuildingType type);
    void setState();
    CityState getState() const;
    void removeLastBuilding();
    int getCitizenHappiness() const;
    void setCitizenHappiness(int happiness);
    void calculateHappiness();
    void checkUtilityUsage();
    void getUtilityStats(std::string& temp);
    void upgradeUtilities();
    void repairUtilities();
    int checkCityFunds() const;
    void startTaxCycle();
    void increaseTransport(VehicleType type);
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
    std::string addNewBuilding(const std::string& name, BuildingType type);

    std::shared_ptr<DepartmentOfWaterPowerAndSanitation> getDepartmentOfWaterPowerAndSanitation() const;
    std::shared_ptr<TaxAuthority> getTaxAuthority() const;
    std::shared_ptr<DepartmentOfHomeAffairs> getDepartmentOfHomeAffairs() const;
    std::shared_ptr<TransportDepartment> getTransportDepartment() const;
    std::shared_ptr<BudgetDepartment> getBudgetDepartment() const;
};

#endif // CITY_H
