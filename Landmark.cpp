#include "Landmark.h"
#include <iostream>

using namespace std;

Landmark::Landmark(int cost, std::string location, Resources *resources, int size, Citizen *owner, TaxAuthority *taxAuthority, string name) : Building(cost, location, resources, size, owner, taxAuthority){
    this->name = name;
}

std::string Landmark::getDetails() {
    string details =  "Landmark: \n";
    details += "Name: " + name + "\n";
    details += "Owner: " + owner->getName() + "\n";
    details += "Location: " + location + "\n";
    details += "Cost: " + to_string(cost) + "\n";
    details += "Size: " + to_string(size) + "\n";
    return details;
}

void Landmark::payTax() {
    owner->payTaxes();
}

int Landmark::pay(Citizen* citizen){
    if(citizen == owner){
        int salary = 20000;
        cout<< owner->getName() << " was paid their salary. R" << salary << " was paid into their account\n";
        return salary;
    }
    else{
        cout << citizen->getName() << ", you're not the owner? Did you forge this paperwork??\n";
        return 0;
    }
}

void Landmark::update(){
    payTax();
}
