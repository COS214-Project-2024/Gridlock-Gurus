#include "ResidentialFactory.h"
#include <iostream>
#include <ostream>
#include "City.h"
#include "Residential.h"

ResidentialFactory::ResidentialFactory(TaxAuthority *taxAuthority) : BuildingFactory(){
    tax = taxAuthority;
}

Building *ResidentialFactory::createBuilding(string type, Citizen* owner) {
    cout<< "Constructing Residential Building...\n";
    Residential* residence;
    Resources* resources = nullptr;
    int maxInhabitants;
    Citizen* citizen = owner;
    int cost;
    if(type != "") {
        if(type == "flat") {
            maxInhabitants = 2;
            cost = 1000;
            if(owner) {
                int funds = owner->getFunds();
                if(funds > cost) {
                    residence = new Residential(cost, "Business district", resources, 1000, citizen, tax, maxInhabitants);
                } else {
                    cout<< owner->getName() <<" has insufficient funds.\n";
                }
            }
        } else if(type == "house") {
            maxInhabitants = 6;
            cost = 120000;
            if(owner) {
                int funds = owner->getFunds();
                if(funds > cost) {
                    residence = new Residential(cost, "Residential district", resources, 100000, citizen, tax, maxInhabitants);
                } else {
                    cout<< owner->getName() <<" has insufficient funds.\n";
                }
            }
        } else if(type == "highRise") {
            maxInhabitants = 30;
            cost = 30000000;
            if(owner) {
                int funds = owner->getFunds();
                if(funds > cost) {
                    residence = new Residential(cost, "Industrial district", resources, 1000000000, citizen, tax, maxInhabitants);
                } else {
                    cout<< owner->getName() <<" has insufficient funds.\n";
                }
            }
        } else if(type == "estate") {
            maxInhabitants = 100;
            cost = 100000000;
            if(owner) {
                int funds = owner->getFunds();
                if(funds > cost) {
                    residence = new Residential(cost, "Residential district", resources, 100000000000, citizen, tax, maxInhabitants);
                } else {
                    cout<< owner->getName() <<" has insufficient funds.\n";
                }
            }
        } else if(type == "hotel") {
            maxInhabitants = 50;
            cost = 10000000;
            if(owner) {
                int funds = owner->getFunds();
                if(funds > cost) {
                    residence = new Residential(cost, "CBD", resources, 500000000, citizen, tax, maxInhabitants);
                } else {
                    cout<< owner->getName() <<" has insufficient funds.\n";
                }
            }
        }
    }
    return residence;
}
