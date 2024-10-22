#ifndef TRANSPORTDEPARTMENT_H
#define TRANSPORTDEPARTMENT_H

#include <list>
#include <string>
#include "Vehicle.h"

/**
 * @brief The TransportDepartment class manages a fleet of different types of vehicles.
 *
 * This class handles operations related to the transport department, including
 * maintaining lists of various vehicle types and providing functionality to call
 * for transport and add vehicles to the fleet.
 */
class TransportDepartment {
private:
    std::list<Vehicle*> trains; ///< List of train vehicles.
    std::list<Vehicle*> trucks; ///< List of truck vehicles.
    std::list<Vehicle*> taxis;  ///< List of taxi vehicles.

public:
    /**
     * @brief Construct a new TransportDepartment object.
     *
     * Initializes the TransportDepartment and prepares the vehicle lists.
     */
    TransportDepartment();

    /**
     * @brief Destroy the TransportDepartment object.
     *
     * Cleans up resources and deletes the vehicle lists.
     */
    ~TransportDepartment();

    /**
     * @brief Calls for transport from the fleet.
     *
     * This function handles the logic to call for available transport vehicles
     * based on user requests or other criteria.
     */
    void callTransport();

    /**
     * @brief Adds a vehicle to the fleet.
     *
     * @param type The type of vehicle to add to the fleet (e.g., "train", "truck", "taxi").
     * This function will create a new vehicle of the specified type and add it to the
     * appropriate list within the TransportDepartment.
     */
    void addToFleet(std::string type);
};

#endif // TRANSPORTDEPARTMENT_H
