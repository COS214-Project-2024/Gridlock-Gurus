#ifndef EDUCATIONSERVICE_H
#define EDUCATIONSERVICE_H

#include "Service.h"
#include "EducationState.h"
#include "BuildingType.h"
#include "EducationState.h"
#include <memory>
class EducationState;

enum EducationStateType{
    HighFundingEducation,
    LowFundingEducation
};
/**
 * @brief Represents an education service building.
 *
 * ConcreteProduct participant in the Factory Method pattern. It extends the Service class and represents a specific type of service building that provides education services.
 */
class EducationService : public Service {
private:
    EducationStateType state;
    std::unique_ptr<EducationState> educationState; 
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
    EducationService(int cost, std::string& location, Resources* resources, int size, Citizen& owner, int id, BuildingType name);

    /**
     * @brief Destroys the EducationService building.
     */
    ~EducationService() override = default;

    /**
     * @brief Sets the state of the education service.
     * @param state Pointer to the new education state.
     */
    void setState();

    /**
     * @brief Pays a staff member in the education service.
     * @param staffMember Pointer to the staff member being paid.
     */
    int pay() override;

    void prestigeDec(int by);
    void prestigeInc(int by);

    int getPrestige();

    std::string getState() const;

};

#endif // EDUCATIONSERVICE_H
