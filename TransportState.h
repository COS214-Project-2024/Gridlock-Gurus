#ifndef TRANSPORTSTATE_H
#define TRANSPORTSTATE_H

/**
 * @class TransportState
 * @brief Abstract class representing the state of a vehicle in the transport system.
 * 
 * The `TransportState` class is the base class for different states that a vehicle 
 * can exist in, such as functional, damaged, or broken. It provides an interface for 
 * the common operations that can be performed on vehicles in any state.
 */
class TransportState {
public:
    /**
     * @brief Constructor for the TransportState class.
     *
     * Initializes the state of the vehicle.
     */
    TransportState();

    /**
     * @brief Virtual destructor for the TransportState class.
     *
     * Ensures that derived classes can properly clean up their resources.
     */
    virtual ~TransportState();

    /**
     * @brief Returns the current state of the vehicle.
     *
     * This is a pure virtual function that must be implemented by derived classes.
     * 
     * @return A `TransportState` object representing the current state of the vehicle.
     */
    virtual TransportState returnState() = 0;

    /**
     * @brief Simulates breaking the vehicle.
     *
     * This is a pure virtual function that must be implemented by derived classes.
     */
    virtual void breakTransport() = 0;

    /**
     * @brief Repairs the vehicle, transitioning it to a functional state.
     *
     * This is a pure virtual function that must be implemented by derived classes.
     */
    virtual void repair() = 0;

};

#endif // TRANSPORTSTATE_H
