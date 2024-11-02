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
 * @brief Department managing water, power, and sanitation utilities.
 */
class DepartmentOfWaterPowerAndSanitation {
private:
    std::unique_ptr<Water> water;
    std::unique_ptr<Power> power;
    std::unique_ptr<Sanitation> sanitation;

public:

    /**
     * @brief Construct a new DepartmentOfWaterPowerAndSanitation object.
     *
     * Initializes the DepartmentOfWaterPowerAndSanitation and prepares the resources and utilities.
     */
    DepartmentOfWaterPowerAndSanitation() {
        water = std::make_unique<Water>();
        power = std::make_unique<Power>();
        sanitation = std::make_unique<Sanitation>();
    }

    /**
     * @brief Destroy the DepartmentOfWaterPowerAndSanitation object.
     *
     * Cleans up resources and deletes the utilities.
     */
     ~DepartmentOfWaterPowerAndSanitation() = default;
    
    /**
     * @brief Repair the utilities managed by the department.
     */
    int repair();

    /**
     * @brief Check the utility network capacity.
     */
    std::string checkNetwork() const;

    void reviewWaterUsage(int totalWater);

    void reviewPowerUsage(int totalPower);
};

#endif // DEPARTMENTOFWATERPOWERANDSANITATION_H
