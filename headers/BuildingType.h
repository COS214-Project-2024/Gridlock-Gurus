#ifndef BUILDINGTYPE_H
#define BUILDINGTYPE_H
#include <iostream>
#include <string>
#include <ostream>

enum class BuildingType {
    Residential,
    Shop,
    BrickFactory,
    SteelFactory,
    WoodFactory,
    Bank,
    Flat,
    Estate,
    House,
    Statue,
    Park,
    PoliceStation,
    Hospital,
    School
};

// Overload operator<< to allow printing of BuildingType

#endif // BUILDINGTYPE_H
