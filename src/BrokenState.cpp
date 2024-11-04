/**
* @class BrokenState
 * @brief Definition of the BrokenState class, representing a non-functional state.
 */

#include "BrokenState.h"
#include <iostream>

/**
 * @brief Executes the operation in the broken state.
 *
 * @return A boolean value indicating the success of the operation; always returns false.
 */
bool BrokenState::run() {
    return false;
}
