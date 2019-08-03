//Program filename:animal.h
//Author:Andrew Collins
//Date:5/8/2016
//Description:this is the parent class for tiger, polar bear, penguin
//Input:/
//Output;/
#include <iostream>

#ifndef ANIMAL_H
#define ANIMAL_H

using namespace std;

//Description:animal class
//mamber declarations
//all functions descriptions in .cpp
class animal{

   private:
      int age;//the age of the animal in days,if less than three years baby.
      int num_babies;//number of babies the animal can have
      int avg_food_cost;//the cost of feeding the animal each day
      int payoff;//profit made for each animal
      int cost;//cost of the animal

   public:
      animal();//default constructod
      animal(int,int,int,int,int);//non default constructor
      //~animal();
      void operator=(const animal &other);

      void set_age();
      void set_num_babies(int);
      void set_avg_food_cost(int);
      void set_payoff(int);
      void set_cost(int);


      int get_age();
      int get_num_babies();
      int get_avg_food_cost();
      int get_payoff();
      int get_cost();

};
#endif
