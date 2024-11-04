/**
 * @file City.h
 * @brief Defines the City class, which manages various aspects of a city, including buildings, citizens, utilities, and taxation.
 */

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
 * @enum CityState
 * @brief Represents the overall happiness state of the city.
 */
enum CityState {
    Happy, ///< High citizen satisfaction.
    Normal, ///< Average citizen satisfaction.
    Upset ///< Low citizen satisfaction.
};

/**
 * @class City
 * @brief Represents a city, managing its buildings, citizens, utilities, and finances.
 */
class City {
private:
    std::shared_ptr<Government> government; ///< Government entity managing the city's departments.

    FactoryFactory* factory_factory; ///< Factory for creating industrial buildings.
    LandmarkFactory* landmark_factory; ///< Factory for creating landmarks.
    ResidentialFactory* residential_factory; ///< Factory for creating residential buildings.
    CommercialFactory* commercial_factory; ///< Factory for creating commercial buildings.
    ServiceFactory* service_factory; ///< Factory for creating service buildings.

    int citizen_happiness; ///< Current happiness level of the city's citizens.
    CityState state; ///< Current state of the city's overall satisfaction.

public:
    /**
     * @brief Constructs a City object.
     */
    City();

    /**
     * @brief Destroys the City object.
     */
    ~City();

    /**
     * @brief Adds a new building to the city's collection of buildings.
     * @param name The name of the building.
     * @param type The type of building to add.
     */
    void addBuilding(const std::string & name, BuildingType type);

    /**
     * @brief Sets the city's overall state based on citizen happiness.
     */
    void setState();

    /**
     * @brief Gets the current state of the city.
     * @return The current CityState.
     */
    CityState getState() const;

    /**
     * @brief Removes the last building added to the city (for testing purposes).
     */
    void removeLastBuilding();

    /**
     * @brief Gets the current happiness level of the citizens (for testing purposes).
     * @return The citizen happiness level.
     */
    int getCitizenHappiness() const;

    /**
     * @brief Sets the happiness level of the citizens.
     * @param happiness New happiness level to set.
     */
    void setCitizenHappiness(int happiness);

    /**
     * @brief Calculates the overall happiness of the citizens.
     */
    void calculateHappiness();

    // UTILITIES

    /**
     * @brief Checks the usage of city utilities to determine if they are under strain.
     */
    void checkUtilityUsage();

    /**
     * @brief Gets statistics of utility usage.
     * @param temp Reference to a string where utility statistics will be stored.
     */
    void getUtilityStats(std::string& temp);

    /**
     * @brief Upgrades the city's utility infrastructure.
     */
    void upgradeUtilities();

    /**
     * @brief Repairs city utilities in case of damage or malfunction.
     */
    void repairUtilities();

    // TAX

    /**
     * @brief Checks the city's current funds.
     * @return The amount of funds available to the city.
     */
    int checkCityFunds() const;

    /**
     * @brief Initiates a new cycle of tax collection.
     */
    std::string startTaxCycle();

    /**
     * @brief Increases the city's transport services by adding vehicles.
     * @param type The type of vehicle to add.
     */
    void increaseTransport(VehicleType type);

    /**
     * @brief Changes the city's tax strategy.
     * @param taxStrategy New tax strategy to be used.
     */
    void changeTaxStrategy(std::unique_ptr<TaxStrategy> taxStrategy);

    /**
     * @brief Gets the total number of buildings in the city.
     * @return The count of buildings.
     */
    int getBuildingCount();

    /**
     * @brief Gets the total number of citizens in the city.
     * @return The count of citizens.
     */
    int getCitizenCount();

    /**
     * @brief Gets the total number of working citizens in the city.
     * @return The count of working citizens.
     */
    int getWorkerCount();

    /**
     * @brief Generates a report on the city.
     * @param temp Reference to a string where the report will be stored.
     */
    void generateReport(std::string& temp);

    /**
     * @brief Gets a list of all buildings in the city.
     * @return Vector containing pointers to all buildings.
     */
    std::vector<Building*>& getBuildings();

    /**
     * @brief Gets a list of all citizens in the city.
     * @return Vector containing pointers to all citizens.
     */
    std::vector<Citizen*>& getCitizens();

    /**
     * @brief Gets a list of all vehicles in the city.
     * @return Vector containing pointers to all vehicles.
     */
    std::vector<Vehicle*>& getVehicles();

    /**
     * @brief Gets a specific citizen by their ID.
     * @param id ID of the citizen to retrieve.
     * @return Reference to the Citizen object.
     */
    Citizen& getCitizen(int id);

    /**
     * @brief Creates a new citizen in the city.
     * @param type Type of the citizen.
     * @param satisfaction Initial satisfaction level.
     * @param funds Initial funds for the citizen.
     * @return ID or name of the created citizen.
     */
    std::string createCitizen(CitizenType type, int satisfaction, int funds);

    /**
     * @brief Gets details of a specific citizen.
     * @param id ID of the citizen to get details for.
     * @return Details of the citizen as a string.
     */
    std::string getCitizenDetails(int id);

    /**
     * @brief Adds a new building to the city.
     * @param name Name of the building.
     * @param type Type of the building.
     * @return Confirmation message upon successful addition.
     */
    std::string addNewBuilding(const std::string & name, BuildingType type);

    // GOVERNMENT DEPARTMENTS

    /**
     * @brief Gets the city's Department of Water, Power, and Sanitation.
     * @return Shared pointer to the DepartmentOfWaterPowerAndSanitation.
     */
    std::shared_ptr<DepartmentOfWaterPowerAndSanitation> getDepartmentOfWaterPowerAndSanitation() const {
     return government->getDepartmentOfWaterPowerAndSanitation();
    };

    /**
     * @brief Gets the city's Tax Authority.
     * @return Shared pointer to the TaxAuthority.
     */
    std::shared_ptr<TaxAuthority> getTaxAuthority() const {
     return government->getTaxAuthority();
    };

    /**
     * @brief Gets the city's Department of Home Affairs.
     * @return Shared pointer to the DepartmentOfHomeAffairs.
     */
    std::shared_ptr<DepartmentOfHomeAffairs> getDepartmentOfHomeAffairs() const {
     return government->getDepartmentOfHomeAffairs();
    };

    /**
     * @brief Gets the city's Transport Department.
     * @return Shared pointer to the TransportDepartment.
     */
    std::shared_ptr<TransportDepartment> getTransportDepartment() const {
     return government->getTransportDepartment();
    };

    /**
     * @brief Gets the city's Budget Department.
     * @return Shared pointer to the BudgetDepartment.
     */
    std::shared_ptr<BudgetDepartment> getBudgetDepartment() const {

        return government->getBudgetDepartment();
    }

    std::vector<std::string> getBuildingNames();
   

};

#endif // CITY_H
