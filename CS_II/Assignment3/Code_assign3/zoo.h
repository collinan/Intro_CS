//Program filename:zoo.h
//Author:Andrew Collins
//Date:5/8/2016
//Description:this is the class for zoo, has all the zoo logestics
//Input:/
//Output;/
#include <iostream>
#include "tiger.h"
#include "polar_bear.h"
#include "penguin.h"

#ifndef ZOO_H 
#define ZOO_H
using namespace std;

//Description:zoo  class
//member declarations
//all functions descriptions in .cpp
class zoo{

   private:
      int num_diff_animals;//number of different animals current 3
      int num_tigers;//number of tigers in zoo
      int num_polar_bears;//number of polar bears in  zoo
      int num_penguins;//number of penguins in zoo
      tiger **t;//point to array of tiger pointers
      polar_bear **p_b;//point to array of tiger pointers
      penguin **p;//point to arry of tiger pointes
      int bank;//the money we have run zoo
      int budget;//the money we need to run zoo
      int avg_food_cost;//the base cost for food for animal
   public:
      zoo();//default constructor
      ~zoo();//destructor
      
      void subtract_bank(int);
      void add_bank(int);
  
	 void set_tiger(int);
      void set_polar_bear(int);
      void set_penguin(int);
      
	 void remove_tiger();
      void remove_polar_bear();
      void remove_penguin();
      
      void set_budget(int);
      
      tiger **get_tiger();
      polar_bear **get_polar_bear();
      penguin **get_penguin();
      int get_num_diff_animals();
      int get_bank();
      int get_budget();
      int get_num_polar_bears();
      int get_num_tigers();
      int get_num_penguins();
      int get_avg_food_cost();
};
#endif
