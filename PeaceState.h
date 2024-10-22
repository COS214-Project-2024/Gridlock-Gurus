#ifndef PEACESTATE_H
#define PEACESTATE_H

#include "PoliceState.h"

/**
 * @brief Represents a state of peace in the city.
 */
class PeaceState : public PoliceState {
public:
    PeaceState();  ///< Constructor
    ~PeaceState();  ///< Destructor
};

#endif // PEACESTATE_H
