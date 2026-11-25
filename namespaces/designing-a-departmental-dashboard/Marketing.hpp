#include <iostream>
#include <string>
#include <vector>

namespace Marketing {
    class Team {
    public:
        Team(std::string name, std::vector<std::string> members, double budget) : teamName(name), teamMembers(members), teamBudget(budget) {}
        
        std::string getName() const {
            return teamName; 
        }
        
        void addMember(std::string member) {
            teamMembers.push_back(member);
        }
        
        int getMemberCount() const {
            return teamMembers.size(); 
        }

        double getBudget() const {
            return teamBudget; 
        }

        void setBudget(double newBudget) {
            teamBudget = newBudget;
        }

    private: 
        std::string teamName;
        std::vector<std::string> teamMembers;
        double teamBudget;
    };

    namespace Support {
        void auditTeam(Marketing::Team& team) {
            std::cout << "Auditing Marketing Team: " << team.getName() << std::endl;
            std::cout << "Number of Members: " << team.getMemberCount() << std::endl;
            std::cout << "Team Budget: $" << team.getBudget() << std::endl;
            std::cout << "Audit complete!" << std::endl;
        }

        
    }
}