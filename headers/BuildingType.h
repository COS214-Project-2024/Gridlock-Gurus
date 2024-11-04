#ifndef BUILDINGTYPE_H
#define BUILDINGTYPE_H
#include <iostream>
#include <string>
#include <ostream>

/**
 * @brief Enumeration representing different types of buildings.
 */
enum class BuildingType {
    Residential,     ///< Residential building.
    Shop,            ///< Shop or commercial building.
    BrickFactory,    ///< Factory for producing bricks.
    SteelFactory,    ///< Factory for producing steel.
    WoodFactory,     ///< Factory for producing wood.
    Bank,            ///< Bank building.
    Flat,            ///< Apartment or flat.
    Estate,          ///< Estate or large residence.
    House,           ///< House or single residence.
    Statue,          ///< Statue or monument.
    Park,            ///< Public park.
    PoliceStation,   ///< Police station.
    Hospital,        ///< Hospital or healthcare facility.
    School           ///< Educational institution.
};

/**
 * @brief Overloads the output stream operator for BuildingType.
 * @param os Output stream.
 * @param type The BuildingType to output.
 * @return Reference to the modified output stream.
 */
std::ostream& operator<<(std::ostream& os, BuildingType type);

#endif // BUILDINGTYPE_H
