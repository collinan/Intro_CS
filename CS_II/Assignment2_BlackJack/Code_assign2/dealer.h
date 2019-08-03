//Program: Black Jack
//File: dealer.h
//Name: Andrew Collins
//Date: 4/24/2016
//Description:has all the dealer class prototypes
#include <iostream>
#include "hand.h"
//#include "game.h"
#ifndef _dealer_h
#define _dealer_h

using namespace std;

class dealer{

   private:
      hand d_hand;
      int card_total;
   public:
      dealer();
      ~dealer();
      void set_card_total();
void reset();
      hand *get_d_hand();
      int get_card_total();

};
#endif
