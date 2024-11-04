/**
 * @file Citizen.h
 * @brief Defines the Citizen class representing an individual in the simulation.
 */

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

/**
 * @class Citizen
 * @brief Represents a citizen with properties such as employment status, funds, and satisfaction level.
 */
class Citizen {
private:
    std::weak_ptr<TaxAuthority> taxAuthority; ///< Weak pointer to the Tax Authority for managing taxes.

protected:
    std::string name; ///< Name of the citizen.
    CitizenType type; ///< Type of the citizen (e.g., worker, retired).
    int satisfactionLevel; ///< Satisfaction level of the citizen.
    int funds; ///< Financial funds available to the citizen.
    bool employmentStatus; ///< Employment status of the citizen.
    bool retired; ///< Retirement status of the citizen.
    Building* home; ///< Pointer to the citizen's home building.
    Building* placeOfWork; ///< Pointer to the citizen's workplace.
    int id; ///< Unique identifier for the citizen.

public:
    /**
     * @brief Constructs a Citizen object.
     * @param id Unique identifier for the citizen.
     * @param type Type of the citizen.
     * @param satisfactionLevel Initial satisfaction level of the citizen.
     * @param funds Initial amount of funds the citizen has.
     * @param taxAuthority Weak pointer to the Tax Authority.
     */
    Citizen(int id, CitizenType type, int satisfactionLevel, int funds, std::weak_ptr<TaxAuthority> taxAuthority);

    /**
     * @brief Destructor for the Citizen class.
     */
    ~Citizen() = default;

    /**
     * @brief Assigns a workplace to the citizen.
     * @param work Reference to the building that will be the citizen's workplace.
     */
    void setWork(Building& work);

    /**
     * @brief Causes the citizen to quit their job, removing their workplace.
     */
    void quitJob();

    /**
     * @brief Assigns a home to the citizen.
     * @param home Reference to the building that will be the citizen's home.
     */
    void setHome(Building& home);

    /**
     * @brief Simulates a work day for the citizen.
     */
    void workDay();

    /**
     * @brief Collects the salary for the citizen.
     */
    void collectSalary();

    /**
     * @brief Pays taxes to the Tax Authority.
     * @param amount The amount of tax to be paid.
     */
    void payTaxes(int amount);

    /**
     * @brief Calls transport for the citizen through the specified transport department.
     * @param department Reference to the transport department.
     * @param type Type of vehicle requested.
     */
    void callTransport(TransportDepartment& department, VehicleType type);

    /**
     * @brief Retires the citizen.
     */
    void retire();

    /**
     * @brief Retires the citizen to the countryside.
     */
    void retireToCountryside();

    /**
     * @brief Handles the event of the citizen being fired from their job.
     */
    void fired();

    // GETTERS

    /**
     * @brief Gets the employment status of the citizen.
     * @return True if employed, false otherwise.
     */
    bool getEmploymentStatus() const {
     return this->employmentStatus;
    };

    /**
     * @brief Gets the name of the citizen.
     * @return Name of the citizen.
     */
    std::string getName() const {
     return this->name;
    };

    /**
     * @brief Gets the unique identifier of the citizen.
     * @return Citizen's unique identifier.
     */
    int getId() const {
     return this->id;
    };

    /**
     * @brief Gets the funds available to the citizen.
     * @return Amount of funds.
     */
    int getFunds() const {
     return this->funds;
    };

    /**
     * @brief Gets the satisfaction level of the citizen.
     * @return Satisfaction level.
     */
    int getSatisfactionLevel() const {
     return this->satisfactionLevel;
    };

    /**
     * @brief Gets the type of the citizen.
     * @return Type of the citizen.
     */
    CitizenType getType() const {
     return this->type;
    };

    /**
     * @brief Checks if the citizen has a home.
     * @return True if the citizen has a home, false otherwise.
     */
    bool hasHome() const {
     return this->home != nullptr;
    };
};

#endif // CITIZEN_H
