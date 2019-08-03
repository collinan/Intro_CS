//Program: Black Jack
//File: play_game.cpp
//Name: Andrew Collins
//Date: 4/24/2016
//Description:this is the bvrain of the game this is where all the logic takes place
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include "play_game.h"


using namespace std;

int main(){
   int num_players=0;


   int end_game=0;

   //loop to play roun and repeat
   do{

      game g;
      num_players=black_jack_num_players();//gets number of players from user
      g.set_num_players(num_players);//set the number of players in game class
      end_game=0;
      bets(g);//sets the players bets
      first_deal_cards(g,num_players);
      print_table(g,1);
      if(check_dealer_blackjack(g)==false){
	 check_player_blackjack(g);
	 hit_stay(g);
	 dealer_hit_stay(g);
	 check_win(g);
	 // print_table(g,2);
      }

      end_game=check_end();
   } while(end_game==1);




   return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function name:
//Description: user decides to continue playing
//return:return 1 if user wants to play again else 2
int check_end(){

   string c;
   int num=0;
   bool check=false;

   do{
      cout<<"Do you want to: "<<endl;
      cout<<"1- contine playing"<<endl;
      cout<<"2- end program"<<endl;
      cout<<":";
      cin>>c;
      check=num_check(c);
      if(check==true){
	 num=atoi(c.c_str());
	 check=(num==1 || num ==2)? true:error();
      }
   }while(check== false);

   return num;
}
/////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function name:
//Description: gets the number of players from the user
//return:return the number of player to main
int black_jack_num_players(){

   string number_of_players;
   int num_players=0;
   bool check_number=false;
   do{
      cout<<"Enter the number of players (1-6): ";
      cin>>number_of_players;

      check_number=num_check(number_of_players);
      if(check_number==true){
	 num_players=atoi(number_of_players.c_str());
	 if(num_players>6){
	    cout<<"Cannot have more than 6 player."<<endl;
	    check_number=false;
	 }
      }
   }while(check_number==false);

   return num_players;
}
//
//
//////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function name:
//Description: check if the user entered a valid number,= positive integer
//Pre-condition:user input
//Post-condition:
//return:ture if valid input else false
bool num_check(string n){
   int str_size=n.length();

   if(n[0]=='0'){
      cout<<"Error: Invalid input."<<endl;
      cout<<endl;
      cout<<endl;
      return false;
   }
   for(int i=0;i<str_size;i++){
      if(!(n[i]>='0' && n[i]<='9')){
	 cout<<"Error: Invalid input."<<endl;
	 cout<<endl;
	 cout<<endl;
	 return false;
      }
   }

   return true;
}
//
//
//////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function name:
//Description: //get the players bet
//Pre-condition:game object to store players bets
//Post-condition:
void bets(game & game_obj){//gg is game object

   for(int x=0;x<game_obj.get_num_players();x++){

      int p_bet=0;
      if(check_player_bank(x,game_obj)==true){//check to see if player has any money to bet. else skips player

	 string bets;
	 bool check_bets=false;
	 do{
	    cout<<endl;
	    cout<<"Player "<<x+1<<" enter your bet (even numbers only,2-1000):";
	    cin>>bets;

	    check_bets=num_check(bets);//check to see if the bet is a valid pos integer
	    if(check_bets==true){
	       p_bet=atoi(bets.c_str());
	       check_bets= check_bet(x,p_bet, game_obj) ;
	       check_bets= p_bet%2==0? true: error() ;
	    }
	 }while(check_bets==false);
	 save_player_bet( x, p_bet, game_obj);

      }
   }
}
//
//
//////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function name:
//Description: make sure the user enters avalid bet amount that is less than the total 
//money they have.
//Pre-condition:player entering bet, their bet ,game obj
//Post-condition:
//return:ture if valid bet
bool check_bet(int player_num,int bet,game &ggg){
   // player **players= ggg.get_players();
   if(bet>ggg.get_players()[player_num].get_playing_total()){
      cout<<endl;
      cout<<"--Error: Your bet is greater than the amount of money you have."<<endl;
      cout<<"Please enter a bet that is less than or equal to the amount of money you have.--"<<endl;
      cout<<endl;
      return false;
   }

   return true;
}
//
//
//////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function name:
//Description: check to see if player has money to play game
//Pre-condition:
//Post-condition:
//return:
bool check_player_bank(int p_num ,game &g){

   if(g.get_players()[p_num].get_playing_total()<10){
      cout<<"Player "<<p_num+1<<" you do not have enough money to play at this table"<<endl;
      return false;
   }
   return true;
}
//
//
//////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function name:
//Description: sets the players bet
//Pre-condition:player number, players bet, game obj
//Post-condition:game obj has players bet
//return:
void save_player_bet(int p_num,int p_bet, game &g){
   g.get_players()[p_num].set_bet(p_bet);
   g.get_players()[p_num].set_playing_total(p_bet);

   cout<<"Players "<<p_num+1<<" bet:"<<g.get_players()[p_num].get_bet()<<endl;

}
//
//
//////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function name:
//Description: deals initial 2 card to each player and dealer
//Pre-condition:game obj,and number of players
//Post-condition:game obj, holds player cards
//return:
void first_deal_cards(game & g, int num_p){
   player *p_obj_array=g.get_players();

   for(int two=0;two<2;two++){
      for(int p_n=0;p_n<num_p;p_n++){
	 if(p_obj_array[p_n].get_bet()>0){//if the player has abet give him a card
	    set_player_card(g,p_n);
	 }
      }
      set_dealer_card(g);
   }
}
//
//
//////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function name:
//Description: sets a players card
//Pre-condition:game obj ,and player getting a card
//Post-condition: adds a card to game obj
//return:
void set_player_card(game &g,int player_num){
   g.get_players()[player_num].get_p_hand()->add_card(g.get_deck()->get_card());
   g.get_players()[player_num].set_card_total();

}
//
//
//////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function name:
//Description: gives dealer a card
//Pre-condition:game obj, 
//Post-condition:adds card to dealer in game obj
//return:
void set_dealer_card(game &g){
   g.get_game_dealer()->get_d_hand()->add_card(g.get_deck()->get_card());
   g.get_game_dealer()->set_card_total();
}
//
//
//////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function name:
//Description: return the value of a card J,Q,K=10 A=11
//Pre-condition:get the card number
//Post-condition:
//return:return converted value 
int value_of_cards(int c_value){

   if(c_value<=10){
      return c_value;
   }else if(c_value>10 && c_value<14){
      return 10;
   }else if(c_value==14){
      return 11;
   }
}


/////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function name:
//Description:print the black jack table with dealer and players info 
//Pre-condition:get all player and dealers info g, z-if all player are done z=2 else z=1
//Post-condition:
//return:
void print_table(game &g,int z){
   cout<<endl;
   cout<<endl;
   cout<<endl;
   int q=0;
   if(z==1){
      q=1;
   }
   if(z!=1){
      q=g.get_game_dealer()->get_d_hand()->get_num_cards();
   }
   for(int n=0;n<((24*(g.get_num_players()-1))/2);n++)
      cout<<" ";
   cout<<"Dealer"<<endl;
   for(int i=0;i<q;i++){
      for(int n=0;n<((24*(g.get_num_players()-1))/2);n++)
	 cout<<" ";
      cout<<"Card "<<q+1<<":";


      //card value
      if((g.get_game_dealer()->get_d_hand()->get_cards()[i].value) < 10){
	 cout<<g.get_game_dealer()->get_d_hand()->get_cards()[i].value<<"  ";
      }
      if(g.get_game_dealer()->get_d_hand()->get_cards()[i].value==10){
	 cout<<g.get_game_dealer()->get_d_hand()->get_cards()[i].value<<" ";
      }
      if(g.get_game_dealer()->get_d_hand()->get_cards()[i].value>10){
	 if(g.get_game_dealer()->get_d_hand()->get_cards()[i].value==11){
	    cout<<"J  ";
	 }
	 if(g.get_game_dealer()->get_d_hand()->get_cards()[i].value==12){
	    cout<<"Q  ";
	 }
	 if(g.get_game_dealer()->get_d_hand()->get_cards()[i].value==13){
	    cout<<"K  ";
	 }
	 if(g.get_game_dealer()->get_d_hand()->get_cards()[i].value==14){
	    cout<<"A  ";
	 }
      }
      //card suit
      if(g.get_game_dealer()->get_d_hand()->get_cards()[i].suit==1){
	 cout<<"D ";
      }else if(g.get_game_dealer()->get_d_hand()->get_cards()[i].suit==2){
	 cout<<"H ";
      }else if(g.get_game_dealer()->get_d_hand()->get_cards()[i].suit==3){
	 cout<<"S ";
      }else if(g.get_game_dealer()->get_d_hand()->get_cards()[i].suit==4){
	 cout<<"C ";
      }
      cout<<endl;
   }
      for(int n=0;n<((24*(g.get_num_players()-1))/2);n++)
	 cout<<" ";

      if(q==1){
	 cout<<"Cards total: "<<value_of_cards( g.get_game_dealer()->get_d_hand()->get_cards()[0].value);
      }else{

	 cout<<"Card Total: "<<g.get_game_dealer()->get_card_total()<<" ";
      }

   cout<<endl;
   cout<<endl;
   cout<<endl;


   /////////////////////////////////////////////////////////////////////////////////////////////

   int num_pp=g.get_num_players();
   //players number
   for(int p=0;p<num_pp;p++){
      //cout<<"Player "<<p+1<<" -+-+-+-******";
      cout<<"Player "<<p+1<<"               ";
      //cout<<"Player "<<p+1<<"************* ";
   }
   cout<<endl;
   //
   int max_p_cards=0;
   for(int pp=0;pp<num_pp-1;pp++){
      if(max_p_cards<g.get_players()[pp].get_p_hand()->get_num_cards())
	 max_p_cards=g.get_players()[pp].get_p_hand()->get_num_cards();
   }
   ///////////////////////////////////////////////////////////////////////////////////////////////////////////
   for(int c=0;c<max_p_cards;c++){
      for(int p=0;p<num_pp;p++){

	 if(c<=9){
	    cout<<"Card "<<c+1<<": ";
	 }else{
	    cout<<"Card "<<c+1<<": ";
	 }

	 if(g.get_players()[p].get_p_hand()->get_num_cards()>c){
	    //card value
	    if((g.get_players()[p].get_p_hand()->get_cards()[c].value) < 10){
	       cout<<g.get_players()[p].get_p_hand()->get_cards()[c].value<<"  ";
	    }
	    if(g.get_players()[p].get_p_hand()->get_cards()[c].value==10){
	       cout<<g.get_players()[p].get_p_hand()->get_cards()[c].value<<" ";
	    }
	    if(g.get_players()[p].get_p_hand()->get_cards()[c].value>10){
	       if(g.get_players()[p].get_p_hand()->get_cards()[c].value==11){
		  cout<<"J  ";
	       }
	       if(g.get_players()[p].get_p_hand()->get_cards()[c].value==12){
		  cout<<"Q  ";
	       }
	       if(g.get_players()[p].get_p_hand()->get_cards()[c].value==13){
		  cout<<"K  ";
	       }
	       if(g.get_players()[p].get_p_hand()->get_cards()[c].value==14){
		  cout<<"A  ";
	       }
	    }
	    //card suit
	    if(g.get_players()[p].get_p_hand()->get_cards()[c].suit==1){
	       cout<<"D ";
	       cout<<"          ";
	    }else if(g.get_players()[p].get_p_hand()->get_cards()[c].suit==2){
	       cout<<"H ";
	       cout<<"          ";
	    }else if(g.get_players()[p].get_p_hand()->get_cards()[c].suit==3){
	       cout<<"S ";
	       cout<<"          ";
	    }else if(g.get_players()[p].get_p_hand()->get_cards()[c].suit==4){
	       cout<<"C ";
	       cout<<"          ";
	    }
	 }else{
	    cout<<"                ";
	 }
      }

      cout<<endl;
   }
   ///////////////////////////////////////////////////////////////////////////////////////////////////////////
   for(int p=0;p<num_pp;p++){
      if(g.get_players()[p].get_bet()<10){
	 cout<<"Bet: "<<g.get_players()[p].get_bet()<<"                 ";
      }
      if(g.get_players()[p].get_bet()>=10 && g.get_players()[p].get_bet()<100){
	 cout<<"Bet: "<<g.get_players()[p].get_bet()<<"                ";
      }
      if(g.get_players()[p].get_bet()>=100 && g.get_players()[p].get_bet()<1000){
	 cout<<"Bet: "<<g.get_players()[p].get_bet()<<"               ";
      }
      if(g.get_players()[p].get_bet()>=100 && g.get_players()[p].get_bet()>=1000){
	 cout<<"Bet: "<<g.get_players()[p].get_bet()<<"              ";
      }
   }
   cout<<endl;
   ///////////////////////////////////////////////////////////////////////////////////////////////////////////
   for(int p=0;p<num_pp;p++){
      if(g.get_players()[p].get_playing_total()<10){
	 cout<<"Bank: "<<g.get_players()[p].get_playing_total()<<"                ";
      }
      if(g.get_players()[p].get_playing_total()>=10 && g.get_players()[p].get_playing_total()<100){
	 cout<<"Bank: "<<g.get_players()[p].get_playing_total()<<"               ";
      }
      if(g.get_players()[p].get_playing_total()>=100 && g.get_players()[p].get_playing_total()<1000){
	 cout<<"Bank: "<<g.get_players()[p].get_playing_total()<<"              ";
      }
      if(g.get_players()[p].get_playing_total()>=100 && g.get_players()[p].get_playing_total()>=1000){
	 cout<<"Bank: "<<g.get_players()[p].get_playing_total()<<"             ";
      }
   }
   cout<<endl;

   ///////////////////////////////////////////////////////////////////////////////////////////////////////////
   for(int p=0;p<num_pp;p++){
      bool has_ace=false;
      for(int n=0;n<g.get_players()[p].get_p_hand()->get_num_cards();n++){
	 if(g.get_players()[p].get_p_hand()->get_cards()[n].value==14){
	    has_ace=true;
	 }
      }

      if(g.get_players()[p].get_card_total()[0] <10){
	 cout<<"Card Total: "<<g.get_players()[p].get_card_total()[0]<<" ";
      }
      if(g.get_players()[p].get_card_total()[0] >=10){
	 cout<<"Card Total: "<<g.get_players()[p].get_card_total()[0];
      }
      if(has_ace==true){
	 cout<<" or "<<g.get_players()[p].get_card_total()[1]<<"   ";
      }else{
	 cout<<"         ";

      }

   }
   cout<<endl;

   cout<< "///////////////////////////////////////////////////////////////////////////////////////"<<endl;
}
//
//
//////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function name:
//Description: during first round check to see if dealer has black jack and round ends
//Pre-condition:
//Post-condition:
//return:true if dealer has blackjack
bool check_dealer_blackjack(game &g){
   int d_num = g.get_game_dealer()->get_card_total();
   if(g.get_game_dealer()->get_card_total()==21){
      cout<<"Dealer has BLACK JACK."<<endl;

      for(int p=0;p<g.get_num_players();p++){
	 int p_num=  g.get_players()[p].get_card_total()[1];
	 int p_bet=g.get_players()[p].get_bet();
	 if(d_num==p_num){
	    g.get_players()[p].set_playing_total_add(p_bet);
	    cout<<"Player Push"<<endl;
	    g.get_players()[p].set_bet(0);
	 }else{
	    cout<<"Player loose"<<endl;
	    g.get_players()[p].set_bet(0);
	 }
      }
      return true;
   }
   return false;
}


/////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function name:
//Description: during first round checks to see if player has black jack
//Pre-condition:
//Post-condition:
//return:
bool check_player_blackjack(game &g){

   for(int p=0;p<g.get_num_players();p++){

      int p_bet=g.get_players()[p].get_bet();
      int p_sum_two=  g.get_players()[p].get_card_total()[1];
      if(p_sum_two==21){
	 cout<<"Player "<< p+1 <<" has BLACK JACK."<<endl;
	 g.get_players()[p].set_playing_total_add((p_bet*2)+(p_bet/2));
	 g.get_players()[p].set_bet(0);
      }

   }

}

/////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function name:
//Description: checks to see if players are looser or winners
//Pre-condition:all players information
//Post-condition:
//return:
void check_win(game &g){
   int d_sum = g.get_game_dealer()->get_card_total();
   cout<<endl;
   cout<<endl;
   cout<<endl;

   for(int p=0;p<g.get_num_players();p++){
      int p_sum_one =  g.get_players()[p].get_card_total()[0];
      int p_sum_two=  g.get_players()[p].get_card_total()[1];
      int p_bet=g.get_players()[p].get_bet();

      if(p_sum_one>21){
	 cout<<"Player " <<p+1<<" you loose."<<endl;
	 g.get_players()[p].set_bet(0);
      } else if(d_sum==p_sum_one || d_sum==p_sum_two){
	 cout<<"Player " <<p+1<<" you push."<<endl;
	 g.get_players()[p].set_playing_total_add(p_bet);
      }else if(d_sum <=21 && d_sum > p_sum_one && d_sum > p_sum_two){
	 cout<<"Player " <<p+1<<" you loose."<<endl;
	 g.get_players()[p].set_bet(0);
      }else if(d_sum>21 && p_sum_one <21 ){
	 cout<<"Player " <<p+1<<" you win."<<endl;
	 g.get_players()[p].set_playing_total_add(p_bet*2);
      }else{
	 cout<<"Player " <<p+1<<" you win."<<endl;
	 g.get_players()[p].set_playing_total_add(p_bet*2);
      }
   }
}


/////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function name:
//Description: this function lets the dealer get a card
//Pre-condition:
//Post-condition:
//return:
void hit_stay(game &g){
   string c;//hold players choice 1 hit 2 stay
   int ch=0;
   for(int p=0;p<g.get_num_players();p++){

      print_table(g,1);
      if(g.get_players()[p].get_bet()>0){

	 bool choice=false;
	 do{

	    do{
	       cout<<endl;
	       cout<<"Player "<<p+1<<" do you want to Hit or Stay (1-HIT 2-STAY): ";
	       cin>>c;

	       choice=num_check(c);//check to see if the bet is a valid pos integer
	       if(choice==true){
		  ch=atoi(c.c_str());
		  choice=(ch==1 || ch==2) ? true:error();
	       }
	    }while(choice==false);

	    if(ch ==1){
	       g.get_players()[p].get_p_hand()->add_card(g.get_deck()->get_card());

	       g.get_players()[p].set_card_total();
	    }

	    print_table(g,1);
	    if(g.get_players()[p].get_card_total()[0]>21){
	       ch=2;
	       cout<<"Player " <<p+1<<" you busted."<<endl;
	    }
	 }while( ch!=2);



      }

   }

}
/////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function name:
//Description: this function lets the dealer get cards till his total is >17 or till not bust
//Pre-condition:dealers card info
//Post-condition:
//return:
void dealer_hit_stay(game &g){
   do{ 

      if( g.get_game_dealer()->get_card_total()>=17){

	 break;
      }
      g.get_game_dealer()->get_d_hand()->add_card(g.get_deck()->get_card());
      g.get_game_dealer()->set_card_total();
      if( g.get_game_dealer()->get_card_total()>21){
	 cout<<"Dealer bust."<<endl;
      }

      print_table(g,2);
   }while( g.get_game_dealer()->get_card_total()<18);



}
/////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function name:
//Description: thus function just returns error if user enters invalid input
//Pre-condition:
//Post-condition:
//return:
bool error(){
   cout<<"Error: Invalid input."<<endl;
   return false;


}



