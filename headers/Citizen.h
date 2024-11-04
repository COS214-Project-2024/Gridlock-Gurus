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

/**
 * @brief Forward declaration of TaxAuthority and Building classes.
 */
class TaxAuthority;
class Building;

/**
 * @brief Represents a citizen in the city.
 */
class Citizen {
private:
    std::weak_ptr<TaxAuthority> taxAuthority;
    int id;
    std::string name;
    CitizenType type;
    int satisfactionLevel;
    int funds;
    bool employmentStatus;
    bool retired;
    Building* home;
    Building* placeOfWork;

public:
    /**
     * @brief Constructs a Citizen with specified attributes.
     * @param id Unique identifier for the citizen.
     * @param type Type of citizen.
     * @param satisfactionLevel Initial satisfaction level.
     * @param funds Initial funds available to the citizen.
     * @param taxAuthority Reference to the tax authority managing this citizen's taxes.
     */
    Citizen(int id, CitizenType type, int satisfactionLevel, int funds, std::weak_ptr<TaxAuthority> taxAuthority);

    /**
     * @brief Sets the citizen's workplace.
     * @param work Building representing the citizen's place of work.
     */
    void setWork(Building& work);

    /**
     * @brief Quits the citizen's current job.
     */
    void quitJob();

    /**
     * @brief Sets the citizen's home.
     * @param home Building representing the citizen's home.
     */
    void setHome(Building& home);

    /**
     * @brief Simulates a workday, updating the citizen's state accordingly.
     */
    void workDay();

    /**
     * @brief Collects salary for the citizen.
     */
    void collectSalary();

    /**
     * @brief Pays taxes for the citizen.
     * @param amount Amount of taxes to pay.
     */
    void payTaxes(int amount);

    /**
     * @brief Requests transport from the transport department.
     * @param department Transport department reference.
     * @param type Type of vehicle required.
     */
    void callTransport(TransportDepartment& department, VehicleType type);

    /**
     * @brief Sets the citizen's status to retired.
     */
    void retire();

    /**
     * @brief Moves the citizen to the countryside upon retirement.
     */
    void retireToCountryside();

    /**
     * @brief Sets the citizen's employment status to fired.
     */
    void fired();

    // GETTERS
    bool getEmploymentStatus() const;
    std::string getName() const;
    int getId() const;
    int getFunds() const;
    int getSatisfactionLevel() const;
    CitizenType getType() const;
    bool hasHome() const;
};

#endif // CITIZEN_H
