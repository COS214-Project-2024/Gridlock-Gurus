#ifndef POLICESTATE_H
#define POLICESTATE_H

/**
 * @brief Abstract class representing the state of police services.
 *
 * AbstractState in the State pattern. It defines the interface for concrete states that represent various conditions of police operations. Each state will implement specific behaviors for checking the operational status of police services.
 */
class PoliceState {
public:
    /**
     * @brief Constructs a new PoliceState object.
     */
    PoliceState();

    /**
     * @brief Destroys the PoliceState object.
     */
    virtual ~PoliceState();

    /**
     * @brief Checks the operational status of the police service.
     * This method will be overridden by concrete state classes to define specific behavior based on the current state.
     */
    virtual void checkOperation() = 0;
};

#endif // POLICESTATE_H
