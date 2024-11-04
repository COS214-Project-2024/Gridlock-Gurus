#include "LandmarkFactory.h"
#include "Landmark.h"
#include <string>

/**
 * @brief Creates a building based on the specified type and registers it with the tax authority.
 *
 * @param name The name of the building to create.
 * @param type The type of building to create (e.g., Statue, Park).
 * @param owner Reference to the Citizen who owns the building.
 *
 * @return A pointer to the newly created building.
 */
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
