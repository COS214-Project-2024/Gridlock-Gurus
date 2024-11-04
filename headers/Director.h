#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "City.h"
#include "CityBuilder.h"

class Director {
public:
    Director();

    virtual ~Director();

    City* construct();

    void setBuilding(Building& building) {}
};

#endif // DIRECTOR_H
