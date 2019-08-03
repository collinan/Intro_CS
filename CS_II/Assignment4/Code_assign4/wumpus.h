//Program filename:wumpus.h
//Author:Andrew Collins
//Date:5/24/2016
//Description:part of wumpus game, header file for wumpus.cpp derived clas of event
//Input:
//Output:
#ifndef WUMPUS_H
#define WUMPUS_H
#include "event.h"
#include "iostream"

using namespace std;

class Wumpus:public Event{

   private:


   public:
      void event();

};

#endif
