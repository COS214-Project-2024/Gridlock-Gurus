#ifndef EDUCATIONSTATE_H
#define EDUCATIONSTATE_H

#include "EducationService.h"
#include <string>
#include <iostream>

/**
 * @brief Forward declaration of EducationService class.
 */
class EducationService;

/**
 * @brief Abstract base class representing the state of an education service.
 */
class EducationState {
protected:
    EducationService& service; ///< Reference to the associated EducationService.
    std::string name;          ///< Name of the education state.

public:
    /**
     * @brief Constructs an EducationState with the given service.
     * @param service Reference to the EducationService associated with this state.
     */
    EducationState(EducationService& service) : service(service) {}

    /**
     * @brief Virtual destructor for EducationState.
     */
    virtual ~EducationState() = default;

    /**
     * @brief Checks and updates the state of education based on conditions.
     */
    virtual void checkEducationState() = 0;

    /**
     * @brief Gets the quality of education provided.
     * @return The quality level of education.
     */
    virtual int getEducationQuality() = 0;

    /**
     * @brief Gets the name of this education state.
     * @return The state name.
     */
    virtual std::string getName() = 0;
};

#endif // EDUCATIONSTATE_H
