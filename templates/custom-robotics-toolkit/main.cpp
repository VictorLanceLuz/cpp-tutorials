#include "functions.hpp"
#include "DataHolder.hpp"

void runToolkitDemo() {
    std::cout << midpoint(100, 200) << std::endl;

    std::string part1 = "chassis";
    std::string part2 = "engine"; 
    swapValues(part1, part2); 
    std::cout << "part1, part2 after swap: " << part1 << ", " << part2 << std::endl;

    DataHolder specialNumber(2.71, 1.618, 9.8); 
    std::cout << specialNumber.getValue() << std::endl;

    DataHolder<std::string> robotName("Codey the Robot");
    std::cout << robotName.getValue() << std::endl;
}

int main() {
    std::cout << midpoint(10, 20) << std::endl; 
    std::cout << midpoint(2.71, 3.14) << std::endl;

    int firstNumber = 5;
    int secondNumber = 10;
    swapValues(firstNumber, secondNumber); 
    std::cout << "firstNumber after swap: " << firstNumber << std::endl;
    std::cout << "secondNumber after swap: " << secondNumber << std::endl;

    std::string greeting = "hello";
    std::string planet = "world";
    swapValues(greeting, planet);
    std::cout << "greeting after swap: " << greeting << std::endl;
    std::cout << "planet after swap: " << planet << std::endl;

    // Testing the DataHolder Class
    DataHolder testNumber(42, 0, 100);
    std::cout << testNumber.getValue() << std::endl;

    testNumber.setValue(75);
    testNumber.setValue(150);

    DataHolder<std::string> testString("robotics lab");
    std::cout << "testString value: " << testString.getValue() << std::endl;

    runToolkitDemo(); 

    return 0;
}