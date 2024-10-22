#ifndef COMMERCIALFACTORY_H
#define COMMERCIALFACTORY_H

#include "BuildingFactory.h"

/**
 * @brief Factory for creating commercial buildings.
 */
class CommercialFactory : public BuildingFactory {
public:
    CommercialFactory();  ///< Constructor
    ~CommercialFactory();  ///< Destructor
};

#endif // COMMERCIALFACTORY_H
