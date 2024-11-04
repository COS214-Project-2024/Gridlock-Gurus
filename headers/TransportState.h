#ifndef TRANSPORTSTATE_H
#define TRANSPORTSTATE_H

/**
 * @class TransportState
 * @brief Abstract base class representing the state of a transport vehicle.
 */
class TransportState {
public:
    /**
     * @brief Constructs a new TransportState object.
     */
    TransportState() = default;

    /**
     * @brief Destroys the TransportState object.
     */
    virtual ~TransportState() = default;

    /**
     * @brief Runs the transport vehicle in its current state.
     * @return true if the vehicle runs successfully, false otherwise.
     */
    virtual bool run() = 0;
};

#endif // TRANSPORTSTATE_H