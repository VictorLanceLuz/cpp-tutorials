#ifndef MAINTENANCE_ROBOT_HPP
#define MAINTENANCE_ROBOT_HPP

#include "Robot.hpp"
#include "Exceptions.hpp"
#include <iostream>

class MaintenanceRobot : public Robot {
public:
    MaintenanceRobot(const std::string& name, int initialIntegrity);
    void performTask() override;
private:
    int mechanicalIntegrity;
};



#endif // MAINTENANCE_ROBOT_HPP