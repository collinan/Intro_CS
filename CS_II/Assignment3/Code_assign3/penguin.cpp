//Program filename:penguin.cpp
//Author:Andrew Collins
//Date:5/8/2016
//Description:this is the child class for penguin, inherates from public animal class
//Input:/
//Output;/
#include "penguin.h"

using namespace std;

int penguin::penguin_cost=1000;//set cost to buy penguin

//penguin::penguin(): animal(3,3,30,250){
//}


//Funation name:
//Description:this is the penguin non defaul constructor, gets vaules from zoo.cpp , and sent ts to animals 
//non default constructor
//Pre-condition:default value
//Post-condition:values now hold other values passed 
//return:
penguin::penguin(int a,int avg_food_cost) : animal(a,3,avg_food_cost,penguin_cost/5,penguin_cost){

}

//Funation name:
//Description:return the cost to buy a penguin
//Pre-condition:
//Post-condition:
//return:returns cost to buy the animals,pos  int values
int penguin::get_penguin_cost(){
return penguin_cost;
}
