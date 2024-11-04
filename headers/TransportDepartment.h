#ifndef TRANSPORTDEPARTMENT_H
#define TRANSPORTDEPARTMENT_H

#include <vector>
#include <string>
#include "Vehicle.h"
#include "VehicleType.h"

class Vehicle;
class VehicleTaxi;

/**
 * @class TransportDepartment
 * @brief Manages a fleet of vehicles within the transport department.
 */
class TransportDepartment {
private:
    std::vector<Vehicle*> vehicles;     ///< Collection of vehicles managed by the department.

public:
    /**
     * @brief Adds a vehicle to the department.
     * 
     * @param vehicle Reference to the vehicle to be added.
     */
    void addVehicle(Vehicle& vehicle);

    /**
     * @brief Manages the operations of all vehicles.
     */
    void manage();

    /**
     * @brief Destroys the TransportDepartment object.
     */
    ~TransportDepartment();

    /**
     * @brief Gets an available vehicle of the specified type.
     * @param type The type of vehicle required.
     * @return Reference to an available vehicle.
     */
    Vehicle& getAvailableVehicle(VehicleType type);

    /**
     * @brief Repairs a specified vehicle.
     * @param vehicle Reference to the vehicle to be repaired.
     */
    void repairVehicle(Vehicle& vehicle);

    /**
     * @brief Gets the size of the vehicle fleet.
     * @return The number of vehicles.
     */
    int getSize() {
        return vehicles.size();
    }

    /**
     * @brief Gets the number of broken vehicles in the fleet.
     * @return The number of broken vehicles.
     */
    int getBroken();

    /**
     * @brief Adds a new transport vehicle of the specified type.
     * @param type The type of vehicle to add.
     */
    void addTransport(VehicleType type);

    /**
     * @brief Gets the total size of the fleet.
     * @return The total number of vehicles.
     */
    int getFleetSize();

    /**
     * @brief Generates a report of the department.
     * @param temp String to store the report.
     */
    void getReport(std::string& temp);

    /**
     * @brief Gets the fleet of vehicles managed by the department.
     * @return A vector containing pointers to the vehicles.
     */
    std::vector<Vehicle*>& getFleet();
};

#endif // TRANSPORTDEPARTMENT_H