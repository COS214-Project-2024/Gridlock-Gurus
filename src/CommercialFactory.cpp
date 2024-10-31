#include "Commercial.h"
#include "CommercialFactory.h"
#include <iostream>
#include <ostream>

// Made citizen a reference instead of pointer to prevent it being nullptr
Building *CommercialFactory::createBuilding(std::string& type, Citizen& owner) {
    //Commercial* commercial;
    Resources* resources = nullptr;
    int maxEmployees;
    int productionRate;
    int cost;
    std::string temp = "Business district";

    /*if(type != "") {
        if(type == "Bank") {
            maxEmployees = 30;
            cost = 100000;
            productionRate = 6;
            if(owner) {
                int funds = owner->getFunds();
                if(funds > cost) {
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
    }*/

    // I changed it because before it returs a nullptr? checks should be done before calling, the function of factory is just to produce
    if(type == "Bank") {
        maxEmployees = 30;
        cost = 100000;
        productionRate = 6;
        
    } else {
        maxEmployees = 60;
        cost = 120000;
        productionRate = 12;
    }

    return new Commercial(cost, temp, resources, 1000, owner, tax, productionRate, maxEmployees);
}
