#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "City.h"
#include "CityBuilder.h"

/**
 * @brief Orchestrates the construction of a city.
 */
class Director {
public:
    /**
     * @brief Constructs a Director object.
     */
    Director();

    /**
     * @brief Default destructor.
     */
    virtual ~Director();

    /**
     * @brief Constructs a new city.
     * @return Pointer to the constructed city.
     */
    City* construct();

    /**
     * @brief Sets a building as part of the city construction.
     * @param building Building to be added.
     */
    void setBuilding(Building& building) {}
};

#endif // DIRECTOR_H
