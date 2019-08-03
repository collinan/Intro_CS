//Program filename:animal.cpp
//Author:Andrew Collins
//Date:5/8/2016
//Description:this is the parent class for tiger, polar bear, penguin
//Input:/
//Output;/
#include "animal.h"

using namespace std;

//Funation name:
//Description:non default constructor
//Pre-condition:default vaules passesd in accourind to animal type
//Post-condition:sets all the animal values
//return:
animal::animal(int age,int num_babies,int avg_food_cost,int payoff,int cost){
this->age=age;
this->num_babies=num_babies;
this->avg_food_cost=avg_food_cost;
this->payoff=payoff;
this->cost=cost;

}

//Funation name:
//Description:this is the operator assignment overload for animal class
//Pre-condition:default value
//Post-condition:values now hold other values passed from other obj
//return:
void animal::operator= (const animal &other){
age=other.age;
num_babies=other.num_babies;
avg_food_cost=other.avg_food_cost;
payoff=other.payoff;
cost=other.cost;
}


//Funation name:
//Description:sets the animals age increments by 1 day
//Pre-condition:currnet age
//Post-condition:day older
//return:
void animal::set_age(){
   age++;
}


//Funation name:
//Description:set the animaal babies, value is passed in
//Pre-condition:if animal is younger that 3 then num babies is 0 else 3
//Post-condition:holds number of babies for animals
//return:
void animal::set_num_babies(int b){
   num_babies=b;
}


//Funation name:
//Description:this function set the avg food cost for each animal, is based on provide costs
//Pre-condition:0
//Post-condition:the cost to feed the certain animal
//return:
void animal::set_avg_food_cost(int afc){
   avg_food_cost=afc;
}


//Funation name:
//Description:in this function we set up the payoff of the animal, (or money animal brings in)
//Pre-condition:0
//Post-condition:the animals payoff
//return:
void animal::set_payoff(int p_off){

   payoff=p_off;
}


//Funation name:
//Description:this function holds the amount it costs to buy the animal
//Pre-condition:0
//Post-condition:cast to buy animal
//return:
void animal::set_cost(int c){

   cost=c;
}

//Funation name:
//Description:this function return the animals age
//Pre-condition:
//Post-condition:
//return:the animals age
int animal::get_age(){

   return age;
}


//Funation name:
//Description:this function returns the number of babies the animla can have.
//Pre-condition:
//Post-condition:
//return:returns the number of babies thte aimal can have,
int animal::get_num_babies(){

  return num_babies;
}


//Funation name:
//Description:this function return the amount of money it costs to feed the animal
//Pre-condition:
//Post-condition:
//return:animals average food cost
int animal::get_avg_food_cost(){

   return avg_food_cost;
}


//Funation name:
//Description:this function returns the amount of money the animal can bring in
//Pre-condition:
//Post-condition:
//return:animals payoff
int animal::get_payoff(){

  return  payoff;
}


//Funation name:
//Description:this function returns the cost for buying the animal
//Pre-condition:
//Post-condition:
//return:the cost to buy animal
int animal::get_cost(){

  return  cost;
}




