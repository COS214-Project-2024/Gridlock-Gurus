#ifndef HEALTHSERVICE_H
#define HEALTHSERVICE_H

#include "Service.h"
#include "HealthState.h"

/**
 * @brief Represents a health service building.
 *
 * ConcreteProduct participant in the Factory Method pattern. It extends the Service class and represents a specific type of service building that provides health services.
 */
class HealthService : public Service {
private:
    HealthState* healthState;  ///< Current state of the health service.
    int hospitalId;  ///< ID of the hospital.
    std::list<Citizen*> staff;  ///< List of staff members in the health service.

public:
    /**
     * @brief Constructs a new HealthService building.
     * @param cost The construction cost of the health service.
     * @param location The location of the health service.
     * @param resources Pointer to the resources the health service uses.
     * @param size The size of the health service.
     * @param owner Pointer to the owner of the health service.
     * @param taxAuthority Pointer to the tax authority associated with the health service.
     */
    HealthService(int cost, std::string location, Resources* resources, int size, Citizen* owner, TaxAuthority* taxAuthority);

    /**
     * @brief Destroys the HealthService building.
     */
    virtual ~HealthService();

    /**
     * @brief Gets details about the health service building.
     * @return A string containing details about the health service.
     */
    std::string getDetails() override;

    /**
     * @brief Pays taxes for the health service building.
     * @param amount The amount of tax to be paid.
     * @param owner Pointer to the building's owner.
     */
    void payTax(int amount, Citizen* owner) override;

    /**
     * @brief Sets the state of the health service.
     * @param state Pointer to the new health state.
     */
    void setState(HealthState* state);

    /**
     * @brief Checks the operational status of the health service.
     */
    void checkOperation();

    /**
     * @brief Pays a staff member in the health service.
     * @param staffMember Pointer to the staff member being paid.
     */
    void payStaff(Citizen* staffMember);
};

#endif // HEALTHSERVICE_H