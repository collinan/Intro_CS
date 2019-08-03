//Program:Black Jack
//File:dealer.cpp
//Name: Andrew Collins
//Date: 4/24/2016
//Description: 
#include <iostream>
#include "dealer.h"

using namespace std;

//Function name:
//Description: default constructor for dealer class
//Pre-condition:
//Post-condition:card totla set to 0
//return:
dealer::dealer():card_total(0)
{
}

//Function name:
//Description: dealer clas destructor
//Pre-condition:
//Post-condition:
//return:

dealer::~dealer(){
}
//Function name:
//Description: return the dealers cards
//Pre-condition:
//Post-condition:
//return:
hand *dealer::get_d_hand(){

   return &d_hand;
}

//Function name:
//Description: add the values of the cards and sets it to card total
//Pre-condition:
//Post-condition:
//return:
void dealer::set_card_total(){

   card_total=0;
   int d_num_cards= d_hand.get_num_cards();

   for(int j=0;j< d_num_cards;j++){

      if(d_hand.get_cards()[j].value<11){
	 card_total+=d_hand.get_cards()[j].value;
      }
      if(d_hand.get_cards()[j].value>10 && d_hand.get_cards()[j].value<14){
	 card_total+=10;
      }
      if(d_hand.get_cards()[j].value==14){
	 card_total+=11;
      }
   }

}

//Function name:
//Description: return the dealer card total
//Pre-condition:
//Post-condition:
//return:
int dealer::get_card_total(){

   return card_total;
}
//Function name:
//Description:resets the dealers card total
//Pre-condition:
//Post-condition:
//return:
void dealer::reset(){
card_total=0;
}
