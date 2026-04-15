#include "tictactoe_functions.hpp"
#include <iostream>

int main() {
    std::vector<char> board(9, ' '); // 9 empty spaces.
    int index; 
    bool player = 0; 

    welcome_screen();
    
    
    for (int i = 0; i < 9; i++) {    
        std::cout << "Player " << player + 1 << ": please pick where to place your X or O"; 
        display_board(board); 


        // Check that they enter a number for position. 
        do {
            std::cout << "Enter a position (0-8): ";
            while (!(std::cin >> index)) {
                std::cin.clear(); 
                std::cin.ignore(1000, '\n');
                std::cout << "Invalid input, please enter a number: "; 
            }
        }
        while (!is_valid_move(board, index));

        // Next steps is to add the input into the board and change board. 
        // Move function that takes index and the board as arguments. 
        // Ouptuts the new vector 
        move(board, index, player); 
        
        if (is_winner(board)) {
            display_board(board);
            std::cout << "Congratulations, Player " << player + 1; 
            break;
        }

        // End turn and swap players.
        player = swap_players(player); 
    }
}

