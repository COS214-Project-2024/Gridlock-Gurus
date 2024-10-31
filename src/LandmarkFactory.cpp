#include "LandmarkFactory.h"
#include "Landmark.h"
#include <string>


Building *LandmarkFactory::createBuilding(BuildingType type, Citizen& owner) {
    Resources* resources = new Resource(0,0,false);
    int cost;
    std::string location = "City center";
    int size = 2000;

    if(type == BuildingType::Statue) {
        cost = 1000;
    } else if(type == BuildingType::Park) {
        cost = 1200;
    } else {
        cost = 3000;
    }
/*    if(type != "") {
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
    }*/
    return new Landmark(cost,location,*resources,size,owner,taxAuthority,type);
}
