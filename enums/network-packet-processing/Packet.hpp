#include <string>
#include <iostream>
#include "PacketType.hpp"
#include "Protocol.hpp"
#include "Status.hpp"

class Packet {
private:
    std::string getPacketTypeName() const;
    std::string getStatusName() const;
    PacketType type; 
    Protocol protocol; 
    Status packetStatus;
public:
    std::string getProtocolName() const;
    void validatePacket();
    bool isError();
    void displayInfo(); 
    void setType(PacketType newType);
    
    Packet(PacketType pType, Protocol prtcl)
        : type(pType), protocol(prtcl) {}
    


};
