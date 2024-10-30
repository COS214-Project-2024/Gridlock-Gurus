#include "Commercial.h"
#include "CommercialFactory.h"
#include <iostream>
#include <ostream>

CommercialFactory::CommercialFactory(std::shared_ptr<TaxAuthority> taxAuthority) : BuildingFactory(){
    tax = taxAuthority;
}

Building *CommercialFactory::createBuilding(std::string type, Citizen* owner) {
    std::cout<< "Constructing Shops...\n";
    Commercial* commercial;
    Resources* resources = nullptr;
    int maxEmployees;
    int productionRate;
    Citizen* citizen = owner;
    int cost;
    if(type != "") {
        if(type == "Bank") {
            maxEmployees = 30;
            cost = 100000;
            productionRate = 6;
            if(owner) {
                int funds = owner->getFunds();
                if(funds > cost) {
                    std::string temp = "Business district";
                    commercial = new Commercial(cost, temp , resources, 1000, citizen, tax, productionRate, maxEmployees);
                } else {
                    std::cout<< owner->getName() <<" has insufficient funds.\n";
                }
            }
        } else if(type == "Groceries") {
            maxEmployees = 60;
            cost = 120000;
            productionRate = 12;
            if(owner) {
                int funds = owner->getFunds();
                if(funds > cost) {
                    std::string temp = "Business district";
                    commercial = new Commercial(cost, temp, resources, 1000, citizen, tax, productionRate, maxEmployees);
                } else {
                    std::cout<< owner->getName() <<" has insufficient funds.\n";
                }
            }
        } else {
            std::cout <<"Invalid type.\n";
        }
    }
    return commercial;
}
