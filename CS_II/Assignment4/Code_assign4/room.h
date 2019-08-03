//Program filename:room.h
//Author:Andrew Collins
//Date:5/24/2016
//Description:Part of wumpus game, header file for room.cpp
//Input:
//Output:
#ifndef ROOM_H
#define ROOM_H
#include "event.h"

class Rooms{

   private:
Event *e;//event pointed can point to derived event obj, bats,gold,pit,wumpus
int visited;//delete

   public:
Rooms();
void set_event(Event &);
Event *get_event();
void reset_event();
};
#endif
