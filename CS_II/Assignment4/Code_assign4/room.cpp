//Program filename:room.cpp
//Author:Andrew Collins
//Date:5/24/2016
//Description:part of wumpus game, is the room with the cave, each room has an event
//Input:
//Output:
#include "room.h"
//defaut constructor
Rooms::Rooms():visited(0),e(){
}

//set event in room
void Rooms::set_event(Event &ev){
e=&ev;
}
//change event to null
void Rooms::reset_event(){
   e=NULL;

}

//return the rooms event pointer
Event *Rooms::get_event(){

return e;
}
