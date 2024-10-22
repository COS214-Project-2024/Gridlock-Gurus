#ifndef SERVICE_H
#define SERVICE_H

#include "Building.h"

/**
 * @brief Represents a service building (e.g., hospital, police station).
 */
class Service : public Building {
public:
    Service();  ///< Constructor
    ~Service();  ///< Destructor
};

#endif // SERVICE_H

