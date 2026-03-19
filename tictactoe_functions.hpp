#pragma once
#include <vector>

void welcome_screen();

void display_board(const std::vector<char> board);

bool is_valid_move(const std::vector<char> board,int index);

bool is_winner(const std::vector<char> board);

bool swap_players(bool player);

void move(std::vector<char> &board, int index, bool player); 