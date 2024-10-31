#ifndef LANDMARK_H
#define LANDMARK_H

#include "Building.h"
#include "BuildingType.h"
#include <memory>
#include <string>


/**
 * @brief Represents a landmark in the city.
 *
 * ConcreteProduct participant in the Factory Method pattern. It extends the Building class and represents a notable landmark structure within the city.
 */
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
    Landmark(int cost, std::string& location, Resources* resources, int size, Citizen& owner, BuildingType name) : Building(cost,location,resources,size,owner,name) {} 

    /**
     * @brief Destroys the Landmark building.
     */
    ~Landmark() override = default;  ///< Destructor

    /**
     * @brief Gets details about the landmark building.
     * @return A string containing details about the landmark.
     */
    std::string getDetails() const override;
};

#endif // LANDMARK_H
