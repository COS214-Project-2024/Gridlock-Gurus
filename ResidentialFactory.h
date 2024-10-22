#ifndef RESIDENTIALFACTORY_H
#define RESIDENTIALFACTORY_H

#include "BuildingFactory.h"

/**
 * @brief Factory for creating residential buildings.
 */
class ResidentialFactory : public BuildingFactory {
public:
    ResidentialFactory();  ///< Constructor
    ~ResidentialFactory();  ///< Destructor
};

#endif // RESIDENTIALFACTORY_H

