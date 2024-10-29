#include "PoliceService.h"
#include "PeaceState.h"
#include "UnrestState.h"

PoliceService::PoliceService(int cost, string location, Resources *resources, int size, Citizen *owner, TaxAuthority *taxAuthority, int id, int max, string name) : Service(cost, location, resources, size, owner, taxAuthority) {
    this->stationId = id;
    this->benefits = 1.5;
    this->maxStaff = max;
    this->currentStaff = 0;
    this->stationName = name;
    this->responseTime = 10;
    PeaceState* peaceState = new PeaceState();
    setState(peaceState);
}

string PoliceService::getDetails() {
    string details =  "Police service: \n";
    details += "Name: " + stationName + "\n";
    details += "Police state: " + this->policeState->getName() + "\n";
    details += "Response time: " + to_string(responseTime) + " minutes\n";
    details += "Owner: " + owner->getName() + "\n";
    details += "Location: " + location + "\n";
    details += "Capacity: " + to_string(currentStaff) + "/" + to_string(maxStaff) + "\n";
    details += "Cost: " + to_string(cost) + "\n";
    details += "Size: " + to_string(size) + "\n";
    return details;
}

void PoliceService::payTax() {
    owner->payTaxes();
}

void PoliceService::employ(Citizen *employee) {
    if(employee->getEmploymentStatus() != true) {
        if(currentStaff+1 <= maxStaff) {
            if(find(officers.begin(), officers.end(), employee) != officers.end()) {
                officers.push_back(employee);
            } else {
                cout<< employee->getName() << " is already employed.\n";
            }
            currentStaff++;
        } else {
            cout<< "This force is fully staffed, " + employee->getName() + " can't apply here.\n";
        }
    } else {
        cout<< employee->getName() << " is already employed.\n";
    }
}

void PoliceService::fire(Citizen *employee) {
    auto it = find(officers.begin(), officers.end(), employee);
    if(it != officers.end()) {
        officers.erase(it);
        cout<< employee->getName() << " was fired from their job. Bad cops just don't go far.\n";
        employee->fired();
        currentStaff--;
    } else {
        std::cout << employee->getName() << " was not found. Did we search them before they left?\n";
    }
}

void PoliceService::retire(Citizen *employee) {
    auto it = find(officers.begin(), officers.end(), employee);
    if(it != officers.end()) {
        officers.erase(it);
        cout<< employee->getName() << " retired from their job. They are awarded a medal for their service.\n";
        employee->retireToCountryside();
        currentStaff--;
    } else {
        std::cout << employee->getName() << " was not found. Perhaps they were commiting tax fraud?\n";
    }
}

int PoliceService::pay(Citizen *staffMember) {
    auto it = find(officers.begin(), officers.end(), staffMember);
    if(it != officers.end()) {
        double salary;
        int amount = 33000;
        //benefits are affected by the state of police
        salary = amount*benefits;
        cout<< staffMember->getName() << " was paid their salary. R" << salary << " was paid into their account\n";
        return salary;
    } else {
        std::cout << staffMember->getName() << "? Who the heck are you? Where did you get that badge?\n";
    }
}

int PoliceService::getStaff() {
    return currentStaff;
}

int PoliceService::getMaxStaff() {
    return maxStaff;
}

void PoliceService::responseTimeDec(int by) {
    responseTime -= by;
}

void PoliceService::responseTimeInc(int by) {
    responseTime += by;
}

void PoliceService::checkOperation() {
    if(responseTime <= 10) {
        //fast response
        //check citizen satisfaction
    } else if (responseTime <= 20) {
        //slow response
        if(policeState->getName() == "UnrestState") {
            double ratio = static_cast<double>(currentStaff)/static_cast<double>(maxStaff);
            if(ratio > 0.5) {
                responseTimeInc(1);
            }
        } else {
            UnrestState* unrestState = new UnrestState();
            setState(unrestState);
        }
    }
}

void PoliceService::setState(PoliceState *state) {
    policeState = state;
    if(state->getName() == "UnrestState") {
        benefits -= 0.2;
    } else if(state->getName() == "PeaceState") {
        benefits += 0.2;
    }
}

void PoliceService::update(){
    payTax();
}
