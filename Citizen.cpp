#include "Citizen.h"

string Citizen::getName() {
    return name;
}

bool Citizen::getEmploymentStatus() {
    if(employmentStatus == true || retired == true) {
        return true;
    } else {
        return false;
    }
}

int Citizen::getFunds() {
    return funds;
}

