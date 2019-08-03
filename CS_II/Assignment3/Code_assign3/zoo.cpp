//Program filename:zoo.cpp
//Author:Andrew Collins
//Date:5/8/2016
//Description:this is the zoo class, holds and setsup all the exibits
//Input:/
//Output;/
#include "zoo.h"

using namespace std;



//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function Description:non default constructor for zoo class
//Pre-condition:values are hard coded according to the assignmanet
//Post-Condiotin:zoo object
//return:
zoo::zoo() :num_diff_animals(3),avg_food_cost(10), t(NULL),p_b(NULL),p(NULL),bank(100000),budget(0),num_tigers(0),num_polar_bears(0),num_penguins(0){

  }
//
//
///////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function Description:zoo destructor free up any memory on the heap
//Pre-condition:heap memory
//Post-Condiotin:heap cleared
//return:
zoo::~zoo(){
for(int n=0;n<num_tigers;n++){
   delete t[n];
}
delete [] t;

for(int n=0;n<num_polar_bears;n++){
   delete p_b[n];
}
delete []p_b;
for(int n=0;n<num_penguins;n++){
   delete p[n];
}
delete []p;

}
//
//
///////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function Description:this functins returns a pointer that poits to a array of points of type tiger
//Pre-condition:pointer to pointer array
//Post-Condiotin:
//return:pointer to pointer array
tiger ** zoo::get_tiger(){

return t;

}
//
//
///////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function Description:this functins returns a pointer that poits to a array of points of type polar bear
//Pre-condition:pointer to pointer array
//Post-Condiotin:
//return:pointer to pointer array
polar_bear **zoo::get_polar_bear(){
return p_b;

} 
//
//
///////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function Description:this functins returns a pointer that poits to a array of points of type penguin
//Pre-condition:pointer to pointer array
//Post-Condiotin:
//return:pointer to pointer array
penguin **zoo::get_penguin(){
return p;
}
//
//
///////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function Description:this function return the number of different animals, (three,tiger, P bears, penguins)
//Pre-condition:hold num different animals in  the zoo
//Post-Condiotin:
//return:num of different animale pos int
int zoo::get_num_diff_animals(){
return num_diff_animals;
}
//
//
///////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function Description:this function returns the amount of money left
//Pre-condition:hold the amount of money left
//Post-Condiotin:
//return:band- game money left
int zoo::get_bank(){
return bank;
}
//
//
///////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function Description:function returns the amount of money recuired to run the zoo
//based on the feeding cost of the animals
//Pre-condition:holds the amount of money required to run the zoo, 
//Post-Condiotin:
//return:return budget- the amount of money to run zoo,pos int
int zoo::get_budget(){
return budget;
}
//
//
///////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function Description:returns the number of polar bears in the zoo
//Pre-condition:number of polar bears in zoo
//Post-Condiotin:
//return:the number of polar bears in zooo,pos int
int zoo::get_num_polar_bears(){
return num_polar_bears;
}
//
//
///////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function Description:return the number of tigers in the zoo
//Pre-condition:holds the number of tigers in zoo
//Post-Condiotin:
//return:the num of tigers in  zoo, pos int
int zoo::get_num_tigers(){
return num_tigers;

}
//
//
///////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function Description:returns the number of penguins in zoo
//Pre-condition:holds number of penguins
//Post-Condiotin:
//return:return the number of penguins in the zoo, pos int
int zoo::get_num_penguins(){
return num_penguins;

}
//
//
///////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function Description:the function add a tiger to the zoo
//Pre-condition:x tigers
//Post-Condiotin:x+1 tigers
//return:
void zoo::set_tiger(int age){

   num_tigers++;
   tiger **temp;
   temp=t;

   //t=new tiger *;
   t=new tiger *[num_tigers];

   for(int i=0;i<(num_tigers-1);i++){
      t[i]=new tiger(temp[i]->get_age(),avg_food_cost);
   }
   t[num_tigers-1]= new tiger(age,avg_food_cost);

   for(int d=0;d<num_tigers-1;d++){
      delete temp[d];
   }
   delete [] temp;
}
//
//
///////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function Description:this functis kills or removers a tiger from the zoo
//Pre-condition:x tigers
//Post-Condiotin:x-1 tigers
//return:
void zoo::remove_tiger(){

   num_tigers--;
   tiger **temp;
   temp=t;

   //t=new tiger *;
   t=new tiger *[num_tigers];

   for(int i=0;i<(num_tigers);i++){
      t[i]=new tiger(temp[i]->get_age(),avg_food_cost);
   }
  // t[num_tigers-1]= new tiger(age,avg_food_cost);

   for(int d=0;d<num_tigers+1;d++){
      delete temp[d];
   }
   delete [] temp;

}
//
//
///////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function Description:this function adds a bear to the zoo
//Pre-condition:x bears
//Post-Condiotin:x+1 bears
//return:
void zoo::set_polar_bear(int age){

   num_polar_bears++;
   polar_bear **temp=p_b;
   temp=p_b;

   //p_b=new polar_bear*;
   p_b=new polar_bear *[num_polar_bears];

   for(int i=0;i<num_polar_bears-1;i++){
      //*p_b[i]=*temp[i];
      p_b[i]=new polar_bear(temp[i]->get_age(),avg_food_cost);
   }
   //t->[num_tigers](age,avg_food_cost);
   p_b[num_polar_bears-1]=new polar_bear(age,avg_food_cost);

   for(int d=0;d<num_polar_bears-1;d++){
      delete temp[d];
   }
   delete []temp;
}
//
//
///////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function Description:this function kills or removes a bear from the zoo
//Pre-condition:x bears
//Post-Condiotin:x-1 bear
//return:
void zoo::remove_polar_bear(){

   num_polar_bears--;
   polar_bear **temp=p_b;
   temp=p_b;

   //p_b=new polar_bear*;
   p_b=new polar_bear *[num_polar_bears];

   for(int i=0;i<num_polar_bears;i++){
      //*p_b[i]=*temp[i];
      p_b[i]=new polar_bear(temp[i]->get_age(),avg_food_cost);
   }

  // p_b[num_polar_bears-1]=new polar_bear(age,avg_food_cost);

   for(int d=0;d<num_polar_bears+1;d++){
      delete temp[d];
   }
   delete []temp;
}
//
//
///////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function Description:this function adds a penguin to the zoo
//Pre-condition:x penguins
//Post-Condiotin:x+1 penguins
//return:
void zoo::set_penguin(int age){

   num_penguins++;
   penguin **temp;
   temp=p;

   //p=new penguin *;
   p=new penguin *[num_penguins];
   
   for(int i=0;i<num_penguins-1;i++){
      p[i]=new penguin(temp[i]->get_age(),avg_food_cost);
   }
   //t->[num_tigers](age,avg_food_cost);
   p[num_penguins-1]=new penguin(age,avg_food_cost);
   for(int d=0;d<num_penguins-1;d++){
      delete temp[d];
   }
   delete []temp;
}
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function Description:this function kills or removes a penguin from the zoo
//Pre-condition:x penguins
//Post-Condiotin:x-1 penguins
//return:
void zoo::remove_penguin(){
   
   num_penguins--;
   penguin **temp;
   temp=p;

   //p=new penguin *;
   p=new penguin *[num_penguins];
   
   for(int i=0;i<num_penguins;i++){
      p[i]=new penguin(temp[i]->get_age(),avg_food_cost);
   }
   //t->[num_tigers](age,avg_food_cost);
  // p[num_penguins-1]=new penguin(age,avg_food_cost);
   for(int d=0;d<num_penguins+1;d++){
      delete temp[d];
   }
   delete []temp;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function Description:this function take out the zoo expences fromn the bank,
//also sunbtracts the cost of an aniuma;
//Pre-condition:bank total
//Post-Condiotin:bank total minus charges
//return:
void zoo::subtract_bank(int p){


   bank-=p;
}
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function Description:this function ads to the bank total,
//the payoffs or bonus
//Pre-condition:bank total
//Post-Condiotin:adds to it
//return:
void zoo::add_bank(int p){
   bank+=p;

}
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function Description:this function get the averager food base cost of an animals
//Pre-condition:food base cost
//Post-Condiotin:
//return:food base cost
int zoo::get_avg_food_cost(){


return avg_food_cost;

}
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//Function Description:sum of all the expencises of the zoo
//Pre-condition:0 or peverious budget
//Post-Condiotin:new zo budget
//return:
void zoo::set_budget(int b){

budget=b;

}
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////
