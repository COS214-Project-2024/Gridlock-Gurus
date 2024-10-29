#include "Service.h"

Service::Service(int cost, std::string location, Resources *resources, int size, Citizen *owner, TaxAuthority *taxAuthority) : Building(cost, location, resources, size, owner, taxAuthority) {
    type = "Service";
}
