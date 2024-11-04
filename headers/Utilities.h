#ifndef UTILITIES_H
#define UTILITIES_H
#include "UtilityType.h"
#include <string>

class Utilities {
protected:
    UtilityType type;
    int maxProduction;
    bool shedding;
    bool isRepair;
    int costOfRepair;

public:
    Utilities(UtilityType type, int maxProduction, int costOfRepair) : type(type), maxProduction(maxProduction),shedding(false),isRepair(false),costOfRepair(costOfRepair) {}

    virtual void checkCapacity() const ;

     virtual void shed();

     virtual void breakUtility();

     virtual void repair();

     virtual ~Utilities() = default;

     UtilityType getType() const { return type; }

     bool isShedding() const { return shedding; }

     bool isBroken() const { return isRepair; }

     int getMax() const {
        return maxProduction;
     }
     
    int getCost() const {
        return costOfRepair;
    }

    void upgradeProduction() {
        this->maxProduction *= 2;
    }
};

#endif // UTILITIES_H

