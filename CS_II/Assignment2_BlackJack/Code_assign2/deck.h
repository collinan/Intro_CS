//Program: Black Jack
//File:deck.h
//Name: Andrew Collins
//Date: 4/24/2016
//Description:has all the deck clas prototypes
#include <iostream>
#include <string>

#include "card.h"
//#include "game.h"
#ifndef _deck_h
#define _deck_h
using namespace std;

class deck{
   private: 
      card cards[52];
      int num_cards;
   public:
      deck();//initializes deck--
      ~deck();//destructor-

      void set_deck();//shuffles deck-
      card *get_deck();//returns shuffled desk--
      void reset();

      void set_num_cards(int );
      int get_num_cards();//returns number of cards
      card get_card();
};
#endif
