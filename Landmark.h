#ifndef LANDMARK_H
#define LANDMARK_H

#include "Building.h"

/**
 * @brief Represents a landmark in the city.
 */
class Landmark : public Building {
public:
    Landmark();  ///< Constructor
    ~Landmark();  ///< Destructor
};

#endif // LANDMARK_H
