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

class DepartmentOfWaterPowerAndSanitation {
private:
    std::unique_ptr<Water> water;
    std::unique_ptr<Power> power;
    std::unique_ptr<Sanitation> sanitation;

public:

    DepartmentOfWaterPowerAndSanitation() {
        water = std::make_unique<Water>();
        power = std::make_unique<Power>();
        sanitation = std::make_unique<Sanitation>();
    }

     ~DepartmentOfWaterPowerAndSanitation() = default;

    int repair();

    std::string checkNetwork() const;

    void reviewWaterUsage(int totalWater);

    void reviewPowerUsage(int totalPower);
};

#endif // DEPARTMENTOFWATERPOWERANDSANITATION_H
