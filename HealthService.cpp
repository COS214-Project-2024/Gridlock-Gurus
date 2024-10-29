#include "HealthService.h"
#include "HighFundingState.h"

HealthService::HealthService(int cost, std::string location, Resources *resources, int size, Citizen *owner, TaxAuthority *taxAuthority, int id, int max, std::string name) : Service(int(cost), location, resources, size, owner, taxAuthority){
    this->hospitalId = id;
    this->benefits = 1.8;
    this->maxStaff = max;
    this->currentStaff = 0;
    this->hospitalName = name;
    this->responseTime = 10;
    HealthState* highFunding = new HighFundingState();
    healthState = highFunding;
}

std::string HealthService::getDetails() {
    std::string details =  "Health service: \n";
    details += "Name: " + hospitalName + "\n";
    details += "Hospital state: " + this->healthState->getName() + "\n";
    details += "Response time: " + std::to_string(responseTime) + " minutes\n";
    details += "Owner: " + owner->getName() + "\n";
    details += "Location: " + location + "\n";
    details += "Capacity: " + std::to_string(currentStaff) + "/" + std::to_string(maxStaff) + "\n";
    details += "Cost: " + std::to_string(cost) + "\n";
    details += "Size: " + std::to_string(size) + "\n";
    return details;
}

// void HealthService::payTax() {
//     owner->payTaxes();
// }

void HealthService::employ(Citizen *employee) {
    if(employee->getEmploymentStatus() != true) {
        if(currentStaff+1 <= maxStaff) {
            if(find(staff.begin(), staff.end(), employee) != staff.end()) {
                staff.push_back(employee);
            } else {
                std::cout<< employee->getName() << " is already employed.\n";
            }
            currentStaff++;
        } else {
            std::cout<< "This institution is fully staffed, " + employee->getName() + " can't apply here.\n";
        }
    } else {
        std::cout<< employee->getName() << " is already employed.\n";
    }
}

void HealthService::fire(Citizen *employee) {
    auto it = find(staff.begin(), staff.end(), employee);
    if(it != staff.end()) {
        staff.erase(it);
        std::cout<< employee->getName() << " was fired from their job. Their patients breathe a sigh of relief.\n";
        employee->fired();
        currentStaff--;
    } else {
        std::cout << employee->getName() << " was not found. Perhaps we should call security?\n";
    }
}

void HealthService::retire(Citizen *employee) {
    auto it = find(staff.begin(), staff.end(), employee);
    if(it != staff.end()) {
        staff.erase(it);
        std::cout<< employee->getName() << " retired from their job. Their regular patients will miss them.\n";
        employee->retireToCountryside();
        currentStaff--;
    } else {
        std::cout << employee->getName() << " was not found. Perhaps they were commiting tax fraud?\n";
    }
}

int HealthService::pay(Citizen *staffMember) {
    auto it = find(staff.begin(), staff.end(), staffMember);
    if(it != staff.end()) {
        double salary;
        int amount = 223000;
        //benefits are affected by the state of education
        salary = amount*benefits;
        std::cout<< staffMember->getName() << " was paid their salary. R" << salary << " was paid into their account\n";
        return salary;
    } else {
        std::cout << staffMember->getName() << "? Who the heck are you? You're not a doctor!\n";
    }
}

int HealthService::getResponseTime() {
    return responseTime;
}

void HealthService::setState(HealthState *state) {
    healthState = state;
    if(state->getName() == "HighFundingState") {
        benefits += 0.2;
    } else if(state->getName() == "LowFundingState") {
        benefits -= 0.2;
    }
}

void HealthService::responseTimeDec(int by) {
    responseTime -= by;
}

void HealthService::responseTimeInc(int by) {
    responseTime += by;
}

// void HealthService::update(){
//     payTax();
// }