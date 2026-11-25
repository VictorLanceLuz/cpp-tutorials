#include "Packet.hpp"

void Packet::setType(PacketType newType) {
    type = newType; 
}

std::string Packet::getProtocolName() const {
    switch(protocol) {
        case Protocol::TCP:
            return "TCP";
            break;
        case Protocol::UDP:
            return "UDP";
            break;
        case Protocol::HTTP:
            return "HTTP";
            break;
        case Protocol::FTP:
            return "FTP";
            break;
        default:
            return "Unknown Protocol";
            break;
    }
}

void Packet::validatePacket() {
    switch(type) {
        case PacketType::DATA:
            if (protocol == Protocol::TCP ||
                protocol == Protocol::UDP) {
                packetStatus = Status::VALID; 
            } else {
                packetStatus = Status::INVALID;
            }
            break;
        case PacketType::CONTROL:
            if (protocol == Protocol::TCP) {
                packetStatus = Status::VALID;
            } else {
                packetStatus = Status::INVALID;
            }
            break;
        case PacketType::ERROR:
            packetStatus = Status::VALID;
            break;
        case PacketType::UNKNOWN:
            packetStatus = Status::INVALID;
            break;
        default:
            packetStatus = Status::INVALID;
            break;
    }
}

bool Packet::isError() {
    if (packetStatus == Status::INVALID) {
        return true;
    } else {
        return false;
    }
}

void Packet::displayInfo() {
    std::cout << "Packet Type: " << getPacketTypeName() << std::endl;
    std::cout << "Protocol Name: " << getProtocolName() << std::endl;
    std::cout << "Status Name: " << getStatusName() << std::endl; 
}

std::string Packet::getPacketTypeName() const {
    switch(type) {
        case UNKNOWN:
            return "UNKNOWN";
            break;
        case DATA:
            return "DATA";
            break;
        case CONTROL:
            return "CONTROL";    
            break;
        case ERROR:
            return "ERROR";    
            break;
        default:
            return "UNKNOWN ERROR";
            break;
    }
}

std::string Packet::getStatusName() const {
    switch(packetStatus) {
        case Status::PENDING:
            return "PENDING";
            break;
        case Status::VALID:
            return "VALID";
            break;
        case Status::INVALID:
            return "INVALID";
            break;
        case Status::TIMEOUT:
            return "TIMEOUT";
            break;
        default:
            return "Unknown Packet Status";
            break;
    }
}

