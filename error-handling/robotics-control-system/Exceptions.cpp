#include "Exceptions.hpp"

RobotException::RobotException (const std::string& message)
    : errorMessage(message) {}

const char* RobotException::what() const noexcept {
    return errorMessage.c_str();
}

