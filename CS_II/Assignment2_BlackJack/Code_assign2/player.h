//Program: Black Jack
//File:player.h 
//Name: Andrew Collins
//Date: 4/24/2016
//Description:hold all the player class declarations
#include <iostream>
#include "hand.h"
//#include "game.h"

#ifndef _player_h
#define _player_h
using namespace std;

class player{

   private:
      hand p_hand;
      int playing_total;//player bank amount
      int card_total[2];//players sum of cards
      int bet;//players bet
   public:
      player();
      ~player();

      // void set_player(hand , int, int, int);//constructor
      void set_p_hand(const int,const card);//not used
      void set_playing_total(int);
      void set_playing_total_add(int );
      void set_card_total();
      void set_bet(const int);

      hand* get_p_hand();//accessor
      int get_playing_total();//accessor
      int *get_card_total();//accessor
      int get_bet();//accessor
};

#endif


