//Program:Black Jack
//File:player.cpp
//Name: Andrew Collins
//Date: 4/24/2016
//Description: hold all the player class def
#include <iostream>
#include "player.h"

using namespace std;

//Function name:
//Descritpiton:player clas default constructor
//Pre-condition:
//Post-condition:
//return:
player::player(): playing_total(1000) , bet(0)
{

   card_total[0]=0;
   card_total[1]=0;
}

//Function name:
//Descritpiton:player destructor
//Pre-condition:
//Post-condition:
//return:
player::~player(){
}


/*Function name:
//Descritpiton:
//Pre-condition:
//Post-condition:
//return:
void player::set_p_hand(const int one_card,const card c){
p_hand.set_num_cards(one_card);
}*/


//Function name:
//Descritpiton:
//Pre-condition:sets the players playing total
//Post-condition:
//return:
void player::set_playing_total(int bet){
//playing_total-=bet;
}


//Function name:
//Descritpiton:if player wins it add the winning to the players total
//Pre-condition:
//Post-condition:
//return:
void player::set_playing_total_add(int winnings){
playing_total+=winnings;
}
//Function name:
//Descritpiton:add all the values of the player cards
//Pre-condition:
//Post-condition:
//return:
void player::set_card_total(){

   card_total[0]=0;
   card_total[1]=0;
   int p_num_cards= p_hand.get_num_cards();
   int num_aces=0;
   for(int i=0;i<p_num_cards;i++){
      if(p_hand.get_cards()[i].value==14){
	 num_aces++;
      }
   }


   for(int j=0;j< p_num_cards;j++){

      if(p_hand.get_cards()[j].value<11){
	 card_total[0]+=p_hand.get_cards()[j].value;
      }
      if(p_hand.get_cards()[j].value>10 && p_hand.get_cards()[j].value<14){
	 card_total[0]+=10;
      }
      if(p_hand.get_cards()[j].value==14){
	 card_total[0]++;
      }
   }

   if(num_aces>0){
      int ace_count=0;
      for(int i=0;i< p_num_cards;i++){

	 if(p_hand.get_cards()[i].value<11){
	    card_total[1]+=p_hand.get_cards()[i].value;
	 }
	 if(p_hand.get_cards()[i].value>10 && p_hand.get_cards()[i].value<14){
	    card_total[1]+=10;
	 }
	 if(p_hand.get_cards()[i].value==14 && ace_count==0 ){
	    card_total[1]+=11;
	    ace_count++;
	 }
	 if(p_hand.get_cards()[i].value==14 && ace_count!=0 ){
	    card_total[1]++;
	 }

      }
   }
}
//Function name:
//Descritpiton:save the players bet
//Pre-condition:
//Post-condition:
//return:
void player::set_bet(const int p_bet){
   bet=p_bet;
playing_total=playing_total-p_bet;
}


//Function name:
//Descritpiton:return the player cards
//Pre-condition:
//Post-condition:
//return:
hand *player::get_p_hand(){
   return &p_hand;
}




//Function name:
//Descritpiton:return the players total money
//Pre-condition:
//Post-condition:
//return:
int player::get_playing_total(){

   return playing_total;
}


//Function name:
//Descritpiton:return the sum of all the cards
//Pre-condition:
//Post-condition:
//return:
int *player::get_card_total(){//accessor

   return card_total;
}


//Function name:
//Descritpiton:returns the players bet
//Pre-condition:
//Post-condition:
//return:
int player::get_bet(){//accessor
   return bet;
}



