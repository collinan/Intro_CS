//Program filename:polar_bear.cpp
//Author:Andrew Collins
//Date:5/8/2016
//Description:this is the child class for polar bear, inherates from public animal class
//Input:/
//Output;/
#include "polar_bear.h"

using namespace std;

int polar_bear::polar_bear_cost=5000;//set cost to buy a polar bear

//polar_bear::ploar_bear(): animal(3,2,30,250){
//}


//Funation name:
//Description:this is the polar bear non defaul constructor, gets vaules from zoo.cpp , and sent ts to animals 
//non default constructor
//Pre-condition:default value
//Post-condition:values now hold other values passed 
//return:
polar_bear::polar_bear(int a,int avg_food_cost) : animal(a,2,3*avg_food_cost,polar_bear_cost/5,polar_bear_cost){

}

//Funation name:
//Description:return the cost to buy a polar bear
//Pre-condition:
//Post-condition:
//return:returns cost to buy the animals,pos  int values
int polar_bear::get_polar_bear_cost(){
return polar_bear_cost;
}
