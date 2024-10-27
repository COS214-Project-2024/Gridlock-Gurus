#ifndef CITIZEN_H
#define CITIZEN_H

#include "TaxAuthority.h"
#include "Building.h"
#include <string>
using namespace std;

/**
 * @brief Represents a citizen in the city.
 *
 * The Citizen class encapsulates information and behaviors related to individual citizens,
 * including employment, taxes, and residence.
 */
class Citizen {
private:
    TaxAuthority* taxAuthority;    ///< Pointer to the TaxAuthority managing taxes for this citizen.

protected:
    string name;
    string type;              ///< The type of the citizen (e.g., worker, retiree).
    int satisfactionLevel;         ///< The satisfaction level of the citizen.
    int funds;                     ///< The amount of funds available to the citizen.
    bool employmentStatus;         ///< Employment status of the citizen (employed or not).
    bool retired;                  ///< Retirement status of the citizen.
    Building* home;                ///< Pointer to the citizen's home building.
    Building* placeOfWork;         ///< Pointer to the citizen's workplace.

public:
    /**
     * @brief Construct a new Citizen object.
     *
     * @param type The type of the citizen.
     * @param satisfactionLevel The initial satisfaction level of the citizen.
     * @param funds The initial funds available to the citizen.
     */
    Citizen(std::string type, int satisfactionLevel, int funds);

    /**
     * @brief Destroy the Citizen object.
     *
     * Cleans up resources related to the citizen.
     */
    virtual ~Citizen();

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
    void payTaxes();

    /**
     * @brief Updates the state of the citizen.
     *
     * This function is called to update various attributes of the citizen.
     */
    void update();

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

    /**
     * @brief Quits the citizen's job.
     *
     * This function updates the employment status of the citizen.
     */
    string getName();
    bool getEmploymentStatus();
    int getFunds();
};

#endif // CITIZEN_H