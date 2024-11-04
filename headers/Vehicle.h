#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include "TransportState.h"
#include "TransportDepartment.h"
#include "BrokenState.h"
#include "FunctionalState.h"
#include "VehicleType.h"
#include <memory>
class TransportDepartment;
class TransportState;

enum VehicleState {
    Functional,
    Broken
};

class Vehicle {
protected:
    VehicleType type;                           ///< Type of the vehicle.
    int capacity;                               ///< Maximum passenger capacity.
    int currentPassengers;                      ///< Current number of passengers.
    std::unique_ptr<TransportState> state;      ///< Current operational state.
    VehicleState vehicle_state;                 ///< State of the vehicle.
    int usageCount;                             ///< Count of how many times the vehicle has been used.
    TransportDepartment& department;            ///< Reference to the transport department managing the vehicle.

public:
    /**
     * @brief Constructs a new Vehicle object.
     * @param type The type of the vehicle.
     * @param capacity The maximum passenger capacity of the vehicle.
     * @param transportDept Reference to the transport department managing the vehicle.
     */
    Vehicle(VehicleType type, int capacity, TransportDepartment& transportDept);

    /**
     * @brief Destroys the Vehicle object.
     */
    ~Vehicle() = default;

    /**
     * @brief Collects passengers onto the vehicle.
     * @param passengers Number of passengers to collect.
     */
    void collect(int passengers);

    /**
     * @brief Runs the vehicle if it is operational.
     * @return true if the vehicle runs successfully, false otherwise.
     */
    bool run();

    /**
     * @brief Sets the current state of the vehicle.
     */
    void setState();

    /**
     * @brief Clones the current vehicle.
     * @return A pointer to the cloned vehicle.
     */
    Vehicle* clone();

    /**
     * @brief Offloads passengers from the vehicle.
     */
    void offload();

    /**
     * @brief Repairs the vehicle if it is broken.
     */
    void repair();

    /**
     * @brief Requests a repair for the vehicle.
     */
    void requestRepair();

    /**
     * @brief Gets the type of the vehicle.
     * @return The type of the vehicle.
     */
    VehicleType getType() const {
        return type;
    }

    /**
     * @brief Gets the current state of the vehicle.
     * @return The state of the vehicle.
     */
    VehicleState getState() const {
        return vehicle_state;
    }

    /**
     * @brief Gets the usage count of the vehicle.
     * @return The number of times the vehicle has been used.
     */
    int getUsage() {
        return usageCount;
    }

    /**
     * @brief Gets the current number of passengers on the vehicle.
     * @return The current passenger count.
     */
    int getCurrentPassengers() {
        return currentPassengers;
    }

    /**
     * @brief Gets the capacity of the vehicle.
     * @return The maximum capacity of the vehicle.
     */
    int getCapacity() {
        return capacity;
    }
};

#endif // VEHICLE_H