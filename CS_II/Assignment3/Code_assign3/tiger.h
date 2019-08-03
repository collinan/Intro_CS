//Program filename:tiger.h
//Author:Andrew Collins
//Date:5/8/2016
//Description:this is the class for tiger, get animal public members
//Input:/
//Output;/
#include<iostream>
#include "animal.h"

#ifndef TIGER_H_
#define TIGER_H_
using namespace std;

//Description:tiger  class
//member declarations
//all functions descriptions in .cpp
class tiger : public animal {
   private:
      static int tiger_cost;//hold cost to buy tiger
   public:
      tiger();
      tiger(int,int);
      static int get_tiger_cost();
};
#endif
