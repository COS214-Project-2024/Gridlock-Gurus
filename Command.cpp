#include "Command.h"
#include <iostream>

Command::Command() 
    : status(PENDING), executionCount(0) {}

Command::~Command() {}

void Command::executed() {
    status = EXECUTED;
    executionCount++;

}

void Command::undo() {
    // Set status to UNDONE and log the undo action
    if (status == EXECUTED) {
        status = UNDONE;
        std::cout << "Command undone" << std::endl;
    }
}

void Command::redo() {
    if (status == UNDONE) {
        // Re-execute the command and set status back to EXECUTED
        execute();
        std::cout << "Command redone" << std::endl;
    }
}

Command::Status Command::getStatus() const {
    return status;
}

int Command::getExecutionCount() const {
    return executionCount;
}
