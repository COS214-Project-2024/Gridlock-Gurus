#ifndef DAMAGED_H
#define DAMAGED_H

#include "TransportState.h"

/**
 * @brief Represents a damaged state of a vehicle.
 */
class Damaged : public TransportState {
public:
    Damaged();  ///< Constructor
    ~Damaged();  ///< Destructor
};

#endif // DAMAGED_H
