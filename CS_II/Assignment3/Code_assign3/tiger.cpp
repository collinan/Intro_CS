//Program filename:tiger.cpp
//Author:Andrew Collins
//Date:5/8/2016
//Description:this is the child class for tiger, inherates from public animal class
//Input:/
//Output;/
#include "tiger.h"

using namespace std;
int tiger::tiger_cost=10000;//declare static member cost to buy tiger

//tiger::tiger() : animal(3,1,50,tiger_cost/10,tiger_cost){

//}

//Funation name:
//Description:this is the tiger non defaul constructor, gets vaules from zoo.cpp , and sent ts to animals 
//non default constructor
//Pre-condition:default value
//Post-condition:values now hold other values passed 
//return:
tiger::tiger(int age,int avg_food_cost) : animal(age,1,5*avg_food_cost,tiger_cost/10,tiger_cost){

}


//Funation name:
//Description:return the cost to buy a tiger
//Pre-condition:
//Post-condition:
//return:returns cost to buy the animals,pos  int values
int tiger::get_tiger_cost(){
   return tiger_cost;
}
