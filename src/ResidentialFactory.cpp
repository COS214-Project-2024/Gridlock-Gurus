#include "ResidentialFactory.h"
#include "City.h"
#include "Residential.h"
#include <iostream>
#include <ostream>

Building *ResidentialFactory::createBuilding(BuildingType type,Citizen &owner) {
  // cout<< "Constructing Residential Building...\n";
  Resources *resources = new Resources(400, 400, true);
  int maxInhabitants;
  int cost;

  /*    if(type != "") {
          if(type == "flat") {
              maxInhabitants = 2;
              cost = 1000;
              if(owner) {
                  int funds = owner->getFunds();
                  if(funds > cost) {
                      residence = new Residential(cost, "Business district",
     resources, 1000, citizen, tax, maxInhabitants); } else { cout<<
     owner->getName() <<" has insufficient funds.\n";
                  }
              }
          } else if(type == "house") {
              maxInhabitants = 6;
              cost = 120000;
              if(owner) {
                  int funds = owner->getFunds();
                  if(funds > cost) {
                      residence = new Residential(cost, "Residential district",
     resources, 100000, citizen, tax, maxInhabitants); } else { cout<<
     owner->getName() <<" has insufficient funds.\n";
                  }
              }
          } else if(type == "highRise") {
              maxInhabitants = 30;
              cost = 30000000;
              if(owner) {
                  int funds = owner->getFunds();
                  if(funds > cost) {
                      residence = new Residential(cost, "Industrial district",
     resources, 1000000000, citizen, tax, maxInhabitants); } else { cout<<
     owner->getName() <<" has insufficient funds.\n";
                  }
              }
          } else if(type == "estate") {
              maxInhabitants = 100;
              cost = 100000000;
              if(owner) {
                  int funds = owner->getFunds();
                  if(funds > cost) {
                      residence = new Residential(cost, "Residential district",
     resources, 100000000000, citizen, tax, maxInhabitants); } else { cout<<
     owner->getName() <<" has insufficient funds.\n";
                  }
              }
          } else if(type == "hotel") {
              maxInhabitants = 50;
              cost = 10000000;
              if(owner) {
                  int funds = owner->getFunds();
                  if(funds > cost) {
                      residence = new Residential(cost, "CBD", resources,
     500000000, citizen, tax, maxInhabitants); } else { cout<< owner->getName()
     <<" has insufficient funds.\n";
                  }
              }
          }
      }*/
  if (type == BuildingType::Flat) {
    cost = 500;
    maxInhabitants = 2;
    location = "City center";
  } else if (type == BuildingType::House) {
    cost = 2000;
    maxInhabitants = 5;
    location = "Suburbs";
  } else if (type == BuildingType::Estate) {
    cost = 3000;
    maxInhabitants = 10;
    location = "Country";

  } else {
    cost = 3000;
    maxInhabitants = 10;
    location = "Country";
  }

  return new Residential(cost, location, resources, 5000, owner, taxAuthority,
                         type, maxInhabitants);
}
