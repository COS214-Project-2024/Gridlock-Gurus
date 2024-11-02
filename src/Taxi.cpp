#include "Taxi.h"
#include <iostream>

Vehicle* Taxi::clone() {
    return new Taxi(capacity,department);
}
