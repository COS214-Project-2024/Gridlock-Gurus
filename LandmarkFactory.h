#ifndef LANDMARKFACTORY_H
#define LANDMARKFACTORY_H

#include "BuildingFactory.h"

/**
 * @brief Factory for creating landmarks.
 */
class LandmarkFactory : public BuildingFactory {
public:
    LandmarkFactory();  ///< Constructor
    ~LandmarkFactory();  ///< Destructor
};

#endif // LANDMARKFACTORY_H
