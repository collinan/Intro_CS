//Program filename:polar_bear.h
//Author:Andrew Collins
//Date:5/8/2016
//Description:this is the class for polar bear, get animal public members
//Input:/
//Output;/
#include<iostream>
#include "animal.h"

#ifndef POLAR_BEAR_H
#define POLAR_BEAR_H
using namespace std;

//Description:polar bear  class
//member declarations
//all functions descriptions in .cpp
class polar_bear: public animal{
private:
   static int polar_bear_cost;//holds cost for polar bear
   public:
      polar_bear();
      polar_bear(int,int);
      static int get_polar_bear_cost();
};
#endif
