#include "ResidentialFactory.h"
#include "City.h"
#include "Residential.h"
#include <iostream>
#include <ostream>

Building *ResidentialFactory::createBuilding(BuildingType type,Citizen &owner) {
  Resources *resources = new Resources(400, 400, true);
  int maxInhabitants;
  int cost;

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

    Residential* r = new Residential(cost, location, resources, 5000, owner, type, maxInhabitants);
    taxAuthority->registerBuilding(*r);

  return r;
}
