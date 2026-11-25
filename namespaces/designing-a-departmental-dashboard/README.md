# Designing a Departmental Dashboard

Your company, Stellar Corp, is quickly expanding, and different departments like Sales and Marketing are adding their own teams. Without structure, this can get messy. By using namespaces, you can group each department’s code in its own “container,” so they don’t clash with each other. This way, you’ll keep your code organized and easy to follow, even as the company—and your codebase—grows.

In this project, we’ll be doing the following:

- creating a Sales namespace to represent a sales team
- creating a Marketing namespace to represent a marketing team
- creating a nested Support namespace inside Marketing to audit a marketing team
- using a namespace alias to simplify calling the audit
- testing the code.

Let’s get started!

## Creating the Marketing Namespace

1. We will start by creating the namespace for the marketing department.

   In Marketing.hpp, create a namespace called Marketing.
2. Inside `Marketing`, create a class called `Team` that will represent a marketing team.

   Inside this class, add the following three private members:

   - a string called `teamName` to represent the team name
   - a vector of strings called `teamMembers` to represent the members of the team
   - a member called `teamBudget` of type `double` to represent the budget
3. Add a constructor to Team that takes the following parameters:

   - a string called `name` that initializes the `teamName`
   - a vector called `members` that initializes `teamMembers`
   - an integer called `budget` that initializes `teamBudget`
4. Add a function called getName() that returns the team’s name.
5. In the `Team` class, add a function called `addMember(std::string member)` that adds a team member to the `teamMembers` vector.
6. Add a function called `getMemberCount()` that returns the number of members on the team.
7. Add the getter and setter functions, `getBudget()` and `setBudget(double newBudget)`, for the team `budget`.

## Creating a Marketing Support Namespace

8. The `Marketing` namespace will include an inner namespace called `Support`, which houses functions that help us interact with members of the outer `Marketing` namespace. Having a dedicated `Support` namespace ensures that members’ names within this namespace do not conflict with those in the `Marketing` namespace, even if any share the same name.

   To start, create a namespace called `Support` inside the `Marketing` namespace.
9. Inside the `Support` namespace, create a function called `auditTeam()`. This function will accept a marketing `Team` parameter called `team` passed in by reference.

   > Note: Passing `team` by reference is required!
   >

   In the function, print the following string:

   ```c++
   Auditing Marketing Team: `<team name>`
   Number of Members: `<member count>`
   Team Budget: $`<budget>`
   Audit complete!
   ```

## Creating a Sales Namespace

10. Let’s create a namespace to represent a sales department.

    To start, in `Sales.hpp`, create a namespace called `Sales`.
11. The sales department will also have a class called `Team` to represent a sales team.

    Inside the `Sales` namespace, create a class called `Team` with the following private members:

    - a string to represent the team’s name called `teamName`
    - a vector to represent the team’s members called `teamMembers`
    - a string to represent the location of the sales team called `teamLocation`
12. Add a constructor to the `Team` class that takes the following parameters and uses them to initialize the appropriate class member:

    - a string called `name` to initialize the `teamName`
    - a vector of strings called `members` to initialize the `teamMembers` vector
    - a string called `location` to initialize the `teamLocation`
13. Add a function called `getTeamName()` that returns the name of the sales team.
14. Add a function called `getMembers()` that returns the vector of team members.
15. Add a function called `addMember(std::string member)` that adds a member to the vector of team members.
16. Add getter and setter functions for the `teamLocation` of the sales team. For the setter, use `location` as the parameter and pass it in by reference.
17. Add a function called `printTeamDetails()` to print the following strings:

   ```c++
   Sales Team Name: <teamName>
   Location: <teamLocation>
   Members: <member1>, <member2>, ... <memberN>
   ```

## Creating the Stellar Corp Marketing and Sales Teams

18. Let’s create Stellar Corp’s marketing and sales teams.

    To start, in `main.cpp`, create two vectors of strings called `marketingMembers` and `salesMembers`.
19. Using the `Marketing` namespace, create a marketing `Team` called `marketingTeam`. Use the following values to initialize the team:

    - name:`"Stellar Corp"`
    - string vector: `marketingMembers`
    - budget: `500000`
20. Add the following three members to the marketing team:

    - `"Scott"`
    - `"Nicole"`
    - `"Artem"`
21. Using the `Sales` namespace, create a sales `Team` called `salesTeam`. Use the following values to initialize the team:

    - name: `"Stellar Corp"`
    - string vector: `salesMembers`
    - location: `"London"`
22. Add the following three members to the sales team:

    - `"Pratik"`
    - `"Emily"`
    - `"Clive"`
23. Print the information of the sales team.
24. Let’s simulate a sales team relocation scenario. Move the sales team from London to New York.
25. Print the details of the sales team again to see if the move was successful.
26. Let’s audit the marketing team. The `Marketing` namespace has a `Support` namespace in which you created an `auditTeam()` function to be used to audit a marketing team. However, since this function is in a nested namespace, accessing it will require using a long chain of namespaces.

    Simplify this process by creating a namespace alias called `audit` to access the `auditTeam()` function.
27. Use this new `audit` alias to audit the marketing team.
28. Congratulations! You created namespaces for a marketing and sales team!

    For added practice, you can try the following:

    - Create namespaces to represent other departments of a company, such as engineering, human resources, and communications.
    - Add more members to the `Marketing` `Support` namespace, such as a function that handles communication between the marketing department and another department.
    - Create a `Support` namespace for the `Sales` namespace with support members, such as an audit (as you did for marketing).

    These will further strengthen your knowledge of C++ namespaces.
