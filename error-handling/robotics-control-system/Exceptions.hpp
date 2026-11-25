#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>
#include <string>

class RobotException : public std::exception {
public:
    explicit RobotException (const std::string& message);
    const char* what() const noexcept override;
private:
    std::string errorMessage;
};

class BatteryLowException : public RobotException {
public:
    using RobotException::RobotException;
};

class MechanicalFailureException : public RobotException {
public:
    using RobotException::RobotException; 
};

#endif // EXCEPTIONS_HPP