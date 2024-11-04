#ifndef SERVICE_H
#define SERVICE_H

#include "Building.h"
#include "BuildingType.h"
#include <vector>
#include <algorithm>
#include <string>
#include <memory>

/**
 * @class Service
 * @brief Represents a service building such as a hospital, school, or police station.
 */
class Service : public Building {
protected:
    std::vector<int> employees;     ///< List of employees in the service building.
    double benefits;                ///< Benefits provided by the service.
    int maxEmployees;               ///< Maximum number of employees the building can accommodate.
    int id;                         ///< Unique identifier for the service building.

public:
    /**
     * @brief Constructs a new Service building.
     * 
     * @param name The name of the building.
     * @param cost The construction cost.
     * @param location The location of the building.
     * @param resources Pointer to the resources used by the building.
     * @param size The size of the building.
     * @param owner Reference to the owner of the building.
     * @param type The type of building.
     * @param id Unique identifier for the building.
     */
    Service(const std::string& name, int cost, std::string& location, Resources* resources, int size, Citizen& owner, BuildingType type, int id);

    /**
     * @brief Destroys the Service building.
     */
    virtual ~Service() = default;

    /**
     * @brief Employs a citizen in the service building.
     * @param employee Reference to the citizen to employ.
     */
    void employ(Citizen& employee);

    /**
     * @brief Fires a citizen from the service building.
     * @param employee Reference to the citizen to fire.
     */
    void fire(Citizen& employee);

    /**
     * @brief Retires a citizen from the service building.
     * @param employee Reference to the citizen to retire.
     */
    void retire(Citizen& employee);

    /**
     * @brief Gets the number of employees in the building.
     * @return The number of employees.
     */
    int getNumberOfEmployees() const {
        return employees.size();
    }

    /**
     * @brief Gets the maximum number of employees the building can accommodate.
     * @return The maximum number of employees.
     */
    int getMaxEmployees() const {
        return maxEmployees;
    }

    /**
     * @brief Gets the unique identifier of the service building.
     * @return The unique identifier.
     */
    int getId() const {
        return id;
    }

    /**
     * @brief Checks if the building has reached its maximum capacity.
     * @return true if the building is full, false otherwise.
     */
    bool isFull() const {
        return maxEmployees <= employees.size();
    }
};

#endif // SERVICE_H
