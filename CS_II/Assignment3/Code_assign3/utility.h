//Program filename:utility.h
//Author:Andrew Collins
//Date:5/8/2016
//Description:this si where the game is played, the set up and the logic,has the declaration of the 
//funtion to play the game
//Input:/
//Output;/
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "zoo.h"
#include <ctime>

#ifndef UTILITY_H
#define UTILITY_H
using namespace std;
//function explained in utility.cpp
bool num_check(string);
bool error();
string buy();
bool check_bank(zoo&);
string which_animal_buy();
void buy_animal(zoo&);
void add_animal(int,int,int,zoo&);
string animal_name(int);
void print(zoo &);
void event_file(string);
void sickness(zoo &z);
void boom_in_attendance(zoo &z);
void baby_born(zoo &z);
void nothing();
void add_age(zoo&);
void feed(zoo&);
void random_event(zoo&);
bool end_game();
bool tiger_old_enough(zoo&);
bool polar_bear_old_enough(zoo&);
bool penguin_old_enough(zoo&);
void pay(zoo &);
bool run_zoo(zoo &);
#endif
