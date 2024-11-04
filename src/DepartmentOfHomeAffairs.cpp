#include "DepartmentOfHomeAffairs.h"
#include "CitizenType.h"
#include <random>

/**
 * @brief Constructs a DepartmentOfHomeAffairs with the given TaxAuthority.
 *
 * @param taxAuth A shared pointer to the TaxAuthority.
 */
DepartmentOfHomeAffairs::DepartmentOfHomeAffairs(std::shared_ptr<TaxAuthority> taxAuth) : taxAuthority(taxAuth){
    this->population = 0;
    this->factory = std::make_unique<CitizenFactory>(taxAuth);
}

/**
 * @brief Destructor for the DepartmentOfHomeAffairs.
 *
 * Cleans up the citizens and deregisters them from the TaxAuthority.
 */
DepartmentOfHomeAffairs::~DepartmentOfHomeAffairs() {
    taxAuthority->deregisterAllCitizens();

    for (Citizen* citizen : citizens) {
        if(citizen) {
            citizen->quitJob();
            delete citizen;
        }
    }
     citizens.clear();
}

/**
 * @brief Registers the birth of a new citizen.
 *
 * A new worker citizen is created and added to the citizens list,
 * increasing the population count.
 */
void DepartmentOfHomeAffairs::registerBirth() {
    citizens.push_back(factory->createCitizen(CitizenType::Worker, 100, 1000));
    ++population;
}

/**
 * @brief Registers the death of a citizen.
 *
 * @param citizen The citizen to be removed.
 *
 * If the citizen is found, they are deleted, and the population is decremented.
 */
void DepartmentOfHomeAffairs::registerDeath(Citizen& citizen) {
     auto it = std::find(citizens.begin(), citizens.end(), &citizen);
    
    if (it != citizens.end()) {
        delete *it;
        citizens.erase(it);  
        --population;
    }
}

/**
 * @brief Calculates the average happiness level of the citizens.
 *
 * @return The average satisfaction level. Returns 0 if no citizens are present.
 */
int DepartmentOfHomeAffairs::calculateAvgHappiness() {
    if(citizens.size() == 0) return 0;

    int average = 0;
    for(Citizen* c: citizens){
        average += c->getSatisfactionLevel();
    }

    average /= citizens.size();

    return average;
}

/**
 * @brief Fills a Residential building with tenants.
 *
 * @param home The residential building to fill with tenants.
 *
 * Citizens are created and added until the building is full.
 */
void DepartmentOfHomeAffairs::fillHomeWithTenants(Residential& home) {
    while(!home.isFull()) {
        Citizen* c = factory->createCitizen(CitizenType::Citizen, 100, 1000);
        citizens.push_back(c);
        home.addTenant(*c);
        ++population;
    }
}

/**
 * @brief Fills a Factory building with employees.
 *
 * @param work The factory to fill with workers.
 *
 * Citizens are created and employed until the factory is full.
 */
void DepartmentOfHomeAffairs::fillWorkWithEmployees(Factory& work) {
    while(!work.isFull()) {
        Citizen* c = factory->createCitizen(CitizenType::Worker, 100, 1000);
        citizens.push_back(c);
        work.employ(*c);
        ++population;
    }
}

/**
 * @brief Fills a Service building with employees.
 *
 * @param work The service building to fill with workers.
 *
 * Citizens are created and employed until the service building is full.
 */
void DepartmentOfHomeAffairs::fillWorkWithEmployees(Service& work) {
    while(!work.isFull()) {
            Citizen* c = factory->createCitizen(CitizenType::Worker, 100, 1000);
            citizens.push_back(c);
            work.employ(*c);
            ++population;
        }
}

/**
 * @brief Fills a Commercial building with employees.
 *
 * @param work The commercial building to fill with workers.
 *
 * Citizens are created and employed until the commercial building is full.
 */
void DepartmentOfHomeAffairs::fillWorkWithEmployees(Commercial& work){
    while(!work.isFull()) {
            Citizen* c = factory->createCitizen(CitizenType::Worker, 100, 1000);
            citizens.push_back(c);
            work.employ(*c);
            ++population;
        }
}

/**
 * @brief Retrieves a random citizen from the list of citizens.
 *
 * If the citizen list is empty, a new worker citizen is created and added
 * to the list. A random citizen is then selected and returned.
 *
 * @return A reference to a random Citizen object.
 */
Citizen& DepartmentOfHomeAffairs::getRandomCitizen(){
    // Ensure the vector is not empty
    if (citizens.empty()) {
        Citizen* c = factory->createCitizen(CitizenType::Worker, 100, 1000);
        citizens.push_back(c);
        ++population;
        return *c;
    }

    std::random_device rd;                         
    std::mt19937 gen(rd());                           
    std::uniform_int_distribution<> dist(0, citizens.size() - 1);  
    int randomIndex = dist(gen);             
    return *citizens[randomIndex];  
}


/**
 * @brief Creates a new citizen of the specified type with given satisfaction and funds.
 *
 * The created citizen is added to the citizens list, and the population count is incremented.
 *
 * @param type The type of citizen to create (e.g., Worker, Citizen).
 * @param satisfaction The initial satisfaction level of the citizen.
 * @param funds The initial amount of funds the citizen has.
 *
 * @return A string message indicating the citizen's name and initial funds.
 */
std::string DepartmentOfHomeAffairs::createCitizen(CitizenType type, int satisfaction, int funds){
    Citizen* c = factory->createCitizen(type, satisfaction, funds);
    std::string name = c->getName();
    citizens.push_back(c);
    ++population;
    return name + " was created with $" + std::to_string(funds) + " in their account.";
}

/**
 * @brief Retrieves the details of a citizen by their ID.
 *
 * The details include the citizen's ID, name, funds, and satisfaction level.
 *
 * @param id The ID of the citizen to retrieve details for.
 *
 * @return A string containing the citizen's details or an empty string if the citizen is not found.
 */
std::string DepartmentOfHomeAffairs::getCitizenDetails(int id) {
    std::string details = "";
    for(Citizen* c : citizens) {
        if(c->getId() == id) {
            details += "#";
            details += std::to_string(c->getId());
            details += "\nName:\t";
            details += c->getName();
            details += "\nFunds:\t";
            details += std::to_string(c->getFunds());
            details += "\nSatisfaction Level:\t";
            details += std::to_string(c->getSatisfactionLevel());
        }
    }
    return details;
}

/**
 * @brief Retrieves a citizen by their ID, or a random citizen if not found.
 *
 * Searches for a citizen with the specified ID. If found, returns the citizen;
 * otherwise, a random citizen is returned.
 *
 * @param id The ID of the citizen to retrieve.
 *
 * @return A reference to the found Citizen object or a random Citizen if not found.
 */
Citizen& DepartmentOfHomeAffairs::getCitizen(int id) {
    for (Citizen* c : citizens) {
        if(c->getId() == id) {
            return *c;
        }
    }
    return getRandomCitizen();
}

/**
 * @brief Retrieves the list of citizens.
 *
 * This function returns a reference to the vector containing all citizens
 * managed by the Department of Home Affairs.
 *
 * @return A reference to the vector of Citizen pointers.
 */
std::vector<Citizen*>& DepartmentOfHomeAffairs::getCitizens() {
    return citizens;
}
