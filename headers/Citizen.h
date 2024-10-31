#ifndef CITIZEN_H
#define CITIZEN_H

#include "Vehicle.h"
#include "TransportDepartment.h"
#include "Building.h"
#include "TaxAuthority.h"
#include <string>
#include <memory>

class TaxAuthority;
class Building;


class Citizen {
private:
  TaxAuthority* taxAuthority;    ///< Pointer to the TaxAuthority managing taxes for this citizen.

protected:
    std::string name;
    std::string type;              ///< The type of the citizen (e.g., worker, retiree).
    int satisfactionLevel;         ///< The satisfaction level of the citizen.
    int funds;                     ///< The amount of funds available to the citizen.
    bool employmentStatus;         ///< Employment status of the citizen (employed or not).
    bool retired;                  ///< Retirement status of the citizen.
    Building* home;                ///< Pointer to the citizen's home building.
    Building* placeOfWork;         ///< Pointer to the citizen's workplace.
    int id;
    Vehicle* currentVehicle;

public:
    /**
     * @brief Construct a new Citizen object.
     *
     * @param type The type of the citizen.
     * @param satisfactionLevel The initial satisfaction level of the citizen.
     * @param funds The initial funds available to the citizen.
     */
    Citizen(int id,std::string& type, int satisfactionLevel, int funds, TaxAuthority* taxAuthority);

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
    void findWork(Building* placeOfEmployment);

    /**
     * @brief Finds a home in a specified building.
     *
     * @param home Pointer to the building that will be the citizen's home.
     */
    void findHome(Building* home);

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
    void collectSalary(Building* placeOfWork);

    /**
     * @brief Pays taxes based on the citizen's income.
     *
     * This function handles the tax payment process for the citizen.
     */
    void payTaxes(int amount);
    
    void callTransport(TransportDepartment& department, const std::string& type);
    void boardVehicle(Vehicle* vehicle);
    void offloadVehicle();

    bool isInVehicle() const;

    /**
     * @brief Retires the citizen.
     *
     * This function sets the citizen's retirement status to true.
     */
    void retire();
    void retireToCountryside();

    /**
     * @brief Quits the citizen's job.
     *
     * This function updates the employment status of the citizen.
     */
    void quitJob();
    void fired();


//GETTERS
    /**
     * @brief Checks if the citizen is currently employed.
     *
     * @return A boolean value indicating the employment status.
     */
    bool getEmploymentStatus() const {
        return this->employmentStatus;
    };

    std::string getName() const {
        return this->name;
    }

    int getId() const {
        return this->id;
    }


    /**
    * @brief Getter for the funds to the citizen.
    *
    * @return The funds of the citizen.
    */
    int getFunds() const {
        return this->funds;
    }
    
    int getSatisfactionLevel() const {
        return this->satisfactionLevel;
    }
    
    std::string getType() const {
        return this->type;
    }

};

#endif // CITIZEN_H

