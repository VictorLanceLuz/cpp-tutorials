#include <iostream>
#include "Marketing.hpp"
#include "Sales.hpp"


int main() {
    std::vector<std::string> marketingMembers;
    std::vector<std::string> salesMembers;
    
    // create an instance of marketing team.
    Marketing::Team marketingTeam("Stellar Corp", marketingMembers, 500000);
    
    // print the info of the marketing team.

    // add members to the marketing team.
    marketingTeam.addMember("Scott");
    marketingTeam.addMember("Nicole");
    marketingTeam.addMember("Artem");
    
    // create a sales team instance.
    Sales::Team salesTeam("Stellar Corp", salesMembers, "London");

    // add members to the sales team.
    salesTeam.addMember("Pratik");
    salesTeam.addMember("Emily");
    salesTeam.addMember("Clive");

    // print the info of the sales team.
    salesTeam.printTeamDetails();

    // scenario: move sales team from london to new york.
    salesTeam.setTeamLocation("New York");

    // print info of sales team again.
    salesTeam.printTeamDetails();

    // audit the marketing team. use alias to shorten the long namespace chain.
    namespace audit = Marketing::Support;
    audit::auditTeam(marketingTeam); 

    return 0;
}