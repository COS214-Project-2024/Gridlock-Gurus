#include "Service.h"

Service::Service(int cost, std::string location, Resources *resources, int size, Citizen *owner, std::weak_ptr<TaxAuthority> taxAuthority) : Building(cost, location, resources, size, owner, taxAuthority) {
    type = "Service";
}
