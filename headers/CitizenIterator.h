#ifndef CITIZENITERATOR_H
#define CITIZENITERATOR_H

#include "Citizen.h"

class CitizenIterator {
public:
    CitizenIterator();

    virtual ~CitizenIterator();

    bool hasNext();

    Citizen* next();
};

#endif // CITIZENITERATOR_H

