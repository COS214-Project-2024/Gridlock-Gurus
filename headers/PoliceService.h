#ifndef POLICESERVICE_H
#define POLICESERVICE_H

#include "Service.h"
#include "PoliceState.h"
#include "BuildingType.h"
#include <memory>
#include <vector>
class PoliceState;

enum PoliceStateType{
    Peace,
    Unrest
};
class PoliceService : public Service {
private:
    PoliceStateType state;
    std::unique_ptr<PoliceState> policeState;
    int responseTime;

public:
    /**
     * @brief Constructs a new PoliceService building.
     * @param name The name of the police service.
     * @param cost The construction cost.
     * @param location The location of the service.
     * @param resources Pointer to the resources used.
     * @param size The size of the service.
     * @param owner Reference to the owner of the service.
     * @param id The unique identifier for the service.
     * @param type The building type.
     */
    PoliceService(const std::string& name, int cost, std::string& location, Resources* resources, int size, Citizen& owner, int id, BuildingType type);

    /**
     * @brief Destructor for PoliceService.
     */
    ~PoliceService() override = default;

    /**
     * @brief Sets the current state of the police service.
     */
    void setState();

    /**
     * @brief Pays the due amount for the police service.
     * @return The paid amount.
     */
    int pay() override;

    /**
     * @brief Decreases the response time by a specified amount.
     * @param by The amount to decrease the response time by.
     */
    void responseTimeDec(int by);

    /**
     * @brief Increases the response time by a specified amount.
     * @param by The amount to increase the response time by.
     */
    void responseTimeInc(int by);

    /**
     * @brief Gets the current response time of the police service.
     * @return The response time.
     */
    int getResponseTime() const {
        return responseTime;
    }

    /**
     * @brief Gets the current state of the police service as a string.
     * @return The state as a string.
     */
    std::string getState() const;
};

#endif // POLICESERVICE_H
