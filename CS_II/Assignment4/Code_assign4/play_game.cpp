//Program filename:play_game.cpp
//Author:Andrew Collins
//Date:5/24/2016
//Description:main file for wumpus game
//Input:the number of rows in grid
//Output:
#include <iostream>
#include "game.h"
#include "driver.h"
#include "game.h"
using namespace std;

//description;this the main function pf wumpus game
//precondition:gets the number of arguments and the number of rows in grid
//post-condition;
//return
int main (int argc, char* argv[]){
//check to seed enough arguments are passed
   if (check_arguments(argc,argv)==false){
      return 0;
   }

   int rows=atoi(argv[1]);
   bool game_condition;//fale keep playing trur endgame
   bool win_lose;//true if player wins
   string p;//player option to replay game, start new game, end game
   bool c_p;//check player pick
   do{//end game loop
      Game g(rows);//set up game obj
      start_game(g);//starts game
      do{//repete game loop
	 do{//check game option loop
	    cout<<endl;
	    cout<<endl;
	    cout<<"Do you want to,s-play same game again,n-play new game, e-end game?:";
	    cin>>p;
	    c_p=(p.compare("s")==0||p.compare("n")==0||p.compare("e")==0)?true:false;
	    if(c_p==false){cout<<"Invalid input"<<endl;}
	 }while(c_p==false);//loop sif playe wants to redo level
	 if(p.compare("s")==0){
	    g.reset();
	    start_game(g);
	 }
      }while(p.compare("s")==0);//end if player wants new game of quit game


   }while(game_condition==false && p.compare("e")!=0 ); //loop till player wants to end game





   /*
      cout<<"===================================="<<endl;
      for(int i=0;i<rows;i++){
      for(int j=0;j<rows;j++){
      cout<< "i-"<<i<<" j-"<<j<<"|*|";
      }
      cout<<endl;
      }
      cout<<endl;
      */
   return 0;
}

