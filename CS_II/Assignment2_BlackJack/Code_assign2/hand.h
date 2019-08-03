//Program: Black Jack
//File: hand.h
//Name: Andrew Collins
//Date: 4/24/2016
//Description:has all the hand class prototypes
#include <iostream>
//#include "deck.h"
#include "card.h"
//#include "game.h"
#ifndef _hand_h
#define _hand_h
using namespace std;

class hand{
   private:
      card *cards;
      int num_cards;

   public:
      hand();
      ~hand();

  //    void create_cards();

void add_card(card c); 

    //  void set_card( const card );//sets hand
      void set_num_cards(const int);//sets cards number
      void reset();


      card *get_cards() ;//returns a card
      int get_num_cards();//return num_cards
};
#endif
