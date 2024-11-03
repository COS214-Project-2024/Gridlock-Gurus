#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H

#include "Building.h"
#include <vector>
#include <string>
#include <memory>

class Residential : public Building {
private:
    int maxCapacity;
    std::vector<Citizen*> tenants;

public:
    Residential(int cost, std::string& location, Resources* resources, int size, Citizen& owner,BuildingType name, int capacity);
    ~Residential() override = default;
    std::string getDetails() const override;
    //void householdTax();
    void addTenant(Citizen& tenant);
    void removeTenant(Citizen& tenant);

    bool isFull() const;

    int getNumberOfTenants() const {
        return tenants.size();
    }
};

#endif // RESIDENTIAL_H
