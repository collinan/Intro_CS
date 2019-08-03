//Program filename:zoo_driver.cpp
//Author:Andrew Collins
//Date:5/8/2016
//Description:this file contntains the program main file.
//the program runs a virtual zoo.In the game the user creates a zoo, that has different exibits of animals..
// In this game there sre three exibits, the tigers, polar bears and penguins. the gaem deals with the
//  logistics behind running a zoo. (for more detail view design and test) 
//Input:/user will select the anumals to buy
//Output;program runs though different senerious that may arise while running a zoo
#include <iostream>
#include <cstdlib>
#include <string>
#include "zoo.h"
#include "utility.h"

using namespace std;
//Function description:this the main function of the game, the funcion calls the setup ands game 
//run function s to play game, most function are called in utility.cpp
//Precondition:
//Post condition
//return:
int main(){
   int day=1;
   zoo z;//zoo object
   string input;//holds user input for several questions
   bool valid_input;
//   boom_in_attendance(z);
   do{
      cout<<"BANK: "<<z.get_bank()<<endl;

      if(check_bank(z)==true && buy().compare("1")==0 ){
	 buy_animal(z);
      cout<<"BANK: "<<z.get_bank()<<endl;
      }

      cout<<"******************************************************************************"<<endl;
      cout<<"Day "<<day<<endl;
      feed(z);
      if((z.get_num_tigers()+z.get_num_polar_bears()+z.get_num_penguins())>0){
      cout<<"You spent "<<z.get_budget()<<" to feed all the animals."<<endl;
      z.subtract_bank(z.get_budget()); 
      cout<<"BANK: "<<z.get_bank()<<endl;
      add_age(z);//add to animal age

      cout<<endl;
      cout<<endl;
      print(z);
      cout<<endl;
      cout<<endl;
      cout<<"******************************************************************************"<<endl;
      random_event(z);
      print(z);
pay(z);
      }
      cout<<"******************************************************************************"<<endl;
      cout<<endl;
      cout<<endl;

      day++;

   }while(run_zoo(z)==false && end_game()==false);
   cout<<"end"<<endl;
   return 0;

}

