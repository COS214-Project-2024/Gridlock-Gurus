#ifndef UNRESTSTATE_H
#define UNRESTSTATE_H

#include "PoliceState.h"

/**
 * @brief Represents a state of unrest in the city.
 */
class UnrestState : public PoliceState {
public:
    UnrestState();  ///< Constructor
    ~UnrestState();  ///< Destructor
};

#endif // UNRESTSTATE_H
