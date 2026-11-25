#ifndef ROBOT_CONTROL_CENTER_HPP
#define ROBOT_CONTROL_CENTER_HPP

#include <vector>
#include <iostream>
#include "Robot.hpp"
#include "Exceptions.hpp"

class RobotControlCenter {
public:
    explicit RobotControlCenter(int capacity);
    void addRobot(Robot* robot); 
    void executeAllRobotTasks();
private:
    std::vector<Robot*> robotCollection;
    void logError(const std::string& errorMessage) noexcept; 
};



#endif // ROBOT_CONTROL_CENTER_HPP
