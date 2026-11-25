#include "RobotControlCenter.hpp"

RobotControlCenter::RobotControlCenter(int capacity) {
    if (capacity < 0) {
        throw RobotException("EXCEPTION: Negative capacity.");
    } else {
        std::cout << "The control centre was created." << std::endl;
    }
}

void RobotControlCenter::addRobot(Robot* robot) {
    robotCollection.push_back(robot); 
}

void RobotControlCenter::executeAllRobotTasks() {
    try {
        for (auto& robot : robotCollection) {
            robot->performTask(); 
        } 
    } 
    catch (const BatteryLowException& e) {
        logError(e.what());        
    }
    catch (const MechanicalFailureException& e) {
        logError(e.what());
    } 
    catch (const RobotException& e) { // catch other robot exceptions
        logError(e.what());
    }
    catch (...) {// catch any other possible exceptions.
        logError("Unknown robot error"); 
        throw; // rethrow because unexpected or unkonwn error. 
    }
}

void RobotControlCenter::logError(const std::string &errorMessage) noexcept
{
    std::cout << "[Log Error]: " << errorMessage << std::endl;
}
