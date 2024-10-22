#ifndef FUNCTIONAL_H
#define FUNCTIONAL_H

#include "TransportState.h"

/**
 * @brief Represents a functional state of a vehicle.
 */
class Functional : public TransportState {
public:
    Functional();  ///< Constructor
    ~Functional();  ///< Destructor
};

#endif // FUNCTIONAL_H
