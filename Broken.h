#ifndef BROKEN_H
#define BROKEN_H

#include "TransportState.h"

/**
 * @brief Represents a broken state of a vehicle.
 */
class Broken : public TransportState {
public:
    Broken();  ///< Constructor
    ~Broken();  ///< Destructor
};

#endif // BROKEN_H
