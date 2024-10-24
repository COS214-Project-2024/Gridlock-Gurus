#ifndef POLICESERVICE_H
#define POLICESERVICE_H

#include "Service.h"
#include "PoliceState.h"

/**
 * @brief Represents a police service building.
 *
 * ConcreteProduct participant in the Factory Method pattern. It extends the Service class and represents a specific type of service building that provides police services.
 */
class PoliceService : public Service {
private:
    PoliceState* policeState;  ///< Current state of the police service.
    int stationId;  ///< ID of the police station.
    std::list<Citizen*> officers;  ///< List of officers in the police service.

public:
    /**
     * @brief Constructs a new PoliceService building.
     * @param cost The construction cost of the police service.
     * @param location The location of the police service.
     * @param resources Pointer to the resources the police service uses.
     * @param size The size of the police service.
     * @param owner Pointer to the owner of the police service.
     * @param taxAuthority Pointer to the tax authority associated with the police service.
     */
    PoliceService(int cost, std::string location, Resources* resources, int size, Citizen* owner, TaxAuthority* taxAuthority);

    /**
     * @brief Destroys the PoliceService building.
     */
    virtual ~PoliceService();

    /**
     * @brief Gets details about the police service building.
     * @return A string containing details about the police service.
     */
    std::string getDetails() override;

    /**
     * @brief Pays taxes for the police service building.
     * @param amount The amount of tax to be paid.
     * @param owner Pointer to the building's owner.
     */
    void payTax(int amount, Citizen* owner) override;

    /**
     * @brief Sets the state of the police service.
     * @param state Pointer to the new police state.
     */
    void setState(PoliceState* state);

    /**
     * @brief Checks the operational status of the police service.
     */
    void checkOperation();

    /**
     * @brief Pays an officer in the police service.
     * @param officer Pointer to the officer being paid.
     */
    void payOfficer(Citizen* officer);
};

#endif // POLICESERVICE_H