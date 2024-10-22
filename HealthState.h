#ifndef HEALTHSTATE_H
#define HEALTHSTATE_H

/**
 * @brief Abstract class representing the state of health services.
 */
class HealthState {
public:
    HealthState();  ///< Constructor
    virtual ~HealthState();  ///< Destructor
};

#endif // HEALTHSTATE_H
