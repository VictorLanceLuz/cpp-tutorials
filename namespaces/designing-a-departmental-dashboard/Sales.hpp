#include <iostream>
#include <string>
#include <vector>

namespace Sales {
    class Team {
    public:
        Team(std::string name, std::vector<std::string> members, std::string location) 
            : teamName(name), teamMembers(members), teamLocation(location) {}
        
        std::string getTeamName() const {
            return teamName;
        }

        std::vector<std::string> getMembers() const {
            return teamMembers; 
        }

        void addMember(std::string member) {
            teamMembers.push_back(member); 
        }

        std::string getTeamLocation() const {
            return teamLocation;
        }

        void setTeamLocation(std::string location) {
            teamLocation = location;
        }

        void printTeamDetails() {
            std::cout << "Sales Team Name: " << teamName << std::endl;
            std::cout << "Location: " << teamLocation << std::endl;
            std::cout << "Members: ";
            for (int i = 0; i < teamMembers.size(); ++i) {
                std::cout << teamMembers[i];
                if (i < teamMembers.size() - 1) std::cout << ", ";
            }
            std::cout << std::endl; 
        }
        
    private:
        std::string teamName;
        std::vector<std::string> teamMembers;
        std::string teamLocation; 
    };
}