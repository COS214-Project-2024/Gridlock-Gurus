#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include "TransportState.h"

/**
 * @class Vehicle
 * @brief Abstract base class representing a vehicle in the transportation system.
 * 
 * The `Vehicle` class defines the common properties and behaviors of various types of vehicles
 * (e.g., train, truck, taxi) used in the transportation system. Each specific vehicle type must 
 * implement the abstract functions defined in this class. The class also tracks the state of 
 * the vehicle, such as whether it is functional, damaged, or broken.
 */
class Vehicle {
private:
    std::string type;  ///< Type of the vehicle (e.g., "train", "truck", "taxi").
    int numberOfPassengers;  ///< Number of passengers currently in the vehicle.
    int capacity;  ///< Maximum capacity of the vehicle.
    TransportState* transportState;  ///< The current state of the vehicle (functional, broken, etc.).

public:
    /**
     * @brief Default constructor for the Vehicle class.
     *
     * Initializes a vehicle object with default values.
     */
    Vehicle();

    /**
     * @brief Virtual destructor for the Vehicle class.
     *
     * Ensures proper cleanup of resources used by derived vehicle objects.
     */
    virtual ~Vehicle();

    /**
     * @brief Collects a specified amount of goods or passengers.
     *
     * This is a pure virtual function that must be implemented by derived vehicle types.
     * 
     * @param amount The amount to collect (e.g., number of passengers, cargo).
     */
    virtual void collect(int amount) = 0;

    /**
     * @brief Offloads a specified amount of goods or passengers.
     *
     * This is a pure virtual function that must be implemented by derived vehicle types.
     * 
     * @param amount The amount to offload (e.g., number of passengers, cargo).
     */
    virtual void offload(int amount) = 0;

    /**
     * @brief Runs the vehicle.
     *
     * This method simulates the operation of the vehicle (e.g., moving to a destination).
     */
    virtual void run() = 0;

    /**
     * @brief Simulates a vehicle breakdown.
     *
     * This method transitions the vehicle into a broken or damaged state.
     */
    virtual void breakDown() = 0;

    /**
     * @brief Delays the vehicle operation.
     *
     * This method simulates a delay in the vehicle's operation.
     */
    virtual void delay() = 0;

    /**
     * @brief Clones the vehicle.
     *
     * Creates a copy of the vehicle object.
     */
    virtual void clone() = 0;
};

#endif // VEHICLE_H

