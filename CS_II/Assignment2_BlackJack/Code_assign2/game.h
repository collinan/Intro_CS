//Program: Black Jack
//File: game.h
//Name: Andrew Collins
//Date: 4/24/2016
//Description:has all the game class prototypes
#include <iostream>
#include <string>
//#include "card.h"
#include "deck.h"
//#include "hand.h"
#include "player.h"
#include "dealer.h"

using namespace std;

class game{

   private:
      deck cards;
      player *players;
      dealer game_dealer;
      int num_players;


   public:
      game();
      ~game();

      void set_num_players(int);
      void set_players();


      player* get_players();
      dealer* get_game_dealer();
      int get_num_players();
      deck* get_deck();


};
