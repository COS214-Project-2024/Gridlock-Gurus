#ifndef POWER_H
#define POWER_H

#include "Utilities.h"
#include <string>
#include "UtilityType.h"
class Power : public Utilities {
public:
    Power() : Utilities(UtilityType::Power, 1000, 500) {}

    ~Power()override = default;
    void checkCapacity() const override;
     void shed() override;
     void breakUtility() override;
     void repair() override;
};

#endif // POWER_H
