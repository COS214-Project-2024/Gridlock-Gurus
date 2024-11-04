#ifndef WATER_H
#define WATER_H

#include "Utilities.h"
#include "UtilityType.h"

class Water : public Utilities {
public:
    Water() : Utilities(UtilityType::Water, 500, 300) {}

     ~Water()override = default;

    void checkCapacity() const override;

    void shed() override;
    void breakUtility() override;
    void repair() override;


};

#endif // WATER_H
