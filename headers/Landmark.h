#ifndef LANDMARK_H
#define LANDMARK_H

#include "Building.h"
#include "BuildingType.h"
#include <memory>
#include <string>


class Landmark : public Building {
    
public:
    /**
     * @brief Constructs a new Landmark building.
     * @param cost The construction cost of the landmark.
     * @param location The location of the landmark.
     * @param resources Pointer to the resources the landmark uses.
     * @param size The size of the landmark.
     * @param owner Pointer to the owner of the landmark.
     * @param taxAuthority Pointer to the tax authority associated with the landmark.
     */
    Landmark(const std::string& name, int cost, std::string& location, Resources* resources, int size, Citizen& owner, BuildingType type) : Building(name,cost,location,resources,size,owner,type) {} 

    ~Landmark() override = default;

};

#endif // LANDMARK_H
