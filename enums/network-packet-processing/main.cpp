#include <iostream>
#include "Packet.hpp"

int main() { 
    Packet udpPacket(CONTROL, Protocol::TCP);
    udpPacket.validatePacket();
    udpPacket.displayInfo();
    return 0;
}