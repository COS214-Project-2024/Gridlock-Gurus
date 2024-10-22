#ifndef SERVICEFACTORY_H
#define SERVICEFACTORY_H

#include "BuildingFactory.h"

/**
 * @brief Factory for creating service buildings.
 */
class ServiceFactory : public BuildingFactory {
public:
    ServiceFactory();  ///< Constructor
    ~ServiceFactory();  ///< Destructor
};

#endif // SERVICEFACTORY_H
