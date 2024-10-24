#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "City.h"
#include "CityBuilder.h"

/**
 * @brief Directs the building process using the CityBuilder.
 *
 * Director participant in the Builder pattern. It uses a CityBuilder object to construct a complete city by calling the appropriate building methods in the right sequence.
 */
class Director {
public:
    /**
     * @brief Constructs a new Director object.
     */
    Director();
    
    /**
     * @brief Destroys the Director object.
     */
    virtual ~Director();

    /**
     * @brief Constructs a city using the CityBuilder.
     * @return A pointer to the constructed City object.
     *
     * This function orchestrates the steps defined in CityBuilder to create the final city.
     */
    City* construct();
};

#endif // DIRECTOR_H
