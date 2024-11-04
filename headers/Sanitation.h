#ifndef SANITATION_H
#define SANITATION_H

#include "Utilities.h"
#include "UtilityType.h"

class Sanitation : public Utilities {
public:
    Sanitation() : Utilities(UtilityType::Sanitation,300,300) {}

    ~Sanitation()override = default;
    void checkCapacity() const override;

    void shed() override;
    void breakUtility() override;
    void repair() override;

};

#endif // SANITATION_H
