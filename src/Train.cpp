#include "Train.h"
#include <iostream>


Vehicle* Train::clone() {
    return new Train(capacity,department);
}
