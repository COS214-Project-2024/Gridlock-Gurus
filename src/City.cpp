#include "City.h"

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
    
City::~City() {
    delete factory_factory;
    delete landmark_factory;
    delete residential_factory;
    delete commercial_factory;
    delete service_factory;
}

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

void City::setState() {
    if(citizen_happiness > 65) {
        state = CityState::Happy;
    } else if (citizen_happiness < 40) {
        state = CityState::Upset;
    } else {
        state = CityState::Normal;
    }   
}

CityState City::getState() const {
    return state;
}

void City::removeLastBuilding() {
    government->getTaxAuthority()->removeLastBuilding();
}

int City::getCitizenHappiness() const {
    return citizen_happiness;
}

void City::setCitizenHappiness(int happiness) {
    this->citizen_happiness = happiness;
}

void City::calculateHappiness() {
    setCitizenHappiness(government->getDepartmentOfHomeAffairs()->calculateAvgHappiness());
    setState();        
}

void City::checkUtilityUsage() {
    int totalWater = government->getTaxAuthority()->getWaterUsage();
    int totalPower = government->getTaxAuthority()->getPowerUsage();
     government->getDepartmentOfWaterPowerAndSanitation()->reviewWaterUsage(totalWater);
     government->getDepartmentOfWaterPowerAndSanitation()->reviewPowerUsage(totalPower);
}

void City::getUtilityStats(std::string& temp) {
    temp += government->getDepartmentOfWaterPowerAndSanitation()->checkNetwork();
}

void City::upgradeUtilities() {
    government->getDepartmentOfWaterPowerAndSanitation()->upgrade();
    std::cout << "Utilites have been upgraded and undergone any repairs.\n";
}

void City::repairUtilities() {
    int bill = government->getDepartmentOfWaterPowerAndSanitation()->repair();
    std::cout << "City spent $" << bill << " to repair utilities\n";
}

int City::checkCityFunds() const {
    return government->getBudgetDepartment()->checkTotal();
}

void City::startTaxCycle() {
    government->getBudgetDepartment()->receiveTaxes();
}

int City::getBuildingCount() {
    return government->getTaxAuthority()->getSize();
}

int City::getCitizenCount() {
    return government->getDepartmentOfHomeAffairs()->getPopulation();
}

int City::getWorkerCount() {
    return government->getTaxAuthority()->getAmountOfCitizens();
}

void City::increaseTransport(VehicleType type){
    government->getTransportDepartment()->addTransport(type);
}

void City::changeTaxStrategy(std::unique_ptr<TaxStrategy> taxStrategy){
    return government->getTaxAuthority()->setStrategy(std::move(taxStrategy));
}

void City::generateReport(std::string& temp) {
    government->getTransportDepartment()->getReport(temp);
    getUtilityStats(temp);
}

std::vector<Building*>& City::getBuildings() {
    return government->getTaxAuthority()->getBuildings();
}

std::vector<Citizen*>& City::getCitizens() {
    return government->getDepartmentOfHomeAffairs()->getCitizens();
}

std::vector<Vehicle*>& City::getVehicles() {
    return government->getTransportDepartment()->getFleet();
}

Citizen& City::getCitizen(int id) {
    return government->getDepartmentOfHomeAffairs()->getCitizen(id);
}

std::string City::createCitizen(CitizenType type, int satisfaction, int funds) {
    return government->getDepartmentOfHomeAffairs()->createCitizen(type,satisfaction, funds);
}

std::string City::getCitizenDetails(int id) {
    return government->getDepartmentOfHomeAffairs()->getCitizenDetails(id);
}



