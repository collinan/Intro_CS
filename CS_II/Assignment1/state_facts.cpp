
//Program:State Information 
//File:state_facts.cpp
//Name: Andrew Collins
//Date:04/09/2016
//Description:This program gets data about states and its counties and cities in the counties, from a ".txt" file, 
//then outputs the information base on the user ouput option.This file contains all the functions definitions (not main function) of the program.
//Input:none
//Output:none
//
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <string>
#include "./state_facts.h"
using namespace std;

//Description: Function checks to see if the arguments passed in from the 
//command line are vald
//
//Function name:bool is_valid_arguments()
//Description:this function check to see if the arguments passed by the user from the command line are valid.
//There must be 5 arguments passed 1)the executable (does not check this) 2)-s argumnet before the number of states
// 3) the number of states a positive integer greater than 0 4)-f argumnet before the file name
// 5) file name must have more than 4 character, last four char must be ".txt, and file must be in directory
//Pre-condition:gets the argument passed from the user
//Post-condition:if argumants are not valid asks user for valid argumants, and if valid return those argumant to main
//Return:return true if the state number and file name (for state information) is vaild and -s is second and -f is fourth command 
bool is_valid_arguments(char *argv[], int argc){
   bool g_num;//
   bool s_f;
   s_f=check_s_f(argv[1],argv[3]);
   if(s_f==false){return false;}

   while(check_num(argv[2])==false){//loop till the number of states is valid
      cout<<"Error: Invalid state number."<<endl;
      cout<<"Enter the number of states(1-50): ";
      cin>>argv[2];
   }
   cout<<argv[2]<<endl;

   while(check_file(argv[4])==false){//loop till file name is valid
      cout<<"Enter file name (.txt):";
      cin>>argv[4];
   }

   cout<<argv[4]<<endl;
   return true;
}

//Function name:check_s_f
//Description:this function check to see if the arguments passed from the command line
//have -s befor the number of states and -f before file name
//Pre-condition:gets the  second and 4 argument passed from command line
//Post-condition:none
//Return:return false if bad or missing arguments and program ends
bool check_s_f(char *s,char *f){
   if ((strcmp(s,"-s")!=0 || strcmp(f,"-f")!=0)){
      cout<<"Error invalid arguments passed."<<endl;
      cout<<"Example: ./state_facts -s 4 -f states.txt"<<endl;
      return false;
   }
   return true;
}

//
//Function name:check_num()
//Description:this function check if the user enterd a positive number when the are asked for one
//Pre-condition:users input
//Post-condition:none
//Return:returns false if user entered an invalid input(not number) else true
bool check_num(char *argv ){
   int s_num=strlen(argv);
   for(int i=0;i<s_num;i++){

      if(!(argv[i]>='0' && argv[i]<='9')||argv[0]=='0'){
	 return false;
      }
   }
   return true;
}

//
//Function name:check_file()
//Description:this function checks to see is the file name entered by the user is valid and 
//is in the directory
//Pre-condition:the filename entered by user
//Post-condition:a vaid file name
//Return:return ture once we the usere has entered a vlid file name that is in current directory,else false
bool check_file(char *f_txt){
   bool g_file;
   int c_array_len=strlen(f_txt);
   if(!(c_array_len>4)){  
      cout<<"Error: Invalid file name."<<endl;
      return false;
   }
   if(!(f_txt[c_array_len-1]=='t' && f_txt[c_array_len-2]=='x'&& f_txt[c_array_len-3]=='t'&& f_txt[c_array_len-4]=='.')){	 
      cout<<"Error: Invalid file name."<<endl;
      return false;
   }
   ifstream f_temp;
   f_temp.open(f_txt);
   if(!f_temp){
      cout<<"Error: File does not exist."<<endl;
      return false;
   }
   f_temp.close();

   return true;
}

//
//Function name:get_state_data()
//Description:this function reads from the txt file and stores the state data in the array
//Pre-condition:state *s- empty array type state will store all state and county information
//ifstream &file- file containing state and county data
//int num_s- positive integer, number of states in the txt file
//Post-condition:state *s- store all state data, from txt file
//Return:none
void get_state_data(state *s,int num_s, ifstream &file){

   for(int x=0;x<num_s;x++){
      file>>s[x].name;
      file>>s[x].population;
      file>>s[x].counties;

      s[x].c= create_counties(s[x].counties);

      get_county_data(s[x].c,s[x].counties,file);
   }
}


//
//Function name:get_county_data()
//Description:this function is called from get_state_data(),will read county informatino from txt file and store in county *c
//Pre-condition:county *c- will hold the county information
//int c_num- positive integer, is the number of counties in each state
//Post-condition:county *c,holds county information
//Return:none
void get_county_data(county *c,int c_num,ifstream &file){

   for(int y=0;y<c_num;y++){	
      file>>c[y].name;
      file >>c[y].population;
      file>>c[y].avg_income;
      file>>c[y].avg_house;
      file>>c[y].cities;

      c[y].city=new string[c[y].cities];

      for(int x=0;x<c[y].cities;x++){
	 file>>c[y].city[x];
      }
   }
}

//
//Function name:state *create_states()
//Description:this function creates an array of type state, array size is int s_num
//Pre-condition:int s_num- positive integer, is the number of states in txtx file
//Post-condition:none
//Return:returns array of type state (empty)
state *create_states(int s_num){
   state *s;
   s=new state[s_num];

   return s;

}

//
//Function name:create_counties()
//Description:this function creates an array of type county, array size is int c_num
//Pre-condition:int c_num- holds the number of counties in a state (from the txt file)
//Post-condition:none
//Return:an array of type county, that has lenght of the number of counties  in each state
county *create_counties(int c_num){
   county *c;
   c=new county[c_num];

   return c;

}

//Function name:del_states()
//Description:this function deallocates any  memory on the heap  used to store state and county information 
//Pre-condition:state *s -holds the state and county information
//int num_states- hold the number of state we have info on, positive integer
//Post-condition:state *s removed from heap
//Return:none
void del_states(state *s, int num_states){

   for(int x=0;x<num_states;x++){
      for(int y=0;y<s[x].counties;y++){

	 delete [] s[x].c[y].city;
      }

      delete[] s[x].c;
   }
   delete []s;

}

//////////////////////////////////////////////////
//Print Information

//void print_info(state *s, int num_states ){
//int user_p_f;
//user_p_fget_user_print_fun(


//Function name:s_large_pop()
//Description:this function will give us the state/states with the largest population
//Pre-condition:state *s- holds all the state and county information, 
//int num_states- holds the number of states
//Post-condition:state *s sorted in order byt the states populations
//Return:none
void s_large_pop(state *s,int num_states){
   state *temp;

   temp=new state[1];

   for(int x=0;x<num_states;x++){

      for(int y=0; y<num_states;y++){
	 if(s[x].population>s[y].population){
	    temp[0]=s[x];
	    s[x]=s[y];
	    s[y]=temp[0];
	 }
      } 
   }
   delete []temp;

   cout<<endl;
   cout<<endl;
   for(int n=0;n<num_states;n++){
      if(s[0].population==s[n].population)
      cout<<"State:"<<s[n].name<<"  State Population:"<<s[n].population<<endl;
   }
}
//
//Function name:c_large_pop()
//Description:this function prints out the county with the largest population
//Pre-condition:state *s- holds all the state and county information, 
//int num_states- holds the number of states
//Post-condition:none
//Return:none
void c_large_pop(state *s,int num_states){
   int total_counties=0;
   for(int x=0;x<num_states;x++){
      total_counties+=s[x].counties;
   }

   string *temp_county;//will hold all the county names
   int *temp_county_pop;//will hold all the county populations
   temp_county=new string[total_counties];//size sum of all the counties in each state
   temp_county_pop=new int[total_counties];//size sum of all the counties in each state
   int y=0;
   while(y<total_counties){
      for(int x=0;x<num_states;x++){
	 for(int z=0; z<s[x].counties;z++){
	    temp_county[y]=s[x].c[z].name;
	    temp_county_pop[y]=s[x].c[z].population;
	    y++;
	 }

      }
   }
   //puts counties in oreder
   string ttemp_c;
   int ttemp_cpop;
   for(int t=0;t<total_counties;t++){
      for(int u=0;u<total_counties;u++){
	 if(temp_county_pop[t]>temp_county_pop[u]){
	    ttemp_cpop=temp_county_pop[t];
	    ttemp_c=temp_county[t];

	    temp_county_pop[t]=temp_county_pop[u];
	    temp_county[t]=temp_county[u];

	    temp_county_pop[u]=ttemp_cpop;
	    temp_county[u]=ttemp_c;
	 }
      }
   }

cout<<endl;
cout<<endl;
for(int n=0;n<total_counties;n++){
if(temp_county_pop[0]==temp_county_pop[n]) 
   cout<<"County name:"<<temp_county[0]<<"  county population:"<<temp_county_pop[0]<<endl;

}
   delete [] temp_county;
   delete [] temp_county_pop; 

   cout<<"Total number of counties: "<<total_counties<<endl;


}
//
//Function name:c_income_above()
//Description:this function will print out the counties with an average income above a value provided by the user
//Pre-condition:state *s- holds all the state and county information, 
//int num_states- holds the number of states
//Post-condition:none
//Return:none
void c_income_above(state *s,int num_states){
   string temp_income;
   char *temp_cincome;
   bool g_income;
   float user_income;
   do{
      cout<<"Enter income:";
      cin>>temp_income;//user provide the avg income they are intrested in
      temp_cincome=new char[temp_income.length()];
      strcpy(temp_cincome,temp_income.c_str());
      g_income=check_num(temp_cincome);

      if(g_income==false){
	 cout<<"Error: Invalid input."<<endl;
      }else{
	 user_income=atof(temp_cincome);
      }

      delete [] temp_cincome;
   }while(g_income==false);

cout<<endl;
cout<<endl;
   for(int x=0;x<num_states;x++){
      for(int y=0;y<s[x].counties;y++){
	 if(s[x].c[y].avg_income>user_income){
	    cout<<"County name: "<<s[x].c[y].name<< " Averager income: "<<s[x].c[y].avg_income<<endl;
	 }
      }
   }
}

//
//Function name:avg_house_income()
//Description:this function prints the avg household cost for each county
//Pre-condition:state *s- holds all the state and county information, 
//int num_states- holds the number of states
//Post-condition:none
//Return:none
void avg_house_income(state *s,int num_states){
   cout<<endl;
cout<<endl;
   for(int x=0;x<num_states;x++){
	 cout<<"State Name: "<<s[x].name<<endl;
	 cout<<"Counties:"<<endl;
      for(int y=0;y<s[x].counties;y++){
	 cout<<s[x].c[y].name<<" Average household cost: "<<s[x].c[y].avg_house<<endl;
      }
   }
}

//
//Function name:s_sort_name()
//Description:this function put the states in alpabetical order, and prints them to the screen
//Pre-condition:state *s- holds all the state and county information, 
//int num_states- holds the number of states
//Post-condition:state *s is sorted in alphabetial order by state name
//Return:none
void s_sort_name(state *s, int num_states){
state *temp;

temp=new state[1];
for(int x=0;x<num_states;x++){
   for(int y=0;y<num_states;y++){
      if(s[x].name.compare(s[y].name)!=0){
	 int l=0;
	 while(s[x].name[l]==s[y].name[l]){
	    l++;
	 }
	 if( s[x].name[l]<s[y].name[l]){
	temp[0]=s[x];
	s[x]=s[y];
	s[y]=temp[0];

	 }

      }
   }



}
delete[]temp;
cout<<endl;
cout<<endl;
   for(int r=0;r<num_states;r++){
cout<<s[r].name<<endl;

   } 
}
//
//
//Function name:s_sort_pop()
//Description:this function sorts the *s array by each states population, largest to smallest
//Pre-condition:state *s- holds all the state and county information, 
//int num_states- holds the number of states
//Post-condition:state *s- is in order by the largest state to smallest
//Return:none
void s_sort_pop(state *s,int num_states){

   state *temp;

   temp=new state[1];

   for(int x=0;x<num_states;x++){

      for(int y=0; y<num_states;y++){
	 if(s[x].population>s[y].population){
	    temp[0]=s[x];
	    s[x]=s[y];
	    s[y]=temp[0];
	 }
      } 
   }
   delete []temp;

   cout<<endl;
   cout<<endl;
   for(int h=0;h<num_states;h++){
      cout<<"State"<<h+1<<":"<<s[h].name<<"  State Population:"<<s[h].population<<endl;
   }
}
//
//
//Function name:c_sort_population()
//Description:this function creats a temporry array int- county population, string- county name, sorts these by the county population
//largest to smallest.
//Pre-condition:state *s- holds all the state and county information, 
//int num_states- holds the number of states
//Post-condition:none
//Return:none
void c_sort_pop(state *s,int num_states){

   int total_counties=0;
   for(int x=0;x<num_states;x++){
      total_counties+=s[x].counties;
   }

   string *temp_county;
   int *temp_county_pop;
   temp_county=new string[total_counties];
   temp_county_pop=new int[total_counties];
   int y=0;
   while(y<total_counties){
      for(int x=0;x<num_states;x++){
	 for(int z=0; z<s[x].counties;z++){
	    temp_county[y]=s[x].c[z].name;
	    temp_county_pop[y]=s[x].c[z].population;
	    y++;
	 }

      }
   }
   //puts counties in oreder
   string ttemp_c;
   int ttemp_cpop;
   for(int t=0;t<total_counties;t++){
      for(int u=0;u<total_counties;u++){
	 if(temp_county_pop[t]>temp_county_pop[u]){
	    ttemp_cpop=temp_county_pop[t];
	    ttemp_c=temp_county[t];

	    temp_county_pop[t]=temp_county_pop[u];
	    temp_county[t]=temp_county[u];

	    temp_county_pop[u]=ttemp_cpop;
	    temp_county[u]=ttemp_c;
	 }
      }
   }
cout<<endl;
cout<<endl;
   for(int f=0;f<total_counties;f++){
      cout<<"County name:"<<temp_county[f]<<"  county population:"<<temp_county_pop[f]<<endl;
   }
   delete [] temp_county;
   delete [] temp_county_pop; 

   cout<<"Total number of counties: "<<total_counties<<endl;


}
//
//Function name:c_sort_name()
//Description:This function sorts all the couties in alphabetic arder, and prints to screen,creates a temp string arry to hold 
//couty names 
//Pre-condition:state *s- holds all the state and county information, 
//int num_states- holds the number of states
//Post-condition:none
//Return:none
void c_sort_name(state *s,int num_states){


   int total_counties=0;
   for(int x=0;x<num_states;x++){
      total_counties+=s[x].counties;
   }

   string *temp_county;
   temp_county=new string[total_counties];

   int y=0;
   while(y<total_counties){
      for(int x=0;x<num_states;x++){
	 for(int z=0; z<s[x].counties;z++){
	    temp_county[y]=s[x].c[z].name;
	    y++;
	 }

      }
   }
   //puts counties in oreder
   string ttemp_c;
   int ttemp_cpop;
   for(int t=0;t<total_counties;t++){
      for(int u=0;u<total_counties;u++){
if(temp_county[t].compare(temp_county[u])!=0){

   int l=0;
   while(temp_county[t].at(l)==temp_county[u].at(l)){
l++;
   }
   if(temp_county[t].at(l)<temp_county[u].at(l)){

	    ttemp_c=temp_county[t];
	    temp_county[t]=temp_county[u];
	    temp_county[u]=ttemp_c;
   }
}

	}
      }
cout<<endl;
cout<<endl;
   for(int f=0;f<total_counties;f++){
      cout<<"County name:"<<temp_county[f]<<endl;
   }
   delete [] temp_county;

   cout<<"Total number of counties: "<<total_counties<<endl;


}










