# Robotics Control System

A cutting-edge robot factory is prone to occasional malfunctions—some run low on battery, others break down from mechanical strain. You’ve been hired to create a system that gracefully handles these errors! By the end of this project, you’ll have a suite of robots, a central command to manage them, and robust exception handling so the factory can keep rolling.

## Build the Exception Classes

1. In `Exceptions.hpp`, declare a class `RobotException` derived from `std::exception`. Imagine this as the “flag” your robots will wave when something goes wrong. Give it a private `std::string errorMessage` to store the error details.
2. Write a constructor for `RobotException` that accepts a `const std::string& message` and stores its content in `errorMessage`. This lets you personalise each robot’s “flag.”
3. In `Exceptions.cpp`, override the `what()` method in `RobotException` so that it returns the stored `errorMessage` as a C-style string with `.c_str()`. This guarantees the message prints correctly.
4. Back in `Exceptions.hpp`, declare two special error classes, each inheriting from `RobotException`:

   - `BatteryLowException`
   - `MechanicalFailureException`

   Give every class a constructor that accepts a `const std::string& message` so it can forward the text to `RobotException`.
5. Implement the constructors for `BatteryLowException` and `MechanicalFailureException` in `Exceptions.cpp`. Remember that the parameter is called `message` because it comes from the parent `RobotException` class. Pass it straight to the base constructor.

## Create Specialized Robots

6. Some robots specialize in deliveries. In `DeliveryRobot.hpp`, declare a class `DeliveryRobot` inheriting from `Robot`. Give it a private integer `batteryLevel`. Declare a constructor that takes a `const std::string& name` (inherited from `Robot`) and an `int initialBatteryLevel`. You’ll define that constructor in a moment.
7. Still in `DeliveryRobot.hpp`, override the `performTask()` method. Copy the exact signature you see in `Robot.hpp`; you’ll fill in the body later.
8. In `DeliveryRobot.cpp`, define the constructor and store `initialBatteryLevel` in `batteryLevel`.
9. Now flesh out `performTask()` in `DeliveryRobot.cpp`:

   1. If `batteryLevel` is below `20`, throw a `BatteryLowException`.
   2. Otherwise, print `"DeliveryRobot is delivering"`, reduce `batteryLevel` by **10**, and then print `"Delivery done"`.
10. Maintenance is handled by a different bot. In `MaintenanceRobot.hpp`, declare a class `MaintenanceRobot` inheriting from `Robot`. Give it a private integer `mechanicalIntegrity`. Declare a constructor that takes a `const std::string& name` and an `int initialIntegrity`.
11. Override `performTask()` in `MaintenanceRobot.hpp` (again, match the signature from `Robot.hpp`).
12. In `MaintenanceRobot.cpp`, define the constructor and store `initialIntegrity` in `mechanicalIntegrity`.
13. Finish `performTask()` in `MaintenanceRobot.cpp`:

    1. If `mechanicalIntegrity` is below `30`, throw a `MechanicalFailureException`.
    2. Otherwise, print `"MaintenanceRobot is performing maintenance"`, reduce `mechanicalIntegrity` by **15**, and then print `"Maintenance done"`.

## Centralize Robot Management

14. To oversee all robots, in `RobotControlCenter.hpp`, declare a class `RobotControlCenter` with:

    - a private `std::vector<Robot*> robotCollection`;
    - a constructor that takes an `int capacity` to indicate how many robots the centre can hold.
15. In `RobotControlCenter.cpp`, implement the constructor. If `capacity` is negative, throw a `RobotException`; otherwise, print a confirmation that the control centre was created.
16. Still in `RobotControlCenter.hpp`, add a public function `void addRobot(Robot* robot);` and implement it in `RobotControlCenter.cpp` by pushing the pointer into `robotCollection`.
17. Declare a private method `logError(const std::string& errorMessage)` inside `RobotControlCenter.hpp`. This method should guarantee no exceptions will be thrown.
18. Create a public method `void executeAllRobotTasks()` in `RobotControlCenter.cpp`. Start it with a `try` block that loops through every `Robot*` in `robotCollection`, calling each robot’s `performTask()`.
19. Directly after the loop, add `catch` blocks for `BatteryLowException` and `MechanicalFailureException`. In each block, call `logError(e.what())`.
20. Add a separate `catch (const RobotException& e)` block and log the message the same way.
21. Finally, add a generic `catch (...)` block that logs `"Unknown robot error"` and then re-throws, signalling that something occurred outside the control centre’s scope.

## Test Everything in `main.cpp`

22. In `main.cpp`, you’ll set up your robot factory. Start by writing a `try` block inside `main()`. Inside the block, create a `RobotControlCenter controlCenter(5)`. If creating the centre throws a `RobotException`, catch it, print the error text, and then exit.
23. Create four robots with `new`: two `DeliveryRobot` objects (`batteryLevel` 50 and 10) and two `MaintenanceRobot` objects (`mechanicalIntegrity` 80 and 20). Add them all to `controlCenter` with `addRobot()`.
24. Still in `main()`, call `controlCenter.executeAllRobotTasks()` inside its own `try` block. Catch any exception you didn’t anticipate, print `"Unexpected error: shutting down factory"`, then print `"Program finished."` and return `0` to end the program cleanly.
25. Great work! You’ve created a resilient robotic management system that can handle real-world issues. If you’re feeling adventurous, here are a few bonus challenges to explore:

    - Add a new robot type with a different kind of failure scenario.
    - Track how many tasks each robot has completed successfully.
    - Extend `logError()` to save errors to a file instead of just printing them.
    - Add a repair feature to restore battery or integrity levels between tasks.

    Try out a few of these ideas to level up your robotic control system!
