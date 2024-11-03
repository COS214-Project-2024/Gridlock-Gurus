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
class EducationService : public Service {
private:
    EducationStateType state;
    std::unique_ptr<EducationState> educationState; 
    int prestige;

public:
    EducationService(int cost, std::string& location, Resources* resources, int size, Citizen& owner, int id, BuildingType name);
    ~EducationService() override = default;
    void setState();
    int pay() override;
    void prestigeDec(int by);
    void prestigeInc(int by);

    int getPrestige();

    std::string getState() const;

};

#endif // EDUCATIONSERVICE_H
