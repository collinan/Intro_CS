//Program filename:event.h
//Author:Andrew Collins
//Date:5/24/2016
//Description:part of wumpus game, the is a prue virtule class, derived class are
//bats,gold,pits,wumpus
//Input:
//Output:
#ifndef EVENT_H
#define EVENT_H
#include <iostream>

using namespace std;

class Event{
   private:

   public:
      virtual void event()=0;

};

#endif
