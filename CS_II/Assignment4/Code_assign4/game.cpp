//Program filename:game.cpp
//Author:Andrew Collins
//Date:5/24/2016
//Description:part of wumpus game, the game function hold all the information about the game
//Input:
//Output:
#include "game.h"

//Description;default constructor
//Pre-conditoin:
//Post-conditon:
//return:
Game::Game():rms(){

}


//Description: destructor
//Pre-conditoin:
//Post-conditon:
//return:
Game::~Game(){

   for(int i=0;i<rows;i++){
      delete []rc[i];
   }
   delete []rc;


   for(int i=0;i<rows;i++){
      delete []precepts[i];
   }
   delete []precepts;

   for(int i=0;i<rows;i++){
      delete []rms[i];
   }
   delete []rms;

}


//Description:non default constructor, sets up game
//Pre-conditoin:row of grid
//Post-conditon:
//return:
Game::Game(int r){
   set_rows(r);
   gold=0;
   arrows=3;
   wumpus_dead=0;
   rms=new Rooms*[rows];
   for(int i=0;i<rows;i++){
      rms[i]= new Rooms[rows];
   }


   //set each room value 0
   rc=new int*[rows];
   for(int i=0;i<rows;i++){
      rc[i]=new int[rows]; 
   }

   int u=0;
   for(int i=0;i<rows;i++){
      for(int j=0;j<rows;j++){
	 rc[i][j]=0;
	 u++;
      }
   }
 //  cout<<u<<endl;

   set_rooms();
}


//Description:if player wants to redo a level this function is called
//and initial values are reset
//Pre-conditoin:
//Post-conditon:
//return:
void Game::reset(){
   arrows=3;
   gold=0;
   wumpus_dead=0;
   rc[gl[0]][gl[1]]=2;
   rc[wl[0]][wl[1]]=1;
   p_loc[0]=start_loc[0];
   p_loc[1]=start_loc[1];
   rms[wl[0]][wl[1]].set_event( e_w );
   rms[gl[0]][gl[1]].set_event( e_g );

}


//Description:set the locatin the player started at, will also be the exit location
//Pre-conditoin:
//Post-conditon:
//return:
void Game::set_start_loc(){
   start_loc[0]=p_loc[0];
   start_loc[1]=p_loc[1];
}


//Description:every time a player shoots an arrow this function take away from the 
//players total number of arrows
//Pre-conditoin:
//Post-conditon:one less arrow
//return:
void Game::set_arrows(){
   arrows--;
}


//Description:if wumpus is killed this function sets 
//wumpus-dead to 1
//Pre-conditoin:wumpus-dead is 0
//Post-conditon:if killed wumpus dead 1
//return:
void Game::set_wumpus_dead(int y_n ){
   wumpus_dead=y_n;
}


//Description:if gold of wumpus event happes sets room event to null
//Pre-conditoin:
//Post-conditon:
//return:
void Game::reset_rms(int r,int c){
   rms[r][c].reset_event();
}


//Description;can change room evnt to 0-no evnt or change room evetn to 
//number corresponding to event
//Pre-conditoin:
//Post-conditon:
//return:
void Game::reset_rc_block(int r,int c,int reset){
   rc[r][c]=reset;
}


//Description:If player finds the gold, gold is added to his total gold
//Pre-conditoin:gold is 0
//Post-conditon:if found gold is 1000
//return:
void Game::set_gold(){
   if(gold==0){
      gold=1000;
   }

}


//Description;set the grid row value passed from cmd line
//Pre-conditoin:
//Post-conditon:
//return:
void Game::set_rows(int r){
   rows=r;
}


//Description:sets the evnts in each room randomly
//Pre-conditoin:
//Post-conditon:
//return:
void Game::set_rooms(){

   for(int i=0;i<rows;i++){
      for(int j=0;j<rows;j++){
	// cout<<rc[i][j]<< "-";;
      }
     // cout<<endl;
   }

   //set the wumpus1
   srand(time(NULL));

   int wr[2];
   wr[0] =rand()%rows;
   wr[1] = rand()%rows;//wumpus room
   wl[0]=wr[0];
   wl[1]=wr[1];

  // cout<< "wumpus room row "<<wr[0]<<" wumpus room column "<<wr[1]<<endl;
   rms[wr[0]][wr[1]].set_event( e_w );
   rc[wr[0]][wr[1]]=1;

   //set gold2

   do{
      gl[0]=rand()%rows;//row
      gl[1]=rand()%rows;//column
   }while(rc[gl[0]][gl[1]]!=0);
   rms[gl[0]][gl[1]].set_event( e_g );
  // cout<< "gold room row "<<gl[0]<<" gold room column "<<gl[1]<<endl;
   rc[gl[0]][gl[1]]=2;


   //set bats 3
   for(int t=0;t<2;t++){
      int br[2];
      do{
	 br[0]=rand()%rows;
	 br[1]=rand()%rows;//wumpus room
      }while((rc[br[0]][br[1]]!=0));
      rc[br[0]][br[1]]=3;
      rms[br[0]][br[1]].set_event( e_b );
     // cout<< t+1<<": bat room row "<<br[0]<<" bat room column "<<br[1]<<endl;
   }


   //set pits4 

   for(int t=0;t<2;t++){
      int pr[2];
      do{
	 pr[0]=rand()%rows;
	 pr[1]=rand()%rows;//wumpus room
      }while((rc[pr[0]][pr[1]]!=0));
      rc[pr[0]][pr[1]]=4;
      rms[pr[0]][pr[1]].set_event(e_p );
     // cout<< t+1<<": pit room row "<<pr[0]<<" bat room column "<<pr[1]<<endl;
   }

   for(int i=0;i<rows;i++){
      for(int j=0;j<rows;j++){
	// cout<<rc[i][j]<< "-";
      }
    //  cout<<endl;
   }
   set_precepts(0);
   set_player_location();
}

//reset wumpus
//Description:if wumpus moves reset old room and set new room
//Pre-conditoin:wumpus old location reset
//Post-conditon:wumpus new location set
//return:
void Game::reset_wumpus(){
  // cout<<"test0"<<endl;
   int r;
 //  cout<<"test1"<<endl;
   int c;
   for(int x=0;x<rows;x++){
      for(int y=0;y<rows;y++){
	 if(rc[x][y]==1){
	    r=x;
	    c=y;
	 }
      }
   }
  // cout<<"test2"<<endl;
   reset_rms(r,c);
  // cout<<"test3"<<endl;
   reset_rc_block(r,c,0);
  // cout<<"test4"<<endl;
   int wr[2];
   do{
      wr[0] =rand()%rows;
      wr[1] = rand()%rows;//wumpus room

   }while((rc[wr[0]][wr[1]]!=0));
  // cout<< "wumpus room row "<<wr[0]<<" wumpus room column "<<wr[1]<<endl;
   rms[wr[0]][wr[1]].set_event( e_w );
   rc[wr[0]][wr[1]]=1;
   set_precepts(1);

}
/////////////////////////////////////
//set percerpts
//Description:sets the precepst for each room
//Pre-conditoin:room precepts empty
//Post-conditon:precepts for room set
//return:
void Game::set_precepts(int first){
 //  cout<<"in"<<endl;
   if(first==1){
    //  cout<<"in"<<endl;
      for(int i=0;i<rows;i++){
	 delete [] precepts[i];
      }
      delete []precepts;
      precepts=NULL;
   }

   precepts=new string*[rows];
   for(int s=0;s<rows;s++)
      precepts[s]=new string[rows];

   for(int i=0;i<rows;i++){
      for(int j=0;j<rows;j++){
	 if(rc[i][j]>0 && rc[i][j]<10){
	    if((i-1)>0 ){
	       precepts[i-1][j]=precepts[i-1][j]+message(rc[i][j]);
	    }
	    if((i+1)<rows ){
	       precepts[i+1][j]=precepts[i+1][j]+message(rc[i][j]);
	    }
	    if((j-1)>0 ){
	       precepts[i][j-1]=precepts[i][j-1]+message(rc[i][j]);
	    }
	    if((j+1)<rows ){
	       precepts[i][j+1]=precepts[i][j+1]+message(rc[i][j]);
	    }
	 }
      }
   }
}

//set players location
//Description:sets the players location randomly
//Pre-conditoin:
//Post-conditon:playes location on grid
//return:
void Game::set_player_location(){
   do{
      p_loc[0]=rand()%rows;
      p_loc[1]=rand()%rows;//wumpus room
   }while((rc[p_loc[0]][p_loc[1]]!=0));
   start_loc[0]=p_loc[0];
   start_loc[1]=p_loc[1];
  // cout<<": player/start room row "<<p_loc[0]<<" player/start room column "<<p_loc[1]<<endl;

}



//Description:precepts for each room returned
//Pre-conditoin:room next to
//Post-conditon:
//return:precept corresponding to room location
string Game::message(int c){
   switch(c){
      case 1: return " You smell a terrible stench.";
      case 2: return " You see glimer nearby. ";
      case 3: return " You hear wings flapping. ";
      case 4: return " You feel a breeze. ";
   }
}


//Description:return the wumpus condition
//Pre-conditoin:
//Post-conditon:
//return:0 if wumpus alive, or 1 if wumpus dead
int Game::get_wumpus_dead( ){
   return wumpus_dead;
}


//Description:return the player gold amount
//Pre-conditoin:
//Post-conditon:
//return:0 if player has no gold else returns gold amount
int Game::get_gold(){
   return gold;
}


//Description:returns the start and end location to win
//Pre-conditoin:
//Post-conditon:
//return:players initial location or finish point
int *Game::get_start_loc(){

   return start_loc;

}


//Description:return the amount of rows in grid
//Pre-conditoin:
//Post-conditon:
//return:rows in grid set by cmd line argument
int Game::get_rows(){
   return rows;

}


//Description:resets the playes location
//Pre-conditoin:playes row and clumn
//Post-conditon:player location updated
//return:
void Game::reset_player_location(int ro, int co){
   p_loc[0]=ro;
   p_loc[1]=co;

}


//Description:gets the players location
//Pre-conditoin:
//Post-conditon:
//return:return the player location on the grid
int *Game::get_player_loc(){

   return p_loc;

}


//Description;returns an arry of precepts corresponding to each room
//Pre-conditoin:
//Post-conditon:
//return:the precents of each room
string **Game::get_precepts(){
   return precepts;
}


//Description;get the cave map which has evnets
//Pre-conditoin:
//Post-conditon:
//return:returns the cave map
int **Game::get_rc(){
   return rc;
}


//Description;return all room and the eventsin them
//Pre-conditoin:
//Post-conditon:
//return:return the room and event
Rooms **Game::get_rms(){

   return rms;
}


//description:returns the number of arrows
int Game::get_arrows(){
   return arrows;
}
