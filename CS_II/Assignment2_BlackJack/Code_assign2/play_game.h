//Program: Black Jack
//File: play_game.h
//Name: Andrew Collins
//Date: 4/24/2016
//Description:hold all the play_game prototypes
#include <iostream>
#include "game.h"
#include "card.h"
#include "deck.h"

#include "hand.h"
#include "player.h"
#include "dealer.h"

using namespace std;
int black_jack_num_players();
bool num_check(string);
void bets(game &);
bool check_bet(int ,int ,game& );//takes player number, int the players bet, game class to access player info
bool check_player_bank(int, game & );//make sure players have money in the bank
void save_player_bet(int, int ,game&);//saves the players bet int- player number, int players bey ,gaem object
void first_deal_cards(game & ,int);
void set_player_card(game&, int);
void set_dealer_card(game &);
void print_table(game &,int);
int value_of_cards(int);
void check_win(game &);
bool check_dealer_blackjack(game &);
bool check_player_blackjack(game &);
void hit_stay(game &);
void dealer_hit_stay(game &);
int check_end();
bool error();
