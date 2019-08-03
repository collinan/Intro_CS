//Program filename:driver.h
//Author:Andrew Collins
//Date:5/24/2016
//Description:header file for game .cpp where alll the game logic takes place
//funtions explaioned in .cpp file
//Input:
//Output:
#ifndef DRIVER_H
#define DRIVER_H

#include <iostream>
#include <cstring>
#include <cstdlib>
#include "game.h"
bool check_num(char *);
bool check_arguments(int, char **);
void invalid_input_error();
void print_cave(Game &g);
bool start_game(Game &);
void print_message(Game &);
void move_player(Game &);
bool check_valid_move(string, Game &g);
bool check_new_room(Game &);
void shoot_arrow(Game &);



#endif
