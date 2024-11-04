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

    void reviewWaterUsage(int totalWater);
    void reviewPowerUsage(int totalPower);

    /**
     * @brief Upgrades the utilities in the department.
     */
    void upgrade();
};

#endif // DEPARTMENTOFWATERPOWERANDSANITATION_H
