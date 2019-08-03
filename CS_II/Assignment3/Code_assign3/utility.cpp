//Program filename:utility.cpp
//Author:Andrew Collins
//Date:5/8/2016
//Description:this si where the game is played, the set up and the logic
//Input:/
//Output;/
#include "utility.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function Description:checks to se if user entered a valid number
//Pre-condition:
//Post-Condiotin:
//return:ture if number is valid else false
bool num_check(string n){
   int str_size=n.length();

   if(n[0]=='0'){
      return false;
   }
   for(int i=0;i<str_size;i++){
      if(!(n[i]>='0' && n[i]<='9')){
	 return false;
      }
   }
}
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function Description:print warning
//Pre-condition:
//Post-Condiotin:
//return:return false if user entered bad input
bool error(){
   cout<<"Error: Invalid input."<<endl;

   cout<<endl;
   cout<<endl;
   return false;
}
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function Description:function check to see if player has
//money to run zoo
//Pre-condition:
//Post-Condiotin:
//return:true if sufficient funds
bool check_bank(zoo &z){
   int bank=z.get_bank();
   int t=tiger::get_tiger_cost();
   int pb=polar_bear::get_polar_bear_cost();
   int p=penguin::get_penguin_cost();
   if(bank>t || bank>pb || bank>p){
      return true;
   }else{
      cout<<"You do not have enough money to buy any animal at this time"<<endl;
      return false;
   }
}
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function Description:checks to see if user want to buy an animal
//Pre-condition:
//Post-Condiotin:
//return:returns users anwswer
string buy(){
   string input;
   bool valid_input;

   do{
      cout<<"Do you want to buy an animal? (1-yes 2-no): ";
      cin>>input;
      valid_input=(num_check(input)==true) && input=="1" ||input== "2" ?true :error();

   } while(valid_input == false);
   return input;
}
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function Description:this is where the logic for 
//animal purchase take place
//Pre-condition:zoo z passed buy values
//Post-Condiotin:if user buys an animals, z holds new animal
//return:
void buy_animal(zoo &z){

   int bank=z.get_bank();
   int t=tiger::get_tiger_cost();
   int pb=polar_bear::get_polar_bear_cost();
   int p=penguin::get_penguin_cost();
   string input;
   bool valid_input;
   for(int i=1;i<4;i++){
      if((i==1&& bank>=t)|| (i==2 && bank>=pb) || (i==3 && bank>=p)){

	 do{
	    cout<<"Do you want to buy a "<<animal_name(i)<<"? (1-yes 2-no):";
	    cin>>input;
	    valid_input=(num_check(input)==true) &&( input.compare("1")==0 || input.compare("2")==0) ? true :error();
	 } while(valid_input == false);

	 if(input.compare("1")==0){
	    cout<<endl;
	    do{
	       cout<<"How many "<<animal_name(i)<<"s do you want to buy? (max 2):";
	       cin>>input;
	       valid_input=(num_check(input)==true)&&(input.compare("1")==0 || input.compare("2")==0) ?true :error();
	    } while(valid_input == false);
	    if(valid_input==true){
	       switch (i){
		  case 1: if(bank>=atoi(input.c_str())*t){
			     add_animal(i,atoi(input.c_str()),3, z);
			     z.subtract_bank(t*atoi(input.c_str()));
			  }else{
			     cout<<"You do not have enough money to buy ";
			     cout<< input<< animal_name(i)<<"s"<<endl;
			     valid_input=false;
			  }
			  break;
		  case 2: if(bank>=atoi(input.c_str())*pb){

			     add_animal(i,atoi(input.c_str()),3, z);
			     z.subtract_bank(pb*atoi(input.c_str()));
			  }else{
			     cout<<"You do not have enough money to buy ";
			     cout<< input<< animal_name(i)<<"s"<<endl;
			     valid_input=false;
			  }
			  break;
		  case 3: if(bank>=atoi(input.c_str())*p){

			     add_animal(i,atoi(input.c_str()),3, z);
			     z.subtract_bank(p*atoi(input.c_str()));
			  }else{
			     cout<<"You do not have enough money to buy ";
			     cout<< input<< animal_name(i)<<"s"<<endl;
			     valid_input=false;
			  }
			  break;
	       }
	    }

	 }
      }

   }
}
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function Description:calls each animal array to add an animal
//Pre-condition:animal type, the number to purchase, the animals age and zoo obj
//Post-Condiotin:
//return:
void add_animal(int animal_name,int num_buy,int age, zoo &z){
   switch(animal_name){
      case 1:cout<<"num buy:"<<num_buy<<endl;
	     for(int n=0;n<num_buy;n++){
		z.set_tiger(age);
	     }
	     break;
      case 2:for(int n=0;n<num_buy;n++){
		z.set_polar_bear(age);
	     }
	     break;
      case 3:for(int n=0;n<num_buy;n++){

		z.set_penguin(age);
	     }
	     break;
   }



}
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function Description:did not use see next function
//Pre-condition:
//Post-Condiotin:
//return:
string which_animal_buy(){
   string input;
   bool valid_input;

   do{
      cout<<"What animal do you want to buy?"<<endl;
      cout<<"(1-tiger, 2-polar bear, 3-penguin): ";
      cin>>input;
      valid_input=(num_check(input)==true) && (atoi(input.c_str())==1 || atoi(input.c_str())==2) ?true :error();
      //valid_input=//start here
   } while(valid_input == false);
   return input;

}
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function Description:take a number that corresponds to an animal
//Pre-condition:
//Post-Condiotin:
//return:ouputs the animals name
string animal_name(int animal){
   switch(animal){
      case 1: return " Tiger";
	      break; 
      case 2: return "Polar Bear";
	      break;
      case 3: return "Penguin";
	      break;
   }
}
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function Description:print the game board
//Pre-condition:
//Post-Condiotin:
//return:
void print(zoo &z){

   cout<<"Number of tigers: "<<z.get_num_tigers()<<endl;
   for(int i=0;i<z.get_num_tigers();i++){
      cout<<"Tiger number "<<i+1<<" age:";
      cout<<z.get_tiger()[i]->get_age()<<endl;
   }

   cout<<endl;
   cout<<endl;
   cout<<"Number of polar_bears: "<<z.get_num_polar_bears()<<endl;
   for(int i=0;i<z.get_num_polar_bears();i++){
      cout<<"Polar Bear number "<<i+1<<" age:";
      cout<<z.get_polar_bear()[i]->get_age()<<endl;
   }

   cout<<endl;
   cout<<endl;
   cout<<"Number of penguins: "<<z.get_num_penguins()<<endl;
   for(int i=0;i<z.get_num_penguins();i++){
      cout<<"Penguin number "<<i+1<<" age:";
      cout<<z.get_penguin()[i]->get_age()<<endl;
   }



}
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function Description:this function increament each anmimals age each day
//Pre-condition:
//Post-Condiotin:
//return:
void add_age(zoo &z){
   for(int n=0;n<z.get_num_tigers();n++){
      z.get_tiger()[n]->set_age();
   }

   for(int n=0;n<z.get_num_polar_bears();n++){
      z.get_polar_bear()[n]->set_age();
   }

   for(int n=0;n<z.get_num_penguins();n++){
      z.get_penguin()[n]->set_age();
   }
}
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function Description:this function sets the zoo budget, based on the 
//cost to feed the animals
//Pre-condition:
//Post-Condiotin:budget in class holds zoo expencis
//return:
void feed(zoo &z){

   int b=0;
   for(int n=0;n<z.get_num_diff_animals();n++){

      switch(n+1){

	 case 1:for(int t=0;t<z.get_num_tigers();t++){

		   b+=z.get_tiger()[t]->get_avg_food_cost();
		}
		break;
	 case 2:for(int pb=0;pb<z.get_num_polar_bears();pb++){
		   b+=z.get_polar_bear()[pb]->get_avg_food_cost();
		}
		break;
	 case 3:for(int p=0;p<z.get_num_penguins();p++){
		   b+=z.get_penguin()[p]->get_avg_food_cost();
		}
		break;

      }


   }
   z.set_budget(b);

}
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function Description:this function ask the user if he or she wants to continue playing
//Pre-condition:
//Post-Condiotin:
//return:false if they want to continue playing, else true
bool end_game(){

   string input;
   bool valid_input;

   do{
      cout<<"Do you want to continue playing?(1-yes 2-no):";
      cin>>input;
      valid_input=(num_check(input)==true) && input=="1" || input=="2" ?true :error();
   } while(valid_input == false);
   if(input=="1"){
      return false;
   }else{
      return true;
   }

}
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function Description:this function generates a random number that corsponds to a random event
//birth, death, bonous attendance, nothing
//Pre-condition:
//Post-Condiotin:
//return:
void random_event(zoo &z){
   srand(time(NULL));

   int random_num=rand()%4+1;
   switch(random_num){
      case 1:sickness(z);
	     break;
      case 2:boom_in_attendance(z);
	     break;
      case 3:if( tiger_old_enough(z)==true || polar_bear_old_enough(z)==true || penguin_old_enough(z)==true){
		baby_born(z);
	     }else{ cout<<"none of the animals are ready to give birth"<<endl;}
	     break;
      case 4:nothing();
	     break;
   }
}
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function Description:this function deals with the random event -sickness
//generates a random number that corresponds to the animals to be killed
//also calls emove to get rid of the animal from array
//Pre-condition:
//Post-Condiotin:one less animal in zoo
//return:
void sickness(zoo &z){
   bool check;
   int random_num=0;
   event_file("sick.txt");
   cout<<"A sickness occured in the zoo."<<endl;
   srand(time(NULL));
   do{
      random_num=rand()%4+1;
      check=(random_num==1 && z.get_num_tigers()>0)||(random_num==2 &&z.get_num_polar_bears()>0) ||(random_num==3 && z.get_num_penguins()>0)?true:false;

   }while(check==false);
   switch(random_num){
      case 1: cout<<"You have lost a Tiger due to sickness."<<endl;
	      z.remove_tiger();

	      break;
      case 2: cout<<"You have lost a Polar Bear due to sickness."<<endl;
	      z.remove_polar_bear();

	      break;
      case 3: cout<<"You have lost a Penguin due to sickness."<<endl;
	      z.remove_penguin();

	      break;
   }
}
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function Description:this function deals with the random event- boom in attendance
//which causes a bonus in the tiger pay off, which is calculated at random
//Pre-condition:
//Post-Condiotin:
//return:
void boom_in_attendance(zoo &z){

   event_file("bonus.txt");
   srand(time(NULL));

   int bonus=0;
   do{
      bonus=rand()%250+250;
   }while( bonus%10!=0);
   cout<<"Bonus : "<<bonus<<endl;
   z.add_bank(bonus);
}
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function Description:this function deals with the random event , animal born
//Pre-condition:
//Post-Condiotin:x more animals in zoo, each animal can have x babies if ooldr that 3
//return:
void baby_born(zoo &z){
   if(tiger_old_enough(z)==true || polar_bear_old_enough(z)==true || penguin_old_enough(z)==true){
      event_file("baby.txt");
      string input;//animal input
      bool valid_input;
      do{
	 cout<<"Which animal gives birth?(1-tiger 2-polar bear 3-penguin):";
	 cin>>input;
	 valid_input=(num_check(input)==true) && (atoi(input.c_str())==1 || atoi(input.c_str())==3||atoi(input.c_str())==2) ?true :error();
	 if(valid_input==true){

	    switch(atoi(input.c_str())){
	       case 1:
		  valid_input=tiger_old_enough(z);
		  break;
	       case 2:
		  valid_input=polar_bear_old_enough(z);
		  break;
	       case 3:
		  valid_input=penguin_old_enough(z);
		  break;
	    }

	 }
      }while(valid_input==false);


      switch(atoi(input.c_str())){
	 case 1:
	    for(int t=0;t<1;t++)
	       z.set_tiger(0);
	    break;
	 case 2:
	    for(int t=0;t<2;t++)
	       z.set_polar_bear(0);
	    break;
	 case 3:
	    for(int t=0;t<3;t++)
	       z.set_penguin(0);
	    break;
      }
   }else{
      cout<<"None of the animals can give birth"<<endl;
   }

}
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function Description:checks to see if there r tigers in the zoo
//and if they are old enough to give birth
//Pre-condition:
//Post-Condiotin:
//return:ture if there are tiger that can give birth
bool tiger_old_enough(zoo &z){
   if(!(z.get_num_tigers()>0)){
      cout<<"You do not have any tigers"<<endl;
      return false;
   }

   bool t_birth=false;
   for(int i=0;i<z.get_num_tigers();i++){
      if(z.get_tiger()[i]->get_age()>3){
	 return true;
      }
   }

   cout<<"You do not have any tigers old enough to have babies"<<endl;
   return false;
}
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function Description:checks to see if there are polar bears in the zoo
//and if they are old enough to give bire=th
//Pre-condition:
//Post-Condiotin:
//return:ture if there are polar bearsthat can give birth
bool polar_bear_old_enough(zoo &z){

   if(!(z.get_num_polar_bears()>0)){
      cout<<"You do not have any polar bears"<<endl;
      return false;
   }
   bool pb_birth=false;
   for(int i=0;i<z.get_num_polar_bears();i++){
      if(z.get_polar_bear()[i]->get_age()>3){
	 return true;
      }
   }
   cout<<"You do not have any Polar Bears old enough to have babies"<<endl;
   return false;
}
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function Description:checks to see if there are penguins in the zoo
//and if they are old enough to give bire=th
//Pre-condition:
//Post-Condiotin:
//return:ture if there are penguins that can give birth
bool penguin_old_enough(zoo &z){

   if(!(z.get_num_penguins()>0)){
      cout<<"You do not have any penguins"<<endl;
      return false;
   }
   bool p_birth=false;
   for(int i=0;i<z.get_num_penguins();i++){
      if(z.get_penguin()[i]->get_age()>3){
	 return true;
	 //return:
      }
   }
   cout<<"You do not have any Penguins old enough to have babies"<<endl;
   return false;
}
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function Description://this function takes in a file name passed from the random event and 
//based on the event it prints out a mesageto screen from the file 
//Pre-condition:file name
//Post-Condiotin:
//return:
void event_file(string f){
   ifstream read;
   int num_lines=0;
   int print_line;
   string temp;

   read.open(f.c_str());
   if(read){

      do{//reads once to see how many lines
	 getline(read,temp);
	 num_lines++;
      }while(!read.eof());
      read.close();

      read.open(f.c_str());
      string *line;
      line=new string[num_lines];
      int i=0;
      do{//save lines 
	 getline(read,line[i]);
	 i++;
      }while(!read.eof()&&i<num_lines-1);
      read.close();
      num_lines--;
      print_line=rand()%num_lines;
      cout<<line[print_line]<<endl;
      delete []line;
   }else{
      cout<<"File does not exixt."<<endl;
   }
}
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function Description:the random event where nothing happens
//Pre-condition:
//Post-Condiotin:
//return:
void nothing(){

   cout<<"Random event: nothing happened."<<endl;
}
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function Description:this function calculated the payoff oif the day based on the animals
//and bonus and adds it to the  bank total
//Pre-condition:z
//Post-Condiotin:total increases
//return:
void pay(zoo &z){
   int profit=0;

   for(int i=0;i<z.get_num_tigers();i++){
      if(z.get_tiger()[i]->get_age()>3){
	 profit+=z.get_tiger()[i]->get_payoff();
      }else{
	 profit+=(z.get_tiger()[i]->get_payoff()*2);
      }
   }

   for(int i=0;i<z.get_num_polar_bears();i++){
      if(z.get_polar_bear()[i]->get_age()>3){
	 profit+=z.get_polar_bear()[i]->get_payoff();
      }else{
	 profit+=(z.get_polar_bear()[i]->get_payoff()*2);
      }
   }

   for(int i=0;i<z.get_num_penguins();i++){
      if(z.get_penguin()[i]->get_age()>3){
	 profit+=z.get_penguin()[i]->get_payoff();
      }else{
	 profit+=(z.get_penguin()[i]->get_payoff()*2);
      }
   }

   cout<<"Todays Total payoff was: "<<profit<<endl;

   z.add_bank(profit);

}
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function Description:check to see if you have enouhg money to run the zoo
//or checks to see if you can cove the day expecses (budget)
//Pre-condition:
//Post-Condiotin:
//return:
bool run_zoo(zoo &z){
   if(z.get_budget()>z.get_bank()){
      cout<<"You do not have enough money to run you zoo, GAME OVER."<<endl;
      return true;
   }

   return false;

}
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////
