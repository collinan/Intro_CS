//Program filename:
//Author:Andrew Collins
//Date:5/24/2016
//Description:
//Input:
//Output:
#include "driver.h"
//Function name:
//Description:
//pre-condition:
//post-condition:
//return:

using namespace std;


//Function name:
//Description:the function akes a char array and check to see if it 
//is a valid positive integer value.
//pre-condition:argv hold any array character value
//post-condition:none
//return:false if value is not a positive integer greater than zero else return true.
bool check_num(char *argv){
   int s_num=strlen(argv);
   for(int i=0;i<s_num;i++){
      if(!(argv[i]>='0' &&argv[i]<='9')||argv[0]=='0'){
	 return false;
      }
   }

   return true;
}


//Description:check to see that valid arguments are passed in 
//pre-condition:argc number of arguments passed, argv arguments
//post-condition:
//return:true if valid arguments
bool check_arguments(int argc , char **argv){
   bool check;
   if(argc !=2){
      invalid_input_error();
      return false;
   }
   else if(check_num(argv[1])==false){

      invalid_input_error();
      return false;
   }
   else if(!(atoi(argv[1])>4 && atoi(argv[1])<=10)){
      invalid_input_error();
      return false;
   }

   return true;
}


//Description:print statement for invalid argumnets
//pre-condition:
//post-condition:
//return:
void invalid_input_error(){
   cout<<"Error: Invalid arguments."<<endl;
   cout<<"Please enter the \"wumpus\" followed by the number of rows. "<<endl;
   cout<<"Rows should be a positive integer greater than 4 and less than equal to 10"<<endl;
}


//Description:prints the game board, all the room and player location 
//and precepts
//pre-condition:allthe game information
//post-condition:
//return:
void print_cave(Game &g){
   int s=g.get_rows();//number of rows in grid
   cout<<endl;
/////////////////////////////////////////////delete
   for(int i=0;i<s;i++){
      for(int j=0;j<s;j++){
	// cout<<g.get_rc()[i][j]<< "-";
      }
    //  cout<<endl;
   }
//////////////////////////////////////////////delete^
   for(int t=0;t<s;t++){//top line, edge of cave
      cout<<"*****";
   }
cout<<endl;
   for(int t=0;t<s-2;t++){//top line, edge of cave
      cout<<"     ";
   }
   cout<<"Gold: "<<g.get_gold();
   cout<<endl;

   for(int t=0;t<s;t++){//top line, edge of cave
      cout<<" ___ ";
   }
   cout<<endl;
   for(int h=0;h<s;h++){
      //cave top walls
      for(int wt=0;wt<s;wt++){  
	 if(g.get_player_loc()[0]==h && g.get_player_loc()[1]==wt){
	    cout<<"|P  |";
	 }else{
	    cout<<"|   |";
	 }
      }
      cout<<endl;
      for(int wm=0;wm<s;wm++){  
	 if(wm==0){
	    cout<<"|    ";
	 }else if(wm==(s-1)){
	    cout<<"    |";
	 }else{
	    cout<<"     ";
	 }
      }
      cout<<endl;
      //cave boottom  wall
      for(int wt=0;wt<s;wt++){  
	 cout<<"|   |";
      }
      cout<<endl;
      if(h<s-1){
	 for(int t=0;t<s;t++){//top line, edge of cave
	    cout<<" _ _ ";
	 }
	 cout<<endl;
      }
   }

   for(int t=0;t<s;t++){//top line, edge of cave
      cout<<" ___ ";
   }
   cout<<endl;
} 
///////////////////////////////////////////////////////////////////////////////////////////////////

//Description:prints the precepts of each room
//pre-condition:all the game information
//post-condition:
//return:
void print_message(Game &g){
   int r=g.get_player_loc()[0];
   int c=g.get_player_loc()[1];
   if(g.get_precepts()[r][c].empty()==false){
      cout<<g.get_precepts()[r][c]<<endl;
   }
}


//Description: this is where all the other function to play
//the game arre called
//pre-condition:all the game information
//post-condition:changed values depending on player moves
//return:return true if game won, else return false
bool start_game(Game &g){
   bool eofg=false;
   bool win =false;
      print_cave(g);
      print_message(g);
      g.set_start_loc();
   do{
      move_player(g);
      eofg=check_new_room(g);
      print_cave(g);
      print_message(g);
     if(eofg==false && g.get_wumpus_dead()==0){ shoot_arrow(g);}
     if(g.get_arrows()==0 && g.get_wumpus_dead()==0){//if you run out off arrows and the wumpus is alive
	cout<<"You ran out of arrows game over"<<endl;
	eofg=true;
     }
     if(g.get_wumpus_dead()==1 && g.get_gold()>0 ){
	if(g.get_start_loc()[0]==g.get_player_loc()[0] && g.get_start_loc()[1]==g.get_player_loc()[1]){
	   cout<<"You win!!."<<endl;
	   eofg=true;
	   win =true;
	}
     }
   }while(eofg==false);

   return win;
}


/////////////////////////////////////////////////////////////////////////////////////////////

//Description:this function is called when player decided to shoot an arrow
//pre-condition:a ll the game info
//post-condition:dependending on the wumpus death, game info chances
//return:
void shoot_arrow(Game &g){
   string shoot;
   string s_d;//shoot direction
   int wr;
   int wc;
   int rows=g.get_rows();
   //find wumpus
   for(int qr=0;qr<g.get_rows();qr++){
      for(int qc=0;qc<g.get_rows();qc++){
	 if(g.get_rc()[qr][qc]==1){
	    wr=qr;
	    wc=qc;
	 }
      }
   }


   do{
      cout<<"Do you want to shoot an arrow (y-yes or n-no)?: ";
      cin>>shoot;
      if(!(shoot.compare("y")==0 || shoot.compare("n")==0)){
	 cout<<"Invalid input"<<endl;
      }
   }while(!(shoot.compare("y")==0 || shoot.compare("n")==0));
   cout<<endl;

   if(shoot.compare("y")==0){
      do{   
	 cout<<"Which way do you want to shoot(w-up, s-down, a-left, d-right)?: ";
	 cin>>s_d;
	 if(!(s_d.compare("w")==0 || s_d.compare("s")==0 || s_d.compare("a")==0 || s_d.compare("d")==0)){
	    cout<<"Invalid input"<<endl;
	 }
      }while(!(s_d.compare("w")==0 || s_d.compare("s")==0 || s_d.compare("a")==0 || s_d.compare("d")==0));


      int r=g.get_player_loc()[0];
      int c=g.get_player_loc()[1];
      bool kill=false;
      for(int x=0;x<3;x++){
	 //up
	 if(s_d.compare("w")==0 ){
	    if((r-1)<0){
	       cout<<"Arrow Out of bounds."<<endl;
	       break;
	    }else{
	       r-=1;
	    }
	    if(r==wr && c==wc){
	       kill=true;
	       break;
	    }
	 }
	 //down
	 if(s_d.compare("s")==0 ){
	    if((r+1)>(rows-1)){
	       cout<<"Arrow Out of bounds."<<endl;
	       break;
	    }else{
	       r+=1;
	    }
	    if(r==wr && c==wc){
	       kill=true;
	       break;
	    }
	 }
	 //left
	 if(s_d.compare("a")==0 ){
	    if((c-1)<0){
	       cout<<"Arrow Out of bounds."<<endl;
	       break;
	    }else{
	       c-=1;
	    }
	    if(r==wr && c==wc){
	       kill=true;
	       break;
	    }
	 }
	 //right
	 if(s_d.compare("d")==0 ){
	    if((c+1)>(rows-1)){
	       cout<<"Arrow Out of bounds."<<endl;
	       break;
	    }else{
	       c+=1;
	    }
	    if(r==wr && c==wc){
	       kill=true;
	       break;
	    }
//cout<<"still in if d-right"<<endl;
	 }
//cout<<"still in for d-right"<<endl;
      }

      if(kill==true){
	 cout<<"You killed the wumpus!!.";
	 if(g.get_gold()==0){
	    cout<<"Get the gold, and"<<endl;
	 }
	 cout<<"Return to start to win game."<<endl;
	 g.reset_rms(r,c);
	 g.reset_rc_block(r,c,0);
	 g.set_precepts(1);
	 g.set_wumpus_dead(1);
      }else{

//	 cout<<"lol"<<endl;

	 g.reset_wumpus();
	 cout<<"You missed."<<endl;
      }
      g.set_arrows();
   }



}
//Description:every time the player enter a new room, this function check to room 
//to see if there is an event or precept
//pre-condition:game information
//post-condition:depending on room event game is changed
//return:true if foom has event
bool check_new_room(Game &g){
   int rows=g.get_rows();
   int r=g.get_player_loc()[0];
   int c=g.get_player_loc()[1];

   if(g.get_rms()[r][c].get_event()!=0){
  //    cout<<"event not null"<<endl;
      g.get_rms()[r][c].get_event()->event();
   }else{
    //  cout<<"event null"<<endl;
   }

   switch(g.get_rc()[r][c]){
      case 1: 	 return true;
      case 2: g.set_gold();
	      g.reset_rms(r,c);
	   //   cout<<"here2"<<endl;
	      g.reset_rc_block(r,c,0);
	      g.set_precepts(1);
	      break;
      case 3: g.reset_player_location(rand()%rows,rand()%rows);//bats move player
	      return check_new_room(g);
      case 4: cout<<" You fell in a pit and died."<<endl;
	      return true;
   }

}


//Description:this function takees care of the players movemt
//pre-condition:players old location
//post-condition:players new location
//return:
void  move_player(Game &g){
   bool valid_move;
   string move;
   do{
      cout<<"Use w,a,s,d to move player(w-up, s-down, a-left, d-right): ";
      cin>>move;
      valid_move=check_valid_move(move,g);
      // cout<<"w- move player up"<<endl;
      //cout<<"s- move player down"<<endl;
      //cout<<"a- move player left"<<endl;
      //cout<<"d- move player right"<<endl;
   }while(valid_move==false);
}


//Description:this function check to see if player is tryion 
//to go off the grid
//pre-condition:
//post-condition:
//return:false if player is moveing off the grid
bool check_valid_move(string move, Game &g ){
   int rows=g.get_rows();
   int r=g.get_player_loc()[0];
   int c=g.get_player_loc()[1];

   if(!(move.compare("w")==0 || move.compare("s")==0 || move.compare("a")==0 || move.compare("d")==0)){
      cout<<"Invalid input"<<endl;
      return false;
   }
   if(move.compare("w")==0 ){
      if((r-1)<0){
	 cout<<"Out of bounds."<<endl;
	 return false;
      } 
      g.reset_player_location((r-1),c);
   }
   if( move.compare("s")==0 ){
      if((r+1)>(rows-1)){
	 cout<<"Out of bounds."<<endl;
	 return false;
      } 
      g.reset_player_location((r+1),c);
   }
   if(move.compare("a")==0){
      if((c-1)<0){
	 cout<<"Out of bounds."<<endl;
	 return false;
      } 
      g.reset_player_location(r,(c-1));
   }
   if(move.compare("d")==0){
      if((c+1)>(rows-1)){
	 cout<<"Out of bounds."<<endl;
	 return false;
      } 
      g.reset_player_location(r,(c+1));
   }
   return true;
}

//Function name:
//Description:
//pre-condition:
//post-condition:
//return:
