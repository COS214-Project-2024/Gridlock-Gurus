#ifndef FACTORYFACTORY_H
#define FACTORYFACTORY_H

#include "BuildingFactory.h"

/**
 * @brief Factory for creating industrial buildings (factories).
 */
class FactoryFactory : public BuildingFactory {
public:
    FactoryFactory();  ///< Constructor
    ~FactoryFactory();  ///< Destructor
};

#endif // FACTORYFACTORY_H

