#include "RobotControlCenter.hpp"
#include "DeliveryRobot.hpp"
#include "MaintenanceRobot.hpp"
#include <memory> // for unique_ptr

int main() {
    try {
        RobotControlCenter controlCenter(5);
        std::unique_ptr<DeliveryRobot> DR1 = std::make_unique<DeliveryRobot> ("DR1", 50);
        std::unique_ptr<DeliveryRobot> DR2 = std::make_unique<DeliveryRobot> ("DR2", 10);
        std::unique_ptr<MaintenanceRobot> MR1 = std::make_unique<MaintenanceRobot> ("MR1", 80);
        std::unique_ptr<MaintenanceRobot> MR2 = std::make_unique<MaintenanceRobot> ("MR2", 20);

        controlCenter.addRobot(DR1.get()); // used .get() to provide raw pointer.
        controlCenter.addRobot(DR2.get());
        controlCenter.addRobot(MR1.get());
        controlCenter.addRobot(MR2.get());
        try {
            controlCenter.executeAllRobotTasks();
        }
        catch (...) {
            std::cout << "Unexpected error: shutting down factory" << std::endl;
            std::cout << "Program finished." << std::endl;
            return 0;
        }
    }
    catch (const RobotException& e) {
        std::cout << e.what() << std::endl;
        return 0;
    }
    return 0;
}