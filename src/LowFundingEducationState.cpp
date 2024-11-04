#include "LowFundingEducationState.h"

/**
 * @brief Gets the education quality for the low funding education state.
 *
 * @return The education quality as an integer (currently always returns 0).
 */
int LowFundingEducationState::getEducationQuality() {
/*    int staff = service->getStaff();
    int maxStaff = service->getMaxStaff();
    double ratio = static_cast<double>(staff) / maxStaff;
    int percentage;
    if(ratio < 0.3) {
        percentage = 20;
    } else if(ratio < 0.4) {
        percentage = 30;
    } else if (ratio < 0.5) {
        percentage = 40;
    } else if (ratio <= 0.75) {
        percentage = 70;
    } else if (ratio <= 0.90) {
        percentage = 90;
    } else {
        percentage = 100;
    }
    return percentage;*/
    return 0;
}

/**
 * @brief Checks the education state and updates the prestige of the service based on education quality.
 */
void LowFundingEducationState::checkEducationState() {
/*    if(service) {
        int quality = getEducationQuality();
        if (quality < 30) {
            cout << "Education quality is far below standard.\n";
            service->prestigeDec(3);
        } else if (quality <= 60) {
            cout << "Education quality is above average.\n";
            service->prestigeInc(1);
        } else if (quality <= 90) {
            cout << "Education quality is exceptional.\n";
            service->prestigeInc(3);
        } else {
            cout << "Education quality is outstanding.\n";
            service->prestigeInc(service->getStaff());
        }
    } else {
        cout<< "Error: this state has not been assigned.\n";
    }*/
}

/**
 * @brief Gets the name of the current education state.
 *
 * @return A string representing the name of the education state.
 */
std::string LowFundingEducationState::getName() {
    return "Low Funding";
}


