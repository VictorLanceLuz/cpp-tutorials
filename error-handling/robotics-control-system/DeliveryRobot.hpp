#ifndef DELIVERY_ROBOT_HPP
#define DELIVERY_ROBOT_HPP

#include "Robot.hpp"
#include "Exceptions.hpp"
#include <iostream>

class DeliveryRobot : public Robot {
public:
    DeliveryRobot(const std::string& name, int initialBatteryLevel);
    void performTask() override;

private:
    int batteryLevel;
};

#endif // DELIVERY_ROBOT_HPP