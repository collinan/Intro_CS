//Program:State Information 
//File:run_facts.cpp
//Name: Andrew Collins
//Date:04/09/2016
//Description:This program gets data about states and its counties and cities in the counties, from a ".txt" file, 
//then outputs the information base on the user ouput option.This file contains the main function of the program.
//all the other function are calle from here.
//Input:number of states in the txt file as an integer value and the "txt" file name
//Output:prints information about the states according to users view option.
//
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "./state_facts.h"

using namespace std;
//Function name:main()
//Description:this the main function of the program
//Pre-condition:gets the number of states, positive integer saved as char, 
//and the name of the text file,".txt" as char* (lenght must be greater than 4), from the command line
//Post-condition:free up memory
//Return:none
int main(int argc, char *argv[]){
   bool check_arg;
   ifstream in_file;
   state *s;
   int num_states;
   int c_num;
   if(argc!=5){
      cout<<"Error: Too few argumants supplied."<<endl;
      return 0;
   }
   //checks to see if user entered valid argumants from comman line
   //loop till users values are valid
do{
   check_arg=is_valid_arguments(argv,argc);
   if(check_arg==false){return 0;}
   num_states=atoi(argv[2]);
   s=create_states(num_states);
   in_file.open(argv[4]);
   get_state_data(s,num_states,in_file);
   in_file.close();

   bool g_choice;
   string choice;
   char *ch;

     //loop till user enters valid print option
     //or users waant to enter new number of states or user wants to end program
  do{
   do{

      cout<<endl;
      cout<<endl;
      cout<<"1-Print the state with the largest population"<<endl;
      cout<<"2-The county with the largest population."<<endl;
      cout<<"3-The counties with an income above a specific amount."<<endl;
      cout<<"4-The average household cost for all counties in each state."<<endl;
      cout<<"5-The states in sorted order by name."<<endl;
      cout<<"6-The states in sorted order population."<<endl;
      cout<<"7-The counties within states sorted by population."<<endl;
      cout<<"8-The counties within states sorted by name."<<endl;
      cout<<"9-Enter a new file name and number of states."<<endl;
      cout<<"10-End program."<<endl;
      cout<<endl;
      cout<<"Enter option (1-10): ";
      cin>>choice;

      ch=new char[choice.length()];
      strcpy(ch,choice.c_str());
      g_choice=check_num(ch);
      if(g_choice==true){
	 c_num=atoi(ch);
	 if(!(c_num>=1 && c_num<=10)){
	    cout<<"Error:Invalid input."<<endl;
	    g_choice=false;
	 }
      }


   delete [] ch;
   }while( g_choice == false);
   //this switch takes user view option
   //and calls the associated function
   switch(c_num){
      case 1: s_large_pop(s,num_states);
	      break;
      case 2: c_large_pop(s,num_states);
	      break;
      case 3: c_income_above(s,num_states);
	      break;
      case 4: avg_house_income(s,num_states);
	      break;
      case 5: s_sort_name(s,num_states);
	      break;
      case 6: s_sort_pop(s,num_states);
	      break;
      case 7: c_sort_pop(s,num_states);
	      break;
      case 8: c_sort_name(s,num_states);
	      break;
   }
  }while(c_num>=1 && c_num<=8);//stops user wants to quit or enter new file name and number of states
//gets user new number of states and new file name
if(c_num==9){
cout<<"Enter number of states:";
cin>>argv[2];
cout<<"Enter file name:";
cin>>argv[4];
}
//this frees any memory on head
//(deallocates)
del_states(s,num_states);
}while(c_num!=10);//ends program






//while(chec_num
//print_info(s,num_states);
/*
for(int h=0;h<num_states;h++){
   cout<<"State"<<h+1<<":"<<s[h].name<<endl;
   cout<<"State Population:"<<s[h].population<<endl;
   cout<<"State number of counties"<<s[h].counties<<endl;
   for(int i=0;i<s[h].counties;i++){
      cout<<"County name: "<<s[h].c[i].name<<endl;
      cout<<"County population: "<<s[h].c[i].population<<endl;
      cout<<"County income: "<<s[h].c[i].avg_income<<endl;
      cout<<"County avg house hold income: "<<s[h].c[i].avg_house<<endl;
      cout<<"County number of cities: "<<s[h].c[i].cities<<endl;
      for(int j=0;j<s[h].c[i].cities;j++){

	 cout<<"City " <<j+1<< " name:"<<s[h].c[i].city[j]<<endl;

      }

   }

}
*/


return 0;
}
