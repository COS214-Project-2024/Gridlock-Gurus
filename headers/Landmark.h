#ifndef LANDMARK_H
#define LANDMARK_H

#include "Building.h"
#include "BuildingType.h"
#include <memory>
#include <string>


class Landmark : public Building {
    
public:
    Landmark(int cost, std::string& location, Resources* resources, int size, Citizen& owner, BuildingType name) : Building(cost,location,resources,size,owner,name) {} 

    ~Landmark() override = default;

    std::string getDetails() const override;
};

#endif // LANDMARK_H
