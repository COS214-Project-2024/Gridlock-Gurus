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
    PoliceService(int cost, std::string& location, Resources *resources, int size, Citizen& owner, int id,BuildingType name);
    ~PoliceService() override = default;
    // void payTax(int amount) override;
    void setState();
    int pay() override;

    void responseTimeDec(int by);

    void responseTimeInc(int by);

    int getResponseTime() const {
        return responseTime;
    }

    std::string getState() const; 
};


#endif // POLICESERVICE_H
