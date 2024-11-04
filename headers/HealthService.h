#ifndef HEALTHSERVICE_H
#define HEALTHSERVICE_H

#include "Service.h"
#include "HealthState.h"
#include "BuildingType.h"
#include <memory>
class HealthState;

enum HealthStateType{
    HighFunding,
    LowFunding
};
class HealthService : public Service {
private:
    HealthStateType state;
    std::unique_ptr<HealthState> healthState; 
    int responseTime;
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
    HealthService(const std::string& name,int cost, std::string& location, Resources *resources, int size, Citizen& owner,  BuildingType type, int id);

     ~HealthService() override = default;

    void setState();
    int pay() override;

    void responseTimeDec(int by);

    void responseTimeInc(int by);

    int getResponseTime() const;

    std::string getState() const;
};

#endif // HEALTHSERVICE_H
