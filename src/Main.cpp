
#include <iostream>
#include "TransportDepartment.h"
#include "CitizenFactory.h"
#include "Train.h"
#include "Taxi.h"
#include "Truck.h"
#include "Functional.h"
#include "Damaged.h"
#include "Broken.h"
#include "TaxAuthority.h"
#include <iostream>


int main() {
   TransportDepartment department;


    Train* train = new Train(100);
    Taxi* taxi = new Taxi(4);
    Truck* truck = new Truck(10);


    Functional functional;
    Damaged damaged;
    Broken broken;

    
    train->setState(&functional);
    taxi->setState(&damaged);
    truck->setState(&broken);

    
    department.addVehicle(train);
    department.addVehicle(taxi);
    department.addVehicle(truck);

    std::weak_ptr<TaxAuthority> tax = new TaxAuthority();
    // Citizen alice("Alice", 1);
    // Citizen bob("Bob", 2);
    Citizen* alice = new Citizen("citizen", 100, 5000, tax);
    Citizen* bob = new Citizen("citizen", 100, 5000, tax);

    
    alice->callTransport(department, "Train");
    bob->callTransport(department, "Taxi");  

    train->run();
    train->delay();
    truck->run();  
    truck->breakDown();  

    
    std::cout << "\n--- State Transitions ---" << std::endl;
    taxi->repair();  
    taxi->setState(&functional);
    taxi->run();

    std::cout << "\n--- Offloading Passengers ---" << std::endl;
    alice->offloadVehicle();
    bob->offloadVehicle();  

    std::cout << "\n--- Cloning Vehicles ---" << std::endl;
    Vehicle* clonedTrain = train->clone();
    std::cout << "Cloned a new: " << clonedTrain->getType() << std::endl;

    delete train;
    delete taxi;
    delete truck;
    delete clonedTrain;

    std::cout << "\n--- All Tests Completed ---" << std::endl;
}

