#ifndef HIGHFUNDINGSTATE_H
#define HIGHFUNDINGSTATE_H

#include "HealthState.h"

/**
 * @brief Represents a high-funding state for health services.
 */
class HighFundingState : public HealthState {
public:
    HighFundingState();  ///< Constructor
    ~HighFundingState();  ///< Destructor
};

#endif // HIGHFUNDINGSTATE_H
