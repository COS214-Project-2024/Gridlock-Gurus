#ifndef LOWFUNDINGSTATE_H
#define LOWFUNDINGSTATE_H

#include "HealthState.h"

/**
 * @brief Represents a low-funding state for health services.
 */
class LowFundingState : public HealthState {
public:
    LowFundingState();  ///< Constructor
    ~LowFundingState();  ///< Destructor
};

#endif // LOWFUNDINGSTATE_H
