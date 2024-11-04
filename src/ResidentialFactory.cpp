#include "ResidentialFactory.h"
#include "City.h"
#include "Residential.h"

/**
 * @brief Creates a residential building of a specified type.
 *
 * This function allocates resources and sets location, cost, and maximum
 * capacity based on the building type, registering the building with the tax authority.
 *
 * @param name The name of the building.
 * @param type The type of the residential building (e.g., Flat, House, Estate).
 * @param owner The citizen who owns the building.
 * @return A pointer to the newly created building.
 */
Building *ResidentialFactory::createBuilding(const std::string& name,BuildingType type,Citizen &owner) {
  Resources *resources = new Resources(400, 400, true);
  int maxInhabitants;
  int cost;
    std::string location = "";
  if (type == BuildingType::Flat) {
    cost = 500;
    maxInhabitants = 2;
    location = "City center";
  } else if (type == BuildingType::House) {
    cost = 2000;
    maxInhabitants = 5;
    location = "Suburbs";
  } else if (type == BuildingType::Estate) {
    cost = 3000;
    maxInhabitants = 10;
    location = "Country";

  } else {
    cost = 3000;
    maxInhabitants = 10;
    location = "Country";
  }

    Residential* r = new Residential(name,cost, location, resources, 500, owner, type, maxInhabitants);
    taxAuthority->registerBuilding(*r);

  return r;
}
