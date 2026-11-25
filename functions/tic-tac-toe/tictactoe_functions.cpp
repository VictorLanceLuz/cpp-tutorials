#include "tictactoe_functions.hpp"
#include <iostream>

void welcome_screen() {
    std::cout << "Welcome to Tic Tac Toe.\n";
}

void display_board(const std::vector<char> board) {
  std::cout << "\n";
  std::cout << " " << board[0] << " | " << board[1] << " | " << board[2] << "\n";
  std::cout << "---|---|---\n";
  std::cout << " " << board[3] << " | " << board[4] << " | " << board[5] << "\n";
  std::cout << "---|---|---\n";
  std::cout << " " << board[6] << " | " << board[7] << " | " << board[8] << "\n";
  std::cout << "\n";
}

bool is_valid_move(const std::vector<char> board,int index) {
    return (index >= 0 && index < 9 && board[index] == ' ');
}

bool is_winner(const std::vector<char> board) {

    // We need to check that they are not all blank, otherwise it will throw false positive. 
    return board[0] != ' ' && board[0] == board[1] && board[1] == board[2]
        || board[3] != ' ' && board[3] == board[4] && board[4] == board[5] 
        || board[6] != ' ' && board[6] == board[7] && board[7] == board[8]

        || board[0] != ' ' && board[0] == board[3] && board[3] == board[6]
        || board[1] != ' ' && board[1] == board[4] && board[4] == board[7]
        || board[2] != ' ' && board[2] == board[5] && board[5] == board[8]

        || board[0] != ' ' && board[0] == board[4] && board[4] == board[8]
        || board[6] != ' ' && board[6] == board[4] && board[4] == board[2];
}

bool swap_players(bool player) {
    return !player;
}

void move(std::vector<char> &board, int index, bool player) {
    if (player == 0) {
        board[index] = 'X';  
    }
    else {
        board[index] = 'O'; 
    }
}