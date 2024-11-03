#ifndef DEPARTMENTOFHOMEAFFAIRS_H
#define DEPARTMENTOFHOMEAFFAIRS_H

#include "CitizenFactory.h"
#include "TaxAuthority.h"
#include <vector>
#include <algorithm>
#include <string>
#include <memory>
#include "Commercial.h"
#include "BuildingType.h"
#include "Citizen.h"
#include "BrickFactory.h"
#include "WoodFactory.h"
#include "SteelFactory.h"
#include "Residential.h"
#include "Landmark.h"
#include "EducationService.h"
#include "HealthService.h"
#include "PoliceService.h"


class Citizen;
class TaxAuthority;

class DepartmentOfHomeAffairs {
private:
    std::shared_ptr<TaxAuthority> taxAuthority;
    std::unique_ptr<CitizenFactory> factory;

public:
    int population;
    std::vector<Citizen*> citizens;

    DepartmentOfHomeAffairs(std::shared_ptr<TaxAuthority> taxAuth);

     ~DepartmentOfHomeAffairs();
     int calculateAvgHappiness();

    void fillHomeWithTenants(Residential& home); 
    void fillWorkWithEmployees(Factory& work); 
    void fillWorkWithEmployees(Service& work); 
    void fillWorkWithEmployees(Commercial& work); 
    Citizen& getRandomCitizen();
    int getPopulation() {
        return population;
    }
protected:
    void registerBirth();

    void registerDeath(Citizen& citizen);

};

#endif // DEPARTMENTOFHOMEAFFAIRS_H
