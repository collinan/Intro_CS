//Program filename:game.h
//Author:Andrew Collins
//Date:5/24/2016
//Description:part of wumpus game, header file for game.cpp
//Input:
//Output:
#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include "room.h"
#include "wumpus.h"
#include "bats.h"
#include "gold.h"
#include "pit.h"

using namespace std;
//function explained in game.cpp
class Game{

   private:
      int rows;//number of rows in grid
      int arrows;//number of arrows player has
      Rooms **rms;//grid of room has event pointer 
      int **rc;//array or grid of room set to 0 if no event in them
      string **precepts;//grid hold percepts
      int gold;//player gold amount 
      int wumpus_dead;//0 if not dead 1 if dead
      int start_loc[2];//start location
      int gl[2];//initial gold location
      int wl[2];//intitia wumpus location
      int p_loc[2];//player loaction
      //events
      Wumpus e_w;//derived event 
      Bats e_b;//derived event
      Gold e_g;//derived event
      Pit e_p;//derived event



   public:
      Game();//default constructor
      Game(int);//non default constructor
      ~Game();//destructor
      void reset();
      void set_rooms();
      void set_arrows();
      void set_start_loc();

      void set_wumpus_dead(int );
      void set_rows(int);
      void set_gold();
      void set_player_location();
      void reset_player_location(int ,int);
      void reset_rc_block(int ,int,int);
      void set_precepts(int );
      void reset_rms(int , int);
      void reset_wumpus();
      string message(int);

      int get_rows();
      int get_arrows();
      int get_wumpus_dead();
      int *get_player_loc();
      int *get_start_loc();
      string **get_precepts();
      int **get_rc();
      Rooms **get_rms();
      int get_gold();
};

#endif
