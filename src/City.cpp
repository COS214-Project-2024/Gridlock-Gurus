#include "City.h"

/**
 * @brief Constructs a City with initialized factories and state.
 */
City::City() {
    this->government = Government::getInstance();
    this->factory_factory = new FactoryFactory(government->getTaxAuthority());
    this->landmark_factory = new LandmarkFactory(government->getTaxAuthority());
    this->residential_factory = new ResidentialFactory(government->getTaxAuthority());
    this->commercial_factory = new CommercialFactory(government->getTaxAuthority());
    this->service_factory = new ServiceFactory(government->getTaxAuthority());
    state = CityState::Happy;
    citizen_happiness = 0;
};

/**
 * @brief Destructor that cleans up city resources.
 */
City::~City() {
    delete factory_factory;
    delete landmark_factory;
    delete residential_factory;
    delete commercial_factory;
    delete service_factory;
}

/**
 * @brief Adds a building to the city.
 * @param name Name of the building.
 * @param type Type of the building.
 */
void City::addBuilding(const std::string& name, BuildingType type){
    Citizen& citizen = government->getDepartmentOfHomeAffairs()->getRandomCitizen();

    if(type == BuildingType::BrickFactory ||type == BuildingType::SteelFactory || type == BuildingType::WoodFactory) {
        //Factory
        Building* temp = factory_factory->createBuilding(name,type,citizen); 
        Factory* work = dynamic_cast<Factory*>(temp);
        government->getDepartmentOfHomeAffairs()->fillWorkWithEmployees(*work);

    } else if(type == BuildingType::Shop ||type == BuildingType::Bank) {
        Building* temp = commercial_factory->createBuilding(name,type,citizen); 
        Commercial* work = dynamic_cast<Commercial*>(temp);
        government->getDepartmentOfHomeAffairs()->fillWorkWithEmployees(*work); 

    } else if(type == BuildingType::Flat ||type == BuildingType::House || type == BuildingType::Estate) {
        Building* temp = residential_factory->createBuilding(name,type,citizen); 
        Residential* home = dynamic_cast<Residential*>(temp);
        government->getDepartmentOfHomeAffairs()->fillHomeWithTenants(*home); 

    } else if(type == BuildingType::Statue ||type == BuildingType::Park) {
        //Landmark
        landmark_factory->createBuilding(name,type,citizen); 
    } else {
        //Service
        Building* temp = service_factory->createBuilding(name,type,citizen); 
        Service* work = dynamic_cast<Service*>(temp);
        government->getDepartmentOfHomeAffairs()->fillWorkWithEmployees(*work); 
    }
}

/**
 * @brief Adds a new building and returns a confirmation message.
 * @param name Name of the building.
 * @param type Type of the building.
 * @return Confirmation message.
 */
std::string City::addNewBuilding(const std::string & name,BuildingType type){
 Citizen& citizen = government->getDepartmentOfHomeAffairs()->getRandomCitizen();

    if(type == BuildingType::BrickFactory ||type == BuildingType::SteelFactory || type == BuildingType::WoodFactory) {
        //Factory
        Building* temp = factory_factory->createBuilding(name,type,citizen); 
        Factory* work = dynamic_cast<Factory*>(temp);
        government->getDepartmentOfHomeAffairs()->fillWorkWithEmployees(*work);

    } else if(type == BuildingType::Shop ||type == BuildingType::Bank) {
        Building* temp = commercial_factory->createBuilding(name,type,citizen); 
        Commercial* work = dynamic_cast<Commercial*>(temp);
        government->getDepartmentOfHomeAffairs()->fillWorkWithEmployees(*work); 

    } else if(type == BuildingType::Flat ||type == BuildingType::House || type == BuildingType::Estate) {
        Building* temp = residential_factory->createBuilding(name,type,citizen); 
        Residential* home = dynamic_cast<Residential*>(temp);
        government->getDepartmentOfHomeAffairs()->fillHomeWithTenants(*home); 

    } else if(type == BuildingType::Statue ||type == BuildingType::Park) {
        //Landmark
        landmark_factory->createBuilding(name,type,citizen); 
    } else {
        //Service
        Building* temp = service_factory->createBuilding(name,type,citizen); 
        Service* work = dynamic_cast<Service*>(temp);
        government->getDepartmentOfHomeAffairs()->fillWorkWithEmployees(*work); 
    }

    return name + " has been constructed";
}

/**
 * @brief Updates the city's state based on citizen happiness.
 */
void City::setState() {
    if(citizen_happiness > 65) {
        state = CityState::Happy;
    } else if (citizen_happiness < 40) {
        state = CityState::Upset;
    } else {
        state = CityState::Normal;
    }   
}

/**
 * @brief Gets the current state of the city.
 * @return Current state of the city.
 */
CityState City::getState() const {
    return state;
}

/**
 * @brief Removes the last building added to the city.
 */
void City::removeLastBuilding() {
    government->getTaxAuthority()->removeLastBuilding();
}

/**
 * @brief Gets the happiness level of citizens.
 * @return Happiness level.
 */
int City::getCitizenHappiness() const {
    return citizen_happiness;
}

/**
 * @brief Sets the citizen happiness level.
 * @param happiness New happiness level.
 */
void City::setCitizenHappiness(int happiness) {
    this->citizen_happiness = happiness;
}

/**
 * @brief Calculates the average happiness of citizens.
 */
void City::calculateHappiness() {
    setCitizenHappiness(government->getDepartmentOfHomeAffairs()->calculateAvgHappiness());
    setState();        
}

/**
 * @brief Checks the utility usage of the city.
 */
void City::checkUtilityUsage() {
    int totalWater = government->getTaxAuthority()->getWaterUsage();
    int totalPower = government->getTaxAuthority()->getPowerUsage();
     government->getDepartmentOfWaterPowerAndSanitation()->reviewWaterUsage(totalWater);
     government->getDepartmentOfWaterPowerAndSanitation()->reviewPowerUsage(totalPower);
}

/**
 * @brief Gets utility statistics and appends them to the provided string.
 * @param temp String to append statistics to.
 */
void City::getUtilityStats(std::string& temp) {
    temp += government->getDepartmentOfWaterPowerAndSanitation()->checkNetwork();
}

/**
 * @brief Upgrades the city's utilities.
 */
void City::upgradeUtilities() {
    government->getDepartmentOfWaterPowerAndSanitation()->upgrade();
    std::cout << "Utilites have been upgraded and undergone any repairs.\n";
}

/**
 * @brief Repairs the city's utilities and logs the expense.
 */
void City::repairUtilities() {
    int bill = government->getDepartmentOfWaterPowerAndSanitation()->repair();
    std::cout << "City spent $" << bill << " to repair utilities\n";
}

/**
 * @brief Checks the total funds available to the city.
 * @return Total city funds.
 */
int City::checkCityFunds() const {
    return government->getBudgetDepartment()->checkTotal();
}

/**
 * @brief Starts the tax collection cycle for the city.
 */
void City::startTaxCycle() {
    government->getBudgetDepartment()->receiveTaxes();
}

/**
 * @brief Gets the total number of buildings in the city.
 * @return Number of buildings.
 */
int City::getBuildingCount() {
    return government->getTaxAuthority()->getSize();
}

/**
 * @brief Gets the total number of citizens in the city.
 * @return Number of citizens.
 */
int City::getCitizenCount() {
    return government->getDepartmentOfHomeAffairs()->getPopulation();
}

/**
 * @brief Gets the total number of workers in the city.
 * @return Number of workers.
 */
int City::getWorkerCount() {
    return government->getTaxAuthority()->getAmountOfCitizens();
}

/**
 * @brief Increases the transport available in the city.
 * @param type Type of vehicle to add.
 */
void City::increaseTransport(VehicleType type){
    government->getTransportDepartment()->addTransport(type);
}

/**
 * @brief Changes the city's tax strategy.
 * @param taxStrategy New tax strategy.
 */
void City::changeTaxStrategy(std::unique_ptr<TaxStrategy> taxStrategy){
    return government->getTaxAuthority()->setStrategy(std::move(taxStrategy));
}

/**
 * @brief Generates a report of the city's status.
 * @param temp String to append report data to.
 */
void City::generateReport(std::string& temp) {
    government->getTransportDepartment()->getReport(temp);
    getUtilityStats(temp);
}

/**
 * @brief Gets a vector of all buildings in the city.
 * @return Vector of pointers to buildings.
 */
std::vector<Building*>& City::getBuildings() {
    return government->getTaxAuthority()->getBuildings();
}

/**
 * @brief Gets a vector of all citizens in the city.
 * @return Vector of pointers to citizens.
 */
std::vector<Citizen*>& City::getCitizens() {
    return government->getDepartmentOfHomeAffairs()->getCitizens();
}

/**
 * @brief Gets a vector of all vehicles in the city.
 * @return Vector of pointers to vehicles.
 */
std::vector<Vehicle*>& City::getVehicles() {
    return government->getTransportDepartment()->getFleet();
}

/**
 * @brief Retrieves a reference to a citizen by their unique identifier.
 *
 * This function accesses the Department of Home Affairs to fetch the
 * citizen associated with the given ID.
 *
 * @param id The unique identifier of the citizen to retrieve.
 * @return Reference to the Citizen object associated with the specified ID.
 *
 * @throws std::out_of_range if no citizen exists with the provided ID.
 */
Citizen& City::getCitizen(int id) {
    return government->getDepartmentOfHomeAffairs()->getCitizen(id);
}

/**
 * @brief Creates a new citizen with specified attributes.
 *
 * This function allows for the creation of a new citizen of the specified
 * type, initial satisfaction level, and available funds. It returns a
 * string indicating the result of the creation process.
 *
 * @param type The type of citizen to be created (e.g., Resident, Visitor).
 * @param satisfaction The initial satisfaction level of the citizen (0-100).
 * @param funds The initial funds available to the citizen.
 * @return A string indicating the result of the citizen creation process.
 */
std::string City::createCitizen(CitizenType type, int satisfaction, int funds) {
    return government->getDepartmentOfHomeAffairs()->createCitizen(type,satisfaction, funds);
}


/**
 * @brief Retrieves detailed information about a specific citizen.
 *
 * This function fetches and returns a string containing details about
 * the citizen associated with the provided ID. This may include
 * attributes such as name, type, satisfaction level, and funds.
 *
 * @param id The unique identifier of the citizen whose details are to be retrieved.
 * @return A string containing the details of the specified citizen.
 *
 * @throws std::out_of_range if no citizen exists with the provided ID.
 */
std::string City::getCitizenDetails(int id) {
    return government->getDepartmentOfHomeAffairs()->getCitizenDetails(id);
}



