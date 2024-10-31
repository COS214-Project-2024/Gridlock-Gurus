#include "EducationService.h"
#include "HighFundingEducationState.h"

EducationService::EducationService(int cost, std::string& location, Resources *resources, int size, Citizen& owner, TaxAuthority& taxAuthority, int id, BuildingType name) : Service(cost, location, resources, size, owner, taxAuthority,name,id){
    this->responseTime = 10;
    educationState = new HighFundingEducationState();
}

std::string EducationService::getDetails() const {
    std::string details =  "Health service: \n";
    details += "Owner: " + owner.getName() + "\n";
    details += "Location: " + location + "\n";
    details += "Capacity: " + std::to_string(employees.size()) + "/" + std::to_string(maxEmployees) + "\n";
    details += "Cost: " + std::to_string(cost) + "\n";
    details += "Size: " + std::to_string(size) + "\n";
    return details;
}

/*void EducationService::employ(Citizen& employee) {
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
}*/

/*void HealthService::fire(Citizen *employee) {
    auto it = find(staff.begin(), staff.end(), employee);
    if(it != staff.end()) {
        staff.erase(it);
        std::cout<< employee->getName() << " was fired from their job. Their patients breathe a sigh of relief.\n";
        employee->fired();
        currentStaff--;
    } else {
        std::cout << employee->getName() << " was not found. Perhaps we should call security?\n";
    }
}*/

/*void HealthService::retire(Citizen *employee) {
    auto it = find(staff.begin(), staff.end(), employee);
    if(it != staff.end()) {
        staff.erase(it);
        std::cout<< employee->getName() << " retired from their job. Their regular patients will miss them.\n";
        employee->retireToCountryside();
        currentStaff--;
    } else {
        std::cout << employee->getName() << " was not found. Perhaps they were commiting tax fraud?\n";
    }
}*/

int EducationService::pay() {
/*    auto it = find(staff.begin(), staff.end(), staffMember);
    if(it != staff.end()) {
        double salary;
        int amount = 223000;
        //benefits are affected by the state of education
        salary = amount*benefits;
        std::cout<< staffMember->getName() << " was paid their salary. R" << salary << " was paid into their account\n";
        return salary;
    } else {
        std::cout << staffMember->getName() << "? Who the heck are you? You're not a doctor!\n";
    }*/
    return 223000;
}

int EducationService::getResponseTime() {
    return responseTime;
}

void EducationService::setState(HealthState *state) {
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

