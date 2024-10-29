#include "Commercial.h"
#include "CommercialFactory.h"
#include <iostream>
#include <ostream>

CommercialFactory::CommercialFactory(TaxAuthority *taxAuthority) : BuildingFactory(){
    tax = taxAuthority;
}

Building *CommercialFactory::createBuilding(string type, Citizen* owner) {
    cout<< "Constructing Shops...\n";
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
                    commercial = new Commercial(cost, "Business district", resources, 1000, citizen, tax, productionRate, maxEmployees);
                } else {
                    cout<< owner->getName() <<" has insufficient funds.\n";
                }
            }
        } else if(type == "Groceries") {
            maxEmployees = 60;
            cost = 120000;
            productionRate = 12;
            if(owner) {
                int funds = owner->getFunds();
                if(funds > cost) {
                    commercial = new Commercial(cost, "Business district", resources, 1000, citizen, tax, productionRate, maxEmployees);
                } else {
                    cout<< owner->getName() <<" has insufficient funds.\n";
                }
            }
        } else {
            cout <<"Invalid type.\n";
        }
    }
    return commercial;
}
