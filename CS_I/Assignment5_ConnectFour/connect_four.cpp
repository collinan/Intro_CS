//Program name:connect_four.cpp
//Author: Andrew Collin
//Date:21 NOV 2015
//Description:this program is a version of the game connect four. a users will define a grid and the 
//number of pieces to connect. This game can be one player, user vs computer, or two player, usere vs user.
//the point of the game is to drop different color pieces into a grid and the first one to connect x( user defined connect)
//number of same color pieces, wins the game.The user will define the size of the grid, ex: 4x4 6x8 , 
//I have made the conditions: rows and colums have to be greater than 3, and also pieces to connect has to be greater than 3.
//this is because if the pieces to connect is 2 player one will easily win.
//since the connect piecses has to be greater than 3 the grid has to refelt this so row and colums must be greter than 3.
//The program will handle bad input by printing the word error and as the question again.
//to play one player the user must enter the command: ./connect_four -a , where the "-a" is the sesond argument of the command that 
//tells the proram to run the program as one player. for two player the command should only have one argument ex: a.out or ./connect_four.
//If a user enters a bad command the program will let them know of it and end the program.
//Input:
//int arg- holds a pos integer num, the number of argumnets passdd to the program. should be 1 or 2 
//char *arg[]- hold the pointer actul arguments, point to c type string or array of char, arry size should only be[1] or [2], 
//Output:the game
#include<iostream>
#include<iomanip>
#include<string>
#include<cstdlib>
#include<cstring>
using namespace std;
int again();
int num_players(int argc,char **arg);
void game_info(int &row_num,int &column_num,int &pieces_to_connect,char *&player_one_color,char *&player_two_color);
void board_size(int &row_num, int &column_num);
void get_row_num(int &row_num);
void get_column_num(int &column_num);
void get_pieces_to_connect(int &pieces_to_connect,int row_num,int column_num);
void block_array(int row_num,int column_num,char **&blocks);
void fill_blocks(int row_num,int column_num,char **blocks);
void print_board(int row_num, int column_num,char **blocks);
void print_line(int spaces);
void print_numbersOfColumn(int column_num);
void get_player_color(char *&player_one_color,char *&player_two_color);


bool checkcolor(string getcolor);
bool checknum(string number);
bool error();

void OnePlayer(int row_num,int column_num,int pieces_to_connect,char **blocks,char *player1_color,char *player2_color);
void computer_or_user( int row_num,int column_num,int pieces_to_connect,char **blocks,int playerNUM,char player_color);
void computer_drop_piece(int row_num,int column_num,char **blocks,char player_color,int playerNum);
bool check_user_fill_block(int row_num,int column_num,int user_column_num, char **blocks,char plyr_color);
void PlayGame(int row_num,int column_num,int pieces_to_connect,char **blocks,char *player1_color,char *player2_color);
void user_drop_piece(int row_num,int column_num,char **blocks,char player_color,int playerNum);
bool check_user_column(int column_num, int user_col_num);
int getplayercolumn(int coulmn_num,int playerNum);

bool check_win(int row_num,int column_num,char **blocks,int pieces_to_connect,char player_color,int player_num);
bool check_full_board(int row_num,int column_num,char **blocks);
bool check_win_horizontal(int row_num,int column_num,char **blocks,int pieces_to_connect,char plyr_color,int player_num);
bool check_win_vertical(int row_num,int column_num,char **blocks,int pieces_to_connect,char plyr_color,int player_num);
bool check_win_diagonal_up(int row_num,int column_num,char **blocks,int pieces_to_connect,char plyr_color,int player_num);
bool check_win_diagonal_down(int row_num,int column_num,char **blocks,int pieces_to_connect,char plyr_color,int player_num);
//
//
//Function name:main()
//Description:main function for program connet_four.cpp, gets passed 2 parametre, argc and arg[]. 
//the function has a loop that exectures once to play game then asks user to if they want to play the game again. 
//Precondition:
//int arg- holds a pos integer num, the number of argumnets passdd to the program. should be 1 or 2 
//char *arg[]- hold the pointer actul arguments, point to c type string or array of char, arry size should only be[1] or [2], 
//possible argumnet, ./connect_four or a.out (2 player), ./connect_four -a (one player vs computer),
//Postcondition:none
//return:returns 0 to end program
int main(int argc, char *arg[]){//argc- argumnet count(1) or number of arguments pass from command line,arg[]-2d array holds arguments being passed (number of players
   int row_num,column_num,pieces_to_connect,num_of_player=num_players(argc,arg);//these hold the games options
   char **blocks,*player1_color,*player2_color;//hold the game options and user color options
   do{
      game_info(row_num,column_num,pieces_to_connect,player1_color,player2_color);//function to get game setup
      block_array(row_num,column_num,blocks);//creates 2 d array type char
      //  fill_blocks(row_num,column_num,blocks);//fill 2 d array with ' '
      if(num_of_player==2)//2 player game
	 PlayGame(row_num,column_num,pieces_to_connect,blocks,player1_color,player2_color);//funtion for two player
      else   //one player game
	 OnePlayer(row_num,column_num,pieces_to_connect,blocks,player1_color,player2_color);//function for one plaier
   }while(again()==1);//end if player dosnt want to playe again

   return 0;//progra ends
}
//Function name:again()
//Description: this functions askes the user if the want to play the game again.
//Precondition:none
//Postcondition:none
//return:return 0 if player dosn't want to play the game, aging else return 1 to playe game again. (integer whole number) 
int again(){
   string yes_or_no;
   bool Goodnum;
   do{
      cout<<"You want to playe again (0-no, 1-yes)?: ";
      getline(cin,yes_or_no);

      Goodnum= yes_or_no.length()>0? checknum(yes_or_no):false;
      Goodnum=((Goodnum==true) && (atoi(yes_or_no.c_str())==1 || atoi(yes_or_no.c_str())==0)) ? true:error();
   }while(Goodnum==false);
   return atoi(yes_or_no.c_str());
}
///Function name:num_players()
//Description:this function gets passed the argument passed by the user on the command line, then it checks if they r valid
//and if they correspond to a one player game or two player game.
//Precondition:
//int arg- holds the number of argumnets being passed from the commend line( 1 or 2)
//char **arg- c style string array pointe that points to the actual argumnets, ex:good: ./connect_four , ./connect_four -a ,a.out
//Postcondition:none
//return:passes the game type to main (integer whole number),1 for one player game ; 2 for 2 player game 
int num_players(int argc,char **arg){

   if(argc>2){
      cout<<"Too many arguments passed to program!!!!!!!."<<endl;
      exit(0);
   }
   if(argc==2)
      if(!(arg[1][0]=='-' && arg[1][1]=='a')){
	 cout<<"Argument 2 to program unknown (-a for 1 player).!!!!!"<<endl;
	 exit(0);
      }else{return 1;}

   //cout<< "argc: "<<argc<<" arg length: "<<strlen(arg)<<endl;
   return 2;
}
//Function name:game_info
//Description:this function is used to call other function that get the game set up from the user.
//Precondition:
//int &row_num- will hold the number of row for the board, integer whole number greater than 3 less than 25. passed by referance
//int &column_num-will hold the number of columns for the board, integer whole number greater than 3 less than 40. passed by regerance
//int &pieces_to_connect- will hold the number of pieces to connect ex connect four will hold 4 pieces to connect. passed by referance
//char *&player_one_color- will point to the color of player one red (r) or yellow(y)
//char *&player_two_color- will point to the color of player two red (r) or yellow(y)
//Postcondition:
//int &row_num-  hold the number of row for the board, integer whole number greater than 3 less than 25
//int &column_num- hold the number of columns for the board, integer whole number greater than 3 less than 40
//int &pieces_to_connect- hold the number of pieces to connect ex connect four will hold 4 pieces to connect
//char *&player_one_color- point to the color of player one red (r) or yellow(y)
//char *&player_two_color- point to the color of player two red (r) or yellow(y)
//return:none
void game_info(int &row_num,int &column_num,int &pieces_to_connect,char *&player_one_color,char *&player_two_color){

   board_size(row_num,column_num);//function will get ROW x COLUMN of game board from user
   get_pieces_to_connect(pieces_to_connect,row_num,column_num);//will get the number of piece to connect, from user, to win game
   get_player_color(player_one_color,player_two_color);//will get the player one color choice, the based on that will assing a color to player 2
}
//
//Function name:error()
//Description:this function print "Error" when called and returns false, usualll called when user
//enters bad input, of game condition in broken
//Precondition:none
//Postcondition:none
//return:return bool value false
bool error(){
   cout<<"Error"<<endl;
   return false;
}
//
//Function name:board_size()
//Description:This function will get the ROW x COLUMN form user for the game board
//Precondition:
//int &row_num- will hold the number of row for the board, integer whole number greater than 3 less than 25. passed by referance
//int &column_num-will hold the number of columns for the board, integer whole number greater than 3 less than 40. passed by regerance
//Postcondition:
//int &row_num-  hold the number of row for the board, integer whole number greater than 3 less than 25
//int &column_num- hold the number of columns for the board, integer whole number greater than 3 less than 40
//return: none
void board_size(int &row_num, int &column_num){

   get_row_num(row_num);
   get_column_num(column_num);
}
//
//Function name:get_row_num()
//Description:Gets and checks the user input for number of rows, has to be >= 3 and <=25. so it fits on screen
//Precondition:
//int &row_num- will hold the number of row for the board, integer whole number greater than 3 less than 25. passed by referance
//Postcondition:
//int &row_num-  hold the number of row for the board, integer whole number greater than 3 less than 25
//return:none
void get_row_num(int &row_num){
   string rnum;
   bool Goodnum;   
   do{
      cout<<"Enter number of rows(3 <=number <= 25): ";//row number greater than three and less than 25 so it fits on screen
      getline(cin,rnum);
      Goodnum= rnum.length()>0? checknum(rnum):false;
      Goodnum=((Goodnum==true)&&(atoi(rnum.c_str())>=3 && atoi(rnum.c_str())<=25))?true:error();
   }while(Goodnum==false);
   row_num=atoi(rnum.c_str());
}

//Function name:get_column_num
//Description:Gets and checks the user input for number of columns, has to be >= 3 and <=40. so it fits on screen
//Precondition:
//int &column_num-will hold the number of columns for the board, integer whole number greater than 3 less than 40. passed by regerance
//Postcondition:
//int &column_num- hold the number of columns for the board, integer whole number greater than 3 less than 40
//return:none
void get_column_num(int &column_num){
   string cnum;
   bool Goodnum;   
   do{
      cout<<"Enter number of columns(3 <= number <= 40): ";//column number greater than three and less than 40 so it fits on screen
      getline(cin,cnum);
      Goodnum= cnum.length()>0? checknum(cnum):false;
      Goodnum=((Goodnum==true) && (atoi(cnum.c_str())>=3 && atoi(cnum.c_str())<=40)) ?true:error();
   }while(Goodnum==false);
   column_num=atoi(cnum.c_str());
}
//Function name:get_pieces_to_connect()
//Description:
//Precondition:
//int &pieces_to_connect- will hold the number of pieces to connect ex connect four will hold 4 pieces to connect. passed by referance
//int row_num-  hold the number of row for the board, integer whole number greater than 3 less than 25
//int column_num- hold the number of columns for the board, integer whole number greater than 3 less than 40
//Postcondition:
//int row_num-  hold the number of row for the board, integer whole number greater than 3 less than 25
//int column_num- hold the number of columns for the board, integer whole number greater than 3 less than 40
//int &pieces_to_connect- hold the number of pieces to connect ex connect four will hold 4 pieces to connect
//return:none
void get_pieces_to_connect(int &pieces_to_connect,int row_num,int column_num){
   string num;
   bool Goodnum;
   do{
      cout<<"Enter number of pieces to connect (3 to (number <= rows or number <= colums)): ";
      getline(cin,num);
      Goodnum=num.length()>0  ?checknum(num):false;
      Goodnum=((Goodnum==true)&&((atoi(num.c_str())>=3)&&(atoi(num.c_str())<=row_num || atoi(num.c_str())<=column_num))) ? true:error();
   }while(Goodnum==false);
   pieces_to_connect=atoi(num.c_str());
}
//
//
//Function name:checknum()
//Description:this function check that a user has entered and postive whole intger number, when called
//Precondition:
//string number- holds the value the user has entered as a c++ string, can be any thei
//Postcondition:none
//return:returns true if the value the user entered is a good number else return false
bool checknum(string number){
   for(int a=0;a<number.length();a++)
      if(!(number.at(a)>='0' && number.at(a)<='9')){
	 return false;
      }

   return true;
}
//
//Function name:block_array()
//Description:this function declares a 2d array that is based on the number of rows and colums the user 
//inputted for the game board size.
//Precondition:
//int row_num-  hold the number of row for the board, integer whole number greater than 3 less than 25
//int column_num- hold the number of columns for the board, integer whole number greater than 3 less than 40
//char **&blocks- is a pointer passed by referance that will hold the 2d array for the number of blocks or the game grid
//Postcondition:
//char **&blocks- holds the addressed 2d array for the number of blocks or the game grid
//return:none
void block_array(int row_num,int column_num,char **&blocks){

   blocks=new char*[row_num];
   for(int row=0;row<row_num;row++){
      blocks[row]=new char[column_num];
      //for(int c=0;c<column_num;c++)
      // delete[] blocks[c];
      // delete [] blocks[row];
      //  blocks[row][0]=' ';
   }

   fill_blocks(row_num,column_num,blocks);//fill 2 d array with ' '
   //for(int i=0;i<column_num;i++)
   // delete [] blocks;
}
//
//Function name:fill_blocks()
//Description:this function fills each position in an array with a space ' '
//Precondition:
//char **blocks- holds or points the addressed of 2d array for the number of blocks or the game grid
//Postcondition:
//char **blocks- holds or points the addressed of 2d array for the number of blocks or the game grid, each position is fille with ' '
//return:none
void fill_blocks(int row_num,int column_num,char **blocks){

   for(int row=0;row<row_num;row++){
      for(int column=0;column<column_num;column++){
	 blocks[row][column]=' ';
      }
   }
   print_board(row_num,column_num,blocks);//prints the game board
}
//
//Function name:print-board()
//Description:this function prints the game board to screen
//Precondition:
//int row_num-  hold the number of row for the board, integer whole number greater than 3 less than 25
//int column_num- hold the number of columns for the board, integer whole number greater than 3 less than 40
//char **blocks- holds or points the addressed of 2d array for the number of blocks or the game grid
//Postcondition:none
//return:none
void print_board(int row_num, int column_num,char **blocks){ 
   for(int row=0;row<row_num;row++){
      int spaces=0;
      for(int column=0;column<(column_num+1);column++){
	 cout<<"|";
	 if(column<column_num){
	    cout<<" "<<blocks[row][column]<<" ";
	    spaces+=4;
	 }
      }
      print_line(spaces);     
   }
   print_numbersOfColumn(column_num);  
}
//Function name:print_line()
//Description:this function prints a line after ever row  that is the same size of the ro above it
//Precondition:
//int space- holds the lenght of the row of the game board
//Postcondition:none
//return:none
void print_line(int spaces){
   cout<<endl;
   for(int k=0;k<spaces+1;k++)
      cout<<"-";
   cout<<endl;
}
//Function name:print_numberOfcolumn()
//Description:this functiuns is called to label the number of columns under the game bord.
//Precondition:
//int column_num- hold the number of columns for the board, integer whole number greater than 3 less than 40
//Postcondition:none
//return:none
void print_numbersOfColumn(int column_num){
   for(int i=0;i<column_num;i++){
      if(i<10)
	 cout<<"  "<<i<<" ";
      else
	 cout<<" "<<i<<" ";
   }
   cout<<endl;
}
//
//Function name:get_player_color()
//Description:this function gets the player color choice fomr the first player based on that
//assigns a color to the send player. color can be rred (r) or yellow(y)
//Precondition:
//char *&player_one_color- will point to the color of player one red (r) or yellow(y)
//char *&player_two_color- will point to the color of player two red (r) or yellow(y)
//Postcondition:
//cahr *&player_one_color- points to the color of player one red (r) or yellow(y)
//cahr *&player_two_color- points to the color of player two red (r) or yellow(y)
//return:none
void get_player_color(char *&player_one_color,char *&player_two_color){
   string getcolor;

   do{
      cout<<"Player one do you want red or yellow(r or y)? ";
      getline(cin,getcolor);
   }while(checkcolor(getcolor)==false);
   player_one_color=new char[1];
   player_one_color[0]=getcolor[0];

   player_two_color=new char[1];

   player_two_color[0]= player_one_color[0]=='r' ? 'y':'r';

}
//Function name:checkcolor()
//Description:this function check to see if a user entered a valid color choice, r (red) or y(yellow)
//Precondition:
//string getcolor- hold the value or color choice from user
//Postcondition:none
//return:return true id good value else calls error() which print Error and returns false
bool checkcolor(string getcolor){
   if(getcolor.length()==1){
      if(getcolor=="r" || getcolor=="y")
	 return true;
   }
   return error();
}
//
//Function name:OnePlayer()
//Description:this function is used for the one player game type
//Precondition:
//int row_num-  hold the number of row for the board, integer whole number greater than 3 less than 25
//int column_num- hold the number of columns for the board, integer whole number greater than 3 less than 40
//int pieces_to_connect- hold the number of pieces to connect ex connect four will hold 4 pieces to connect
//char *player1_color- point to the color of player one red (r) or yellow(y)
//char *player2_color- point to the color of player two red (r) or yellow(y)
//char **blocks- holds or points the addressed of 2d array for the number of blocks or the game grid
//Postcondition:none
//return:none
void OnePlayer(int row_num,int column_num,int pieces_to_connect,char **blocks,char *player1_color,char *player2_color){

   int user_column_num,playerNum=1;
   bool win=false,full_or_not;
   char player_color;
   do{
      playerNum= playerNum%2==0 ? 2:1;//player changes base on whose turn
      player_color= playerNum==1 ? player1_color[0]:player2_color[0];//player color change base in player number
      computer_or_user(row_num,column_num,pieces_to_connect,blocks,playerNum,player_color);//funtion decide if user or computers turn
      print_board(row_num,column_num,blocks);//print the board after every turn
      win=check_win(row_num,column_num,blocks,pieces_to_connect,player_color,playerNum)==false ? check_full_board(row_num,column_num,blocks):true;// checks to is any one won or
                                                                                                                                                  //if board is full
      playerNum++;//changes playe number
   }while(win==false);//lop till someone has one or board is full
}
////Function name:computer_or_user()
//Description:this function decide if it is the computer or user turn
//Precondition:
//int row_num-  hold the number of row for the board, integer whole number greater than 3 less than 25
//int column_num- hold the number of columns for the board, integer whole number greater than 3 less than 40
//int pieces_to_connect- hold the number of pieces to connect ex connect four will hold 4 pieces to connect
//char **blocks- holds or points the addressed of 2d array for the number of blocks or the game grid
//int playerNum- hold 1 0r 2 , player 1 or player 2
//char player_color- holds players color r or y
//Postcondition:none
//char **blocks- holds or points the addressed of 2d array for the number of blocks or the game grid, changes based on the players colum choice
//the colum and row will hold the players color
//return:none
void computer_or_user( int row_num,int column_num,int pieces_to_connect,char **blocks,int playerNum,char player_color){
   if( playerNum%2!=0){	 
      user_drop_piece(row_num,column_num,blocks,player_color,playerNum);
   }else{
      cout<<"computer: Player 2"<<endl;
      computer_drop_piece(row_num,column_num,blocks,player_color,playerNum);
   }

}
//
//Function name: computer_drop_pieces()
//Description:this functions generates a random number between the 0 and the column numbern this the 
//computes column choice
//Precondition:
//int row_num-  hold the number of row for the board, integer whole number greater than 3 less than 25
//int column_num- hold the number of columns for the board, integer whole number greater than 3 less than 40
//int pieces_to_connect- hold the number of pieces to connect ex connect four will hold 4 pieces to connect
//char **blocks- holds or points the addressed of 2d array for the number of blocks or the game grid
//int playerNum- hold 1 0r 2 , player 1 or player 2
//char player_color- holds players color r or y
//Postcondition:
//char **blocks- holds or points the addressed of 2d array for the number of blocks or the game grid, changes based on the computer colum choice
//the colum and row will hold the computer color
//return:none
void computer_drop_piece(int row_num,int column_num,char **blocks,char player_color,int playerNum){
   bool full_or_not=false;
   int user_column_num;

   while(full_or_not==false){//loops till rand () produse a valid number
      user_column_num=rand()%column_num;//rand generates a random number between the 0 and the column numbern this the computes column choice
      full_or_not=check_user_fill_block(row_num,column_num,user_column_num,blocks,player_color);
   }
}
//Function name:PlayGame()
//Description:this funtion handles the 2 player option of the game
//Precondition:
//int row_num-  hold the number of row for the board, integer whole number greater than 3 less than 25
//int column_num- hold the number of columns for the board, integer whole number greater than 3 less than 40
//int pieces_to_connect- hold the number of pieces to connect ex connect four will hold 4 pieces to connect
//char **blocks- holds or points the addressed of 2d array for the number of blocks or the game grid
//char *player1_color- point to the color of player one red (r) or yellow(y)
//char *player2_color- point to the color of player two red (r) or yellow(y)
//Postcondition:none
//return:none
void PlayGame(int row_num,int column_num,int pieces_to_connect,char **blocks,char *player1_color,char *player2_color){
   int playerNum=1;
   bool win=false;
   char player_color;

   do{
      playerNum= playerNum%2==0 ? 2:1;
      player_color= playerNum==1 ? player1_color[0]:player2_color[0];
      user_drop_piece(row_num,column_num,blocks,player_color,playerNum);
      print_board(row_num,column_num,blocks);
      win=check_win(row_num,column_num,blocks,pieces_to_connect,player_color,playerNum)==false ? check_full_board(row_num,column_num,blocks):true;
      playerNum++;
   }while(win==false);//loops till player 1 or 2 wins or till game board is full
}
//
////Function name:user_board_size()
//Description:gets the user column ,also this funtion checks the users column  
//the row and colum based ont the user column number choice,if it is full or valid
//Precondition:
//int row_num-  hold the number of row for the board, integer whole number greater than 3 less than 25
//int column_num- hold the number of columns for the board, integer whole number greater than 3 less than 40
//int pieces_to_connect- hold the number of pieces to connect ex connect four will hold 4 pieces to connect
//char **blocks- holds or points the addressed of 2d array for the number of blocks or the game grid
//int playerNum- hold 1 0r 2 , player 1 or player 2
//char player_color- holds players color r or y
//Postcondition:none
//return:none
void user_drop_piece(int row_num,int column_num,char **blocks,char player_color,int playerNum){
   bool full_or_not=false;
   int user_column_num;

   while(full_or_not==false){
      user_column_num=getplayercolumn(column_num,playerNum);
      full_or_not=check_user_fill_block(row_num,column_num,user_column_num,blocks,player_color);
   }
}

//
//Function name:check_win()
//Description:this functions checks to see if there are x number of same colorer pieces connecter
//the function has 4 check, horizontal vertical diagonla positve sople and diagonla negative slope
//Precondition:
//int row_num-  hold the number of row for the board, integer whole number greater than 3 less than 25
//int column_num- hold the number of columns for the board, integer whole number greater than 3 less than 40
//int pieces_to_connect- hold the number of pieces to connect ex connect four will hold 4 pieces to connect
//char **blocks- holds or points the addressed of 2d array for the number of blocks or the game grid
//int playerNum- hold 1 0r 2 , player 1 or player 2
//char player_color- holds players color r or y
//Postcondition:none
//return:true there is a x number of like color pieces connected
bool check_win(int row_num,int column_num,char **blocks,int pieces_to_connect,char player_color,int player_num){

   if(check_win_horizontal(row_num,column_num,blocks,pieces_to_connect,player_color,player_num)==true)
      return true;
   if(check_win_vertical(row_num,column_num,blocks,pieces_to_connect,player_color,player_num)==true)
      return true;
   if(check_win_diagonal_up(row_num,column_num,blocks,pieces_to_connect,player_color,player_num)==true)
      return true;
   if(check_win_diagonal_down(row_num,column_num,blocks,pieces_to_connect,player_color,player_num)==true)
      return true;

   return false;

}
//
//Function name:get_playercolumn()
//Description:this function get a column from te user
//the column number is where the usere want to drop their piece
//Precondition:
//int column_num- holds where the user want to drop a piece
//int playernum- player 1 or 2
//Postcondition:none
//return:returns the user inputted column number
int getplayercolumn(int column_num,int playerNum){
   string PlayerColNum;
   bool Goodnum;//if valid number Gnum=(true) else (false)
   do{
      cout<<"Player "<<playerNum<<", what column do you want to put your piece?: ";
      getline(cin,PlayerColNum);
      Goodnum= PlayerColNum.length()>0 ? checknum(PlayerColNum):false;
      Goodnum=((Goodnum==true) && (atoi(PlayerColNum.c_str())<column_num))? true:error();
   }while(Goodnum==false);//loops till user enters a valid column number

   return atoi(PlayerColNum.c_str());

}
//
//Function name:check_user_fill_block()
//Description:this funcion check to see if the column number entered by ser id full or not
//Precondition:
//int row_num-  hold the number of row for the board, integer whole number greater than 3 less than 25
//int column_num- hold the number of columns for the board, integer whole number greater than 3 less than 40
//char **blocks- holds or points the addressed of 2d array for the number of blocks or the game grid
//int playerNum- hold 1 0r 2 , player 1 or player 2
//char player_color- holds players color r or y
//int user_column_num- the desire column where the user wants to drop a pieces
//Postcondition:none
//return:ture if colum is not full else false
bool check_user_fill_block(int row_num,int column_num,int user_column_num, char **blocks,char plyr_color){
   for(int i=0;i<row_num;i++){
      if(blocks[i][user_column_num]!=' '){	 cout<<"Full"<<endl;
	 return false;
      }
      if(i+1<row_num){
	 if( blocks[i][user_column_num]==' '&& blocks[i+1][user_column_num]!=' '){
	    blocks[i][user_column_num]=plyr_color;
	    return true;
	 }
      } else if(blocks[i][user_column_num]==' '){
	 blocks[i][user_column_num]=plyr_color;
	 return true;
      }
   }
}
//
//Function name:check_win_horizontal()
//Description:this function checks to see if a user has a win or connection x horizontally
//Precondition:
//int row_num-  hold the number of row for the board, integer whole number greater than 3 less than 25
//int column_num- hold the number of columns for the board, integer whole number greater than 3 less than 40
//int pieces_to_connect- hold the number of pieces to connect ex connect four will hold 4 pieces to connect
//char **blocks- holds or points the addressed of 2d array for the number of blocks or the game grid
//int player_num- hold 1 0r 2 , player 1 or player 2
//char player_color- holds players color r or y
//Postcondition:none
//return:ture if win else false
//
bool check_win_horizontal(int row_num,int column_num,char **blocks,int pieces_to_connect,char plyr_color,int player_num){
   for(int r=0;r<row_num;r++){
      for(int c=0;c<column_num;c++){
	 if(blocks[r][c]!=' '){  int win=0;	
	    for(int cc=c;cc<column_num;cc++){
	       if(blocks[r][cc]==plyr_color){	  win++;
	       }else{break;}
	       if(win==pieces_to_connect) {
		     cout<<"Player "<<player_num<<" wins. "<<"Hoizontal connect "<<pieces_to_connect<<" ("<< plyr_color<<").!!!!!!"<<endl;
		  return true;
	       }

	    }
	 }
      }
   }
}

//
//
//Function name:check_win_vertical()
//Description:this function checks to see if a user has a win or connection x vertically
//Precondition:
//int row_num-  hold the number of row for the board, integer whole number greater than 3 less than 25
//int column_num- hold the number of columns for the board, integer whole number greater than 3 less than 40
//int pieces_to_connect- hold the number of pieces to connect ex connect four will hold 4 pieces to connect
//char **blocks- holds or points the addressed of 2d array for the number of blocks or the game grid
//int player_num- hold 1 0r 2 , player 1 or player 2
//char player_color- holds players color r or y
//Postcondition:none
//return:ture if win else false
bool check_win_vertical(int row_num,int column_num,char **blocks,int pieces_to_connect,char plyr_color,int player_num){
   for(int r=0;r<row_num;r++){
      for(int c=0;c<column_num;c++){
	 if(blocks[r][c]!=' '){   int win=0;	
	    for(int rr=r;rr<row_num;rr++){
	       if(blocks[rr][c]==plyr_color){ win++;
	       }else{break;}
	       if(win==pieces_to_connect){
		     cout<<"Player "<<player_num<<" wins. "<<"Vertical connect "<<pieces_to_connect<<" ("<< plyr_color<<").!!!!!!"<<endl;
		  return true;
	       }
	    }
	 }
      }
   }
}

//
//Function name:check_win_diagonal_up()
//Description:this function checks to see if a user has a win or connection x diognally up
//Precondition:
//int row_num-  hold the number of row for the board, integer whole number greater than 3 less than 25
//int column_num- hold the number of columns for the board, integer whole number greater than 3 less than 40
//int pieces_to_connect- hold the number of pieces to connect ex connect four will hold 4 pieces to connect
//char **blocks- holds or points the addressed of 2d array for the number of blocks or the game grid
//int player_num- hold 1 0r 2 , player 1 or player 2
//char player_color- holds players color r or y
//Postcondition:none
//return:ture if win else false
bool check_win_diagonal_up(int row_num,int column_num,char **blocks,int pieces_to_connect,char plyr_color,int player_num){
   for(int r=0;r<row_num;r++){
      for(int c=0;c<column_num;c++){
	 if(blocks[r][c]!=' '){  int win=0, rr=r, cc=c, count=0;
	    while(count<pieces_to_connect){
	       if((rr>=0 && rr<row_num)&&(cc>=0 && cc<column_num)){ 
		  if(blocks[rr][cc]==plyr_color){ win++; }
		  if(win==pieces_to_connect){	
		     cout<<"Player "<<player_num<<" wins. "<<"Diagonal connect "<<pieces_to_connect<<" ("<< plyr_color<<").!!!!!!"<<endl;
		     return true;
		  }
	       }
	       count++;  rr--;   cc++;
	    }

	 }

      }
   }
}

//Function name:check_win_diagonal_down()
//Description:this function checks to see if a user has a win or connection x diagonally down
//Precondition:
//int row_num-  hold the number of row for the board, integer whole number greater than 3 less than 25
//int column_num- hold the number of columns for the board, integer whole number greater than 3 less than 40
//int pieces_to_connect- hold the number of pieces to connect ex connect four will hold 4 pieces to connect
//char **blocks- holds or points the addressed of 2d array for the number of blocks or the game grid
//int player_num- hold 1 0r 2 , player 1 or player 2
//char player_color- holds players color r or y
//Postcondition:none
//return:ture if win else false
bool check_win_diagonal_down(int row_num,int column_num,char **blocks,int pieces_to_connect,char plyr_color,int player_num){
   for(int r=0;r<row_num;r++){
      for(int c=0;c<column_num;c++){
	 if(blocks[r][c]!=' '){   int win=0,rr=r,cc=c,count=0;
	    while(count<pieces_to_connect){
	       if((rr>=0 && rr<row_num)&&(cc>=0 && cc<column_num)){ 
		  if(blocks[rr][cc]==plyr_color){ win++; }
		  if(win==pieces_to_connect){	
		     cout<<"Player "<<player_num<<" wins. "<<"Diagonal connect "<<pieces_to_connect<<" ("<< plyr_color<<").!!!!!!"<<endl;
		     return true; }
	       }
	       count++;   rr++; cc++;
	    }
	 }
      }
   }
}


//
//Function name:check_full_board()
//Description:this function check to see if all locations on board are full
//Precondition:
//int row_num-  hold the number of row for the board, integer whole number greater than 3 less than 25
//int column_num- hold the number of columns for the board, integer whole number greater than 3 less than 40
//char **blocks- holds or points the addressed of 2d array for the number of blocks or the game grid
//Postcondition:none
//return:returns ture if board is filled up, else false
bool check_full_board(int row_num,int column_num,char **blocks){
   for(int r=0;r<row_num;r++){
      for(int c=0;c<column_num;c++){
	 if(blocks[r][c]==' '){
	    return false;
	 }
      }
   }   
   cout<<"Full"<<endl;
   return true;
}
