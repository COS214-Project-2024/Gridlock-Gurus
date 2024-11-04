#ifndef EDUCATIONSTATE_H
#define EDUCATIONSTATE_H

#include "EducationService.h"
#include <string>
#include <iostream>
class EducationService;
class EducationState {
protected:
    EducationService& service;
    std::string name;

public:
    EducationState(EducationService& service) : service(service) {}
    virtual ~EducationState() = default;
    virtual void checkEducationState() = 0;
    virtual int getEducationQuality() = 0;
    virtual std::string getName() = 0;
};

#endif // EDUCATIONSTATE_H
