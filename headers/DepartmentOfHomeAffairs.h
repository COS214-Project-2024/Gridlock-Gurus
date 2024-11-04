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

    void fillHomeWithTenants(Residential& home);
    void fillWorkWithEmployees(Factory& work);
    void fillWorkWithEmployees(Service& work);
    void fillWorkWithEmployees(Commercial& work);

    /**
     * @brief Gets a random citizen.
     * @return Reference to a randomly selected citizen.
     */
    Citizen& getRandomCitizen();

    int getPopulation() {
        return population;
    }

    std::string createCitizen(CitizenType type, int satisfaction, int funds);
    std::string getCitizenDetails(int id);
    Citizen& getCitizen(int id);
    std::vector<Citizen*>& getCitizens();

protected:
    void registerBirth();
    void registerDeath(Citizen& citizen);
};

#endif // DEPARTMENTOFHOMEAFFAIRS_H
