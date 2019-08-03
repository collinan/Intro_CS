//Program:hangman.cpp
//Author: Andrew Collins
//Date:11/08/2015
//Description: This is the hangman game, You will enter a message--> then you will guess letters in that message, 
//You will only get 5 tries to guess the message, if you guess a letter rigth it does not count toward your tries.
//the game ends when you run out of tries of(you lose), or when you guess the message (you win). 
//Inputs: message from users, guesses / letters
//Output: message in __ ___ form or with letters if guesse right , numbers of triesleft, all letters inputted and number or correct
//letters in word. 
#include <iostream>
#include <string>
#include <locale>
#include <cstdlib>


using namespace std;
//function declarations:
void get_message(string &message);
void make_DashMessage(string message, string &DashMessage);
void get_letter(string &letter,string AllLetters);

string caps(string s);
bool check_letter_repeat(string letter, string AllLetters);
bool check_input(string l_or_wrd);

int check_letter_in_message(string message, string &Dashmessage, string letter);
void guess_loop(string message, string &DashMessage);
void error();
void print_dash(string DashMessage);
int letter_in_word(int num, string letter,string *AllLetters);
void print_letters(string letter);
void win_loose(string message,string DashMessage,int lives);

//functionname: print_rules()
//description: print hangman rules
//precondition: none
//Postcondition: none
//return:none
void print_rules(){
cout<<"HANG MAN"<<endl;
cout<<"Enter message that you want someone to guess.(olny alphabets in message)"<<endl;
cout<<"Start guessing letters in message; you will get 5 turns to guess the message."<<endl;
cout<<"If you guess a letter right, it does not cound againt you."<<endl;
cout<<"GOOD LUCK"<<endl;

}



//Function name: main()
//Description:Main function for program hangman,will call on other function in program 
//Precondition:none
//Post condition:none
//return:returns 0 to end program
int main(){
   string message;
   string DashMessage;
	print_rules();
   get_message(message);
   make_DashMessage(message, DashMessage);
   guess_loop(message,DashMessage);

   return 0;
}


//Function name: get_message()
//Description: Get word or words from user and saves in variablemessage, can only be alphabets or spaces
//Precondition:message empty string type, passed by referance
//Post condition:hold the word or words entered b user and passed back o main
//return:none
void get_message(string &message){
   bool check;
   do{
      cout<<"Enter a message: ";
      getline(cin,message);
      check=check_input(message);
   }while(check == false);
   message = caps(message);

   cout<<message<<endl;
   system("clear");
   cout<<message<<endl;
}


//Function name: make_DashMessage()
//Description: Get word or words from user and replace all charates with __ or space
//Precondition:message- hold words inputted by user, DashMessage empty string type passed by referance
//Post condition:message-no change, DashMessage- has users iput in __ and spaces
//return:none
void make_DashMessage(string message, string &DashMessage){

   for(int x=0;x<message.length();x++)
      DashMessage+= message.at(x) == ' '? " " : "_";
}


//Function name:get_letter()
//Description: Gets users guess in letter form, only one alphabet
//Precondition:letter- passed by referance empty, AllLetters-holds all the letters entered by user (at first blank
//Post condition:letter- will hold user guess passed to guess_loop()
//return:none
void get_letter(string &letter,string AllLetters){
   bool check=false;
   do{
      
      cout<<"Guess a letter: ";
      getline(cin,letter);
      if(letter.length()>1){error();}
      else{
      check = check_input(letter);
      check=check==false ? false:check_letter_repeat(letter, AllLetters);}
   }while(check == false);
   letter = caps(letter);
}


//Function name:check_letter_repeat()
////Description: check to see if user entred the same letter(guess) twice
//Precondition: letter- holds user guess, AllLetters-holds all letters user have ever entered(guesses)
//Postcondition: all variable stay the same
//return:false if users has entered the same letter twice, else true
bool check_letter_repeat(string letter, string AllLetters){
  letter= caps(letter);
for(int i=0;i<AllLetters.length();i++){
   if(AllLetters.at(i) == letter.at(0)){
      cout<<"You have already entered this letter."<<endl;
      return false;
   }
}
return true;
}


//Function name: check_input()
//Description: check to see if users iputs are alphabets only
//Precondition:l_or_word- will hold either words or a letter
//Post condition:none
//return:return false if bad input, anthing other than letters or spaces
bool check_input(string l_or_wrd){
   if(l_or_wrd.length()<=0){
      error();
   cout<<" You did not enter anything."<<endl;
   return false;
   }
   for(int i=0;i<l_or_wrd.length();i++){
      if(!(isalpha(l_or_wrd[i]) || isspace(l_or_wrd[i]))){
	error();
	 return false;
      }
   }
   return true; 
}


//Function name: error
//Description: when calle on prints "Error"
//Precondition:none
//Post condition:none
//return:none
void error(){
   cout<<"Error."<<endl;
}


//Function name: caps()
//Description: takes any input from user and capitalizes all characters
//Precondition:s-users input, words r letter
//Post condition:none
//return:returns input as capital letters/letter
string caps(string s){
   locale loc;
   for(string::size_type i=0;i<s.length();i++){
      s[i]=toupper(s[i],loc);  
   }
   return s;
}


//Function name: check_letter_in_mesage()
//Description: checks to see if the letter(guess) user entered is in the word or words, 
//if it is it replace the corresponding _ with the letter
//Precondition:message- holds users message, DashMessage- corespondong message with balnks, letter- holds users guess
//Post condition:Dashmessage- passed by referance; if user guess maches words the value of _ shows letter passed back to guess loop
//return:number of time the letter occurs in the message (whole number)
int check_letter_in_message(string message, string &Dashmessage, string letter){
   int i=0;
   for(int x=0;x<message.length();x++){
      if(letter.at(0)==message.at(x))
      {
	 Dashmessage.replace(x,letter.length(),letter); 
	 i++;
      }
}
if(i>0){ return i;}
else{ return 0;}
}


//Function name: print_dash()
//Description: prints the DashMessage, users message with blanks or correctly guessed letters 
//Precondition:DashMessage- holds users message with blanks or correctly guessed letters
//Post condition:none
//return:none
void print_dash(string DashMessage){
   cout<<"The message is: "<<DashMessage<<endl;
}


//Function name:letter_in_word() 
//Description: prints out the number of thime the letter(guess) occurs in message, also adds to a variable that hold all user guesses, 
//and keeps track of the cout(lives to end game)
//Precondition:num- holds number of time letter occured in message, letter- the guess entered by user, Alleters- point that point to variable that
//holds all users guess
//Post condition:AllLetters-still point to variable that holds users guesses
//return:0-is users guess is correct, 1- if users guessed wrong
int letter_in_word(int num,string letter,string *AllLetters){
   if(num>0){
      cout<<"There is "<<num<<" "<<letter<<"."<<endl;
   }
   else{
      cout<<"There is no "<<letter<<"."<<endl; 
   }
   *AllLetters+=letter;//adds current letter to the variable that holds all users gusser AllLetters point to that location

   return (num>0) ? 0: 1;
}


//Function name: print_letter()
//Description: prints all users guesses letters
//Precondition:AllLetters- holds alll users guesses
//Post condition:none
//return:none
void print_letters(string AllLetters){

   cout<<"You have guessed: "<<AllLetters<<endl;

}


//Function name: guess_loop()
//Description: brain of program, control get_letter(), check_letter_inmessage(),letter_in_word(),also calls most print functions
//and win_loose function
//Precondition:message- hold message entered bu user, DashMessage-blank equivelent of message entered by user.
//Post condition:DashMessage changes if user guesses letter in message correct
//return:none
void guess_loop(string message, string &DashMessage){

   string letter,AllLetters;
   int lives=0;
   while(lives<=5){
      print_dash(DashMessage);
      get_letter(letter,AllLetters);
      lives+=letter_in_word( check_letter_in_message(message,DashMessage,letter),letter,&AllLetters);//lives changes if users guesse letter wrong 
      print_letters(AllLetters);
      win_loose(message,DashMessage,lives);

   }

}


//Function name: win_loose()
//Description: this function checks to see if usere has won(if DashMessage == message), lost(if the number of worng guesses==5(numbe of turns),
//or tells user how many guesses they have left.
//Precondition:message-holds users mesage, DashMessage- holds message equivalent in _ or space or can contain correct guessed letters
//lives- holds the number of turns users has left
//Post condition:none
//return:none, program ents if user guessed all letters correct in message(win) or if user hase guessed 5 worng(lose).
void win_loose(string message,string DashMessage,int lives){
   if(message==DashMessage){
      cout<<"The message is: "<<message<<endl;
      cout<<"You won!!!!!"<<endl;
      exit(0); }
   else if(lives==5){
      cout<<"The message is: "<<message<<endl;
      cout<<"You have run out of guesses, you lose."<<endl;
      exit(0);}
   cout<<"You have "<<lives<<" incorrect out of 5."<<endl;
}



