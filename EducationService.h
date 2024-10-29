#ifndef EDUCATIONSERVICE_H
#define EDUCATIONSERVICE_H

#include "Service.h"
#include "EducationState.h"


/**
 * @brief Represents an education service building.
 *
 * ConcreteProduct participant in the Factory Method pattern. It extends the Service class and represents a specific type of service building that provides education services.
 */
class EducationService : public Service {
private:
    EducationState* educationState;  ///< Current state of the education service.
    int schoolId;  ///< ID of the school.
    std::list<Citizen*> staff;  ///< List of staff members in the education service.
    int maxStaff;
    int currentStaff;
    string schoolName;
    int prestige;

public:
    /**
     * @brief Constructs a new EducationService building.
     * @param cost The construction cost of the education service.
     * @param location The location of the education service.
     * @param resources Pointer to the resources the education service uses.
     * @param size The size of the education service.
     * @param owner Pointer to the owner of the education service.
     * @param taxAuthority Pointer to the tax authority associated with the education service.
     */
    EducationService(int cost, std::string location, Resources* resources, int size, Citizen* owner, TaxAuthority* taxAuthority, int id, int max, string name);

    /**
     * @brief Destroys the EducationService building.
     */
    virtual ~EducationService() = default;

    /**
     * @brief Gets details about the education service building.
     * @return A string containing details about the education service.
     */
    std::string getDetails() override;

    /**
     * @brief Pays taxes for the education service building.
     * @param amount The amount of tax to be paid.
     * @param owner Pointer to the building's owner.
     */
    void payTax(int amount, Citizen* owner) override;

    /**
     * @brief Sets the state of the education service.
     * @param state Pointer to the new education state.
     */
    void setState(EducationState* state);

    /**
     * @brief Checks the operational status of the education service.
     */
    void checkOperation();

    /**
     * @brief Pays a staff member in the education service.
     * @param staffMember Pointer to the staff member being paid.
     */
    int pay(Citizen* staffMember);
    void employ(Citizen* employee);
    void fire(Citizen* employee);
    void retire(Citizen* employee);
    int getStaff();
    int getMaxStaff();
    void prestigeDec(int by);
    void prestigeInc(int by);
    int getPrestige();
};

#endif // EDUCATIONSERVICE_H