#ifndef CITIZENFACTORY_H
#define CITIZENFACTORY_H

#include <string>
#include <memory>
#include "Citizen.h"
#include "CitizenType.h"

class CitizenFactory {
private:
    std::shared_ptr<TaxAuthority> taxAuthority;
    int citizenCount = 0;

public:
    CitizenFactory(std::shared_ptr<TaxAuthority> taxAuthority);

     ~CitizenFactory() = default;

    Citizen* createCitizen(CitizenType type, int startingSatisfaction, int startingFunds);
};

#endif // CITIZENFACTORY_H
