#include "Landmark.h"
#include "LandmarkFactory.h"
#include <iostream>
#include <ostream>

LandmarkFactory::LandmarkFactory(TaxAuthority *taxAuthority) : BuildingFactory(){
    tax = taxAuthority;
}

Building *LandmarkFactory::createBuilding(string type, Citizen* owner) {
    cout<< "Constructing Factory...\n";
    Landmark* landmark;
    Resources* resources = nullptr;
    Citizen* citizen = owner;
    int cost;
    if(type != "") {
        if(type == "Statue") {
            cost = 10000;
            if(owner) {
                int funds = owner->getFunds();
                if(funds > cost) {
                    landmark = new Landmark(cost, "Business district", resources, 1000, citizen, tax, "Statue");
                } else {
                    cout<< owner->getName() <<" has insufficient funds.\n";
                }
            }
        } else if(type == "Park") {
            cost = 12000;
            if(owner) {
                int funds = owner->getFunds();
                if(funds > cost) {
                    landmark = new Landmark(cost, "Residential district", resources, 1000, citizen, tax, "Park");
                } else {
                    cout<< owner->getName() <<" has insufficient funds.\n";
                }
            }
        } else if(type == "Tower") {
            cost = 300000;
            if(owner) {
                int funds = owner->getFunds();
                if(funds > cost) {
                    landmark = new Landmark(cost, "Industrial district", resources, 1000, citizen, tax, "Tower");
                } else {
                    cout<< owner->getName() <<" has insufficient funds.\n";
                }
            }
        } else {
            cout <<"Invalid type.\n";
        }
    }
    return landmark;
}
