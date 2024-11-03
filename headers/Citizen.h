#ifndef CITIZEN_H
#define CITIZEN_H

#include "Vehicle.h"
#include "VehicleType.h"
#include "TransportDepartment.h"
#include "Building.h"
#include "TaxAuthority.h"
#include "CitizenType.h"
#include <string>
#include <memory>

class TaxAuthority;
class Building;


class Citizen {
private:
    std::weak_ptr<TaxAuthority> taxAuthority;

protected:
    std::string name;
    CitizenType type;              ///< The type of the citizen (e.g., worker, retiree).
    int satisfactionLevel;         ///< The satisfaction level of the citizen.
    int funds;                     ///< The amount of funds available to the citizen.
    bool employmentStatus;         ///< Employment status of the citizen (employed or not).
    bool retired;                  ///< Retirement status of the citizen.

    Building* home;                ///< Pointer to the citizen's home building.
    Building* placeOfWork;         ///< Pointer to the citizen's workplace.

    int id;

public:
    /**
     * @brief Construct a new Citizen object.
     *
     * @param type The type of the citizen.
     * @param satisfactionLevel The initial satisfaction level of the citizen.
     * @param funds The initial funds available to the citizen.
     */
    Citizen(int id,CitizenType type, int satisfactionLevel, int funds, std::weak_ptr<TaxAuthority> taxAuthority);

    /**
     * @brief Destroy the Citizen object.
     *
     * Cleans up resources related to the citizen.
     */
     ~Citizen() = default;

    /**
     * @brief Finds employment at a specified building.
     *
     * @param placeOfEmployment Pointer to the building where the citizen will work.
     */
    void setWork(Building& work);
    void quitJob() ;
    /**
     * @brief Finds a home in a specified building.
     *
     * @param home Pointer to the building that will be the citizen's home.
     */
    void setHome(Building& home);

    /**
     * @brief Simulates a workday for the citizen.
     *
     * This function executes daily tasks associated with the citizen's job.
     */
    void workDay();

    /**
     * @brief Collects salary from the place of work.
     *
     * @param placeOfWork Pointer to the building where the citizen works.
     */
    void collectSalary();

    /**
     * @brief Pays taxes based on the citizen's income.
     *
     * This function handles the tax payment process for the citizen.
     */
    void payTaxes(int amount);
    
    void callTransport(TransportDepartment& department, VehicleType type);

    void retire();
    void retireToCountryside();

    void fired();


//GETTERS
    bool getEmploymentStatus() const {
        return this->employmentStatus;
    };

    std::string getName() const {
        return this->name;
    }

    int getId() const {
        return this->id;
    }

    int getFunds() const {
        return this->funds;
    }
    
    int getSatisfactionLevel() const {
        return this->satisfactionLevel;
    }
    
    CitizenType getType() const {
        return this->type;
    }

    bool hasHome() const {
        return this->home != nullptr;
    }


};

#endif // CITIZEN_H

