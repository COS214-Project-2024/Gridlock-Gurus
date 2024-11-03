#ifndef CITIZEN_H
#define CITIZEN_H

#include "Vehicle.h"
#include "VehicleType.h"
#include "TransportDepartment.h"
#include "Building.h"
#include "TaxAuthority.h"
#include "CitizenType.h"
#include <string>
#include <memory>

class TaxAuthority;
class Building;


class Citizen {
private:
    std::weak_ptr<TaxAuthority> taxAuthority;

protected:
    std::string name;
    CitizenType type;
    int satisfactionLevel;
    int funds;
    bool employmentStatus;
    bool retired;

    Building* home;
    Building* placeOfWork;

    int id;

public:
    Citizen(int id,CitizenType type, int satisfactionLevel, int funds, std::weak_ptr<TaxAuthority> taxAuthority);

     ~Citizen() = default;

    void setWork(Building& work);

    void setHome(Building& home);

    void workDay();

    void collectSalary();

    void payTaxes(int amount);
    
    void callTransport(TransportDepartment& department, VehicleType type);

    void retire();
    void retireToCountryside();

    void fired();


//GETTERS
    bool getEmploymentStatus() const {
        return this->employmentStatus;
    };

    std::string getName() const {
        return this->name;
    }

    int getId() const {
        return this->id;
    }

    int getFunds() const {
        return this->funds;
    }
    
    int getSatisfactionLevel() const {
        return this->satisfactionLevel;
    }
    
    CitizenType getType() const {
        return this->type;
    }

    bool hasHome() const {
        return this->home != nullptr;
    }


};

#endif // CITIZEN_H

