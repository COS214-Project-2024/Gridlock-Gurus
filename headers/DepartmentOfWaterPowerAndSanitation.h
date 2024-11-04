#ifndef DEPARTMENTOFWATERPOWERANDSANITATION_H
#define DEPARTMENTOFWATERPOWERANDSANITATION_H

#include <vector>
#include "Utilities.h"
#include "Water.h"
#include "Sanitation.h"
#include "Power.h"
#include "Resources.h"
#include <memory>
#include <string>

/**
 * @brief Manages water, power, and sanitation services in the city.
 */
class DepartmentOfWaterPowerAndSanitation {
private:
    std::unique_ptr<Water> water;               ///< Water management system.
    std::unique_ptr<Power> power;               ///< Power management system.
    std::unique_ptr<Sanitation> sanitation;     ///< Sanitation management system.

public:
    /**
     * @brief Constructs the Department of Water, Power, and Sanitation.
     */
    DepartmentOfWaterPowerAndSanitation();

    /**
     * @brief Default destructor.
     */
    ~DepartmentOfWaterPowerAndSanitation() = default;

    /**
     * @brief Repairs utilities in the department.
     * @return The cost of repairs.
     */
    int repair();

    /**
     * @brief Checks the status of the utility network.
     * @return A string describing the network status.
     */
    std::string checkNetwork() const;

    /**
    * @brief Reviews the total water usage within the city.
    * @param totalWater The total amount of water used, measured in appropriate units (e.g., liters).
    * This function evaluates the city's water consumption and can trigger alerts or actions
    * based on the water usage levels.
    */
     void reviewWaterUsage(int totalWater);

    /**
     * @brief Reviews the total power usage within the city.
     * @param totalPower The total amount of power used, measured in appropriate units (e.g., kilowatt-hours).
     * This function assesses the city's power consumption and can initiate alerts or actions
     * depending on the power usage metrics.
     */
    void reviewPowerUsage(int totalPower);

    /**
     * @brief Upgrades the utilities in the department.
     */
    void upgrade();
};

#endif // DEPARTMENTOFWATERPOWERANDSANITATION_H
