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
/**
 * @brief Represents a health service building.
 *
 * ConcreteProduct participant in the Factory Method pattern. It extends the Service class and represents a specific type of service building that provides health services.
 */
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
    HealthService(int cost, std::string& location, Resources *resources, int size, Citizen& owner,  BuildingType name, int id);

    /**
     * @brief Destroys the HealthService building.
     */
     ~HealthService() override = default;

    /**
     * @brief Sets the state of the health service.
     * @param state Pointer to the new health state.
     */
    void setState();

    /**
     * @brief Pays a staff member in the health service.
     * @param staffMember Pointer to the staff member being paid.
     */
    int pay() override;

    void responseTimeDec(int by);

    void responseTimeInc(int by);

    int getResponseTime() const;

    std::string getState() const;
};

#endif // HEALTHSERVICE_H
