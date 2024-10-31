#ifndef DEPARTMENTOFWATERPOWERANDSANITATION_H
#define DEPARTMENTOFWATERPOWERANDSANITATION_H

#include <vector>
#include "Utilities.h"
#include "Resources.h"

/**
 * @brief Department managing water, power, and sanitation utilities.
 */
class DepartmentOfWaterPowerAndSanitation {
private:
    std::vector<Utilities*> utilities;
    Resources* resources;

public:

    /**
     * @brief Construct a new DepartmentOfWaterPowerAndSanitation object.
     *
     * Initializes the DepartmentOfWaterPowerAndSanitation and prepares the resources and utilities.
     */
    DepartmentOfWaterPowerAndSanitation(Resources* resources);

    /**
     * @brief Destroy the DepartmentOfWaterPowerAndSanitation object.
     *
     * Cleans up resources and deletes the utilities.
     */
    virtual ~DepartmentOfWaterPowerAndSanitation();
    
    /**
     * @brief Update the number of citizens in the network.
     * @param count The number of citizens.
     */
    void updateCitizenCount(int count);

    /**
     * @brief Repair the utilities managed by the department.
     */
    void repair();

    /**
     * @brief Check the utility network capacity.
     */
    void checkNetwork() const;

    /**
     * @brief Add a new utility to the department.
     * @param utility Pointer to the utility to add.
     */
    void addUtilities(Utilities* utility);
};

#endif // DEPARTMENTOFWATERPOWERANDSANITATION_H
