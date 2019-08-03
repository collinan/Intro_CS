//Program filename:penguin.h
//Author:Andrew Collins
//Date:5/8/2016
//Description:this is the class for penguin, get animal public members
//Input:/
//Output;/
#include<iostream>
#include "animal.h"

#ifndef PENGUIN_H_
#define PENGUIN_H_
using namespace std;

//Description:penguin  class
//member declarations
//all functions descriptions in .cpp
class penguin: public animal{
   private:
      static int penguin_cost;//hold cost to buy tiger
   public:

//      penguin();
      penguin(int,int);
      static int get_penguin_cost();
};
#endif 
