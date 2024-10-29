#include "Residential.h"
#include <algorithm>
#include <iostream>

Residential::Residential(int cost, std::string location, Resources *resources, int size, Citizen *owner, TaxAuthority *taxAuthority, int capacity) : Building(cost, location, resources, size, owner, taxAuthority) {
    this->maxCapacity = capacity;
}

string Residential::getDetails() {
    string details =  "Residential: \n";
    details += "Owner: " + owner->getName() + "\n";
    details += "Location: " + location + "\n";
    details += "Capacity: " + to_string(capacity) + "/" + to_string(maxCapacity) + "\n";
    details += "Cost: " + to_string(cost) + "\n";
    details += "Size: " + to_string(size) + "\n";
    return details;
}

void Residential::payTax(int amount) {
    owner->payTaxes(amount);
}

void Residential::householdTax() {
    for (Citizen* tenant : tenants) {
        if (tenant) {
            tenant->payTaxes();
        }
    }
}

void Residential::addTenant(Citizen* tenant) {
    if(capacity+1 <= maxCapacity) {
        if(find(tenants.begin(), tenants.end(), tenant) != tenants.end()) {
            tenants.push_back(tenant);
        } else {
            std::cout<< tenant->getName() << " is already a resident.\n";
        }
        capacity++;
    } else {
        std::cout<< "This building is full, " + tenant->getName() + " can't move in.\n";
    }
}

void Residential::removeTenant(Citizen *tenant) {
    auto it = find(tenants.begin(), tenants.end(), tenant);
    if(it != tenants.end()) {
        tenants.erase(it);
        cout<< tenant->getName() << " moved out after giving their notice.\n";
        capacity--;
    } else {
        std::cout << tenant->getName() << " was not found. Perhaps they were a squatter?\n";
    }
}

int Residential::pay(Citizen* citizen){
    if(citizen == owner){
        int salary = 40000;
        cout<< owner->getName() << " was paid their salary. R" << salary << " was paid into their account\n";
        return salary;
    }
    else{
        cout << citizen->getName() << ", you're not the owner? How did you get in here??\n";
        return 0;
    }
}

void Residential::update(){
    payTax();
    householdTax();
}

