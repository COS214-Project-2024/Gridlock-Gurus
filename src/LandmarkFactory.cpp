#include "LandmarkFactory.h"
#include "Landmark.h"
#include <string>


Building *LandmarkFactory::createBuilding(const std::string& name,BuildingType type, Citizen& owner) {
    Resources* resources = new Resources(0,0,false);
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

    Landmark* l = new Landmark(name,cost,location,resources,size,owner,type);
    taxAuthority->registerBuilding(*l);

    return l;
}
