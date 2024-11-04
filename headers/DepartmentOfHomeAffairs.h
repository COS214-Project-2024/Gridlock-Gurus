#ifndef DEPARTMENTOFHOMEAFFAIRS_H
#define DEPARTMENTOFHOMEAFFAIRS_H

#include "CitizenFactory.h"
#include "TaxAuthority.h"
#include <vector>
#include <string>
#include <memory>
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

/**
 * @brief Forward declaration of Citizen and TaxAuthority classes.
 */
class Citizen;
class TaxAuthority;

/**
 * @brief Manages citizens and handles home affairs.
 */
class DepartmentOfHomeAffairs {
private:
    std::shared_ptr<TaxAuthority> taxAuthority; ///< Tax authority associated with this department.
    std::unique_ptr<CitizenFactory> factory;    ///< Factory to create citizens.

public:
    int population;                             ///< Current population count.
    std::vector<Citizen*> citizens;             ///< List of all citizens.

    /**
     * @brief Constructs the Department of Home Affairs with the given tax authority.
     * @param taxAuth Shared pointer to the TaxAuthority.
     */
    DepartmentOfHomeAffairs(std::shared_ptr<TaxAuthority> taxAuth);

    /**
     * @brief Destructor for DepartmentOfHomeAffairs.
     */
    ~DepartmentOfHomeAffairs();

    /**
     * @brief Calculates the average happiness of citizens.
     * @return Average happiness value.
     */
    int calculateAvgHappiness();

    /**
     * @brief Fills a house with tenants.
     */
    void fillHomeWithTenants(Residential& home);

   /**
    * @brief Fills a factory with employees.
    */
    void fillWorkWithEmployees(Factory& work);

    /**
     * @brief Fills a service with employees.
     */
    void fillWorkWithEmployees(Service& work);

    /**
     * @brief Fills a commercial lot with employees.
     */
    void fillWorkWithEmployees(Commercial& work);

    /**
     * @brief Gets a random citizen.
     * @return Reference to a randomly selected citizen.
     */
    Citizen& getRandomCitizen();

     /**
     * @brief Gets the population of a city.
     * @return Population count.
     */
    int getPopulation() {
        return population;
    }


   /**
    * @brief Creates a new citizen in the city.
    * @param type The type of citizen to create (e.g., worker, resident).
    * @param satisfaction Initial satisfaction level of the new citizen.
    * @param funds Initial funds allocated to the citizen.
    * @return A string representing the ID or name of the created citizen.
    */
     std::string createCitizen(CitizenType type, int satisfaction, int funds);

     /**
      * @brief Retrieves details of a specific citizen by their ID.
      * @param id The ID of the citizen whose details are to be retrieved.
      * @return A string containing the details of the specified citizen.
      */
     std::string getCitizenDetails(int id);

     /**
      * @brief Retrieves a reference to a specific citizen by their ID.
      * @param id The ID of the citizen to retrieve.
      * @return A reference to the Citizen object with the specified ID.
      */
     Citizen& getCitizen(int id);

     /**
      * @brief Retrieves a list of all citizens in the city.
      * @return A vector containing pointers to all Citizen objects in the city.
      */
     std::vector<Citizen*>& getCitizens();

protected:
     /**
      * @brief Registers the birth of a new citizen within the city.
      * This function is called internally when a new citizen is added to the city.
      */
     void registerBirth();

     /**
      * @brief Registers the death of a specific citizen.
      * @param citizen A reference to the Citizen object representing the deceased citizen.
      * This function handles the necessary procedures and updates to remove the citizen.
      */
     void registerDeath(Citizen& citizen);
};

#endif // DEPARTMENTOFHOMEAFFAIRS_H
