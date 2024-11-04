#ifndef EDUCATIONSERVICE_H
#define EDUCATIONSERVICE_H

#include "Service.h"
#include "EducationState.h"
#include "BuildingType.h"
#include <memory>

/**
 * @brief Forward declaration of EducationState class.
 */
class EducationState;

enum EducationStateType {
    HighFundingEducation,  ///< Education with high funding.
    LowFundingEducation    ///< Education with low funding.
};

/**
 * @brief Provides education services and manages educational state.
 */
class EducationService : public Service {
private:
    EducationStateType state;                           ///< Current state of the education service.
    std::unique_ptr<EducationState> educationState;     ///< Pointer to the current education state.
    int prestige;                                       ///< Prestige level of the education service.

public:
    /**
     * @brief Constructs an EducationService with specified parameters.
     * @param name Name of the service.
     * @param cost Cost of the service.
     * @param location Location of the service.
     * @param resources Resources used by the service.
     * @param size Size of the service.
     * @param owner Owner of the service.
     * @param id Unique identifier of the service.
     * @param type Type of the building.
     */
    EducationService(const std::string& name, int cost, std::string& location, Resources* resources, int size, Citizen& owner, int id, BuildingType type);

    /**
     * @brief Default destructor.
     */
    ~EducationService() override = default;

    /**
     * @brief Sets the current state of the city.
     * This function updates the city's state based on various factors such as citizen satisfaction,
     * resource availability, and building conditions. It may alter the overall status of the city.
     */
      void setState();

      /**
       * @brief Processes the payment for services or taxes.
       * @return An integer indicating the result of the payment process.
       * This function handles the payment logic, including deductions from citizen funds or city resources.
       * It overrides a base class function and may implement additional checks or calculations.
       */
      int pay() override;

      /**
       * @brief Decreases the prestige of the city by a specified amount.
       * @param by The amount to decrease the prestige.
       * This function modifies the city's prestige value, reflecting a decrease due to events such as
       * dissatisfaction among citizens or reduced services.
       */
      void prestigeDec(int by);

      /**
       * @brief Increases the prestige of the city by a specified amount.
       * @param by The amount to increase the prestige.
       * This function updates the city's prestige value, indicating improvements in citizen satisfaction,
       * services, or overall city conditions.
       */
      void prestigeInc(int by);


    /**
     * @brief Gets the prestige level of the education service.
     * @return The current prestige level.
     */
    int getPrestige();

    /**
     * @brief Gets the name of the current state of the education service.
     * @return The name of the current state.
     */
    std::string getState() const;
};

#endif // EDUCATIONSERVICE_H
