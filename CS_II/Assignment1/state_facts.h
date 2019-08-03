//Program:State Information
//File name: state_facts.h
//Author: Andrew Collins
//Date:04/09/2016
//Description: This file contains all the function declaritios and the the struct state and county
//declaritions
//Input:none
//OutPut:none
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

//stuct county 
//contains all the decalaritons of variables associated with county informaiont
struct county{
   string name;//name of county
   string *city;//name of cities in county
   int cities;//number of cities in county
   int population;//total population of county
   float avg_income;//avg household income
   float avg_house;//avg household price
};
//struct state
//contains all the declarations of variab;es associated with each state.
struct state{
   string name;//name of state
   struct county *c;//name of counties
   int counties;//number of counties in the state
   int population;
};

//all the functions descriptions will be in the 
//state_facts.cpp file
bool is_valid_arguments(char *[],int);
bool check_s_f(char*,char*);//check is argv[1] is -s and argv[3] is -f 
bool check_num(char*);
bool check_file(char*);
state *create_states(int);
void get_state_data(state *,int, ifstream &);
county *create_counties(int);
void get_county_data(county *,int, ifstream &);
void del_states(state *,int);

void print_info(state *,int);
void delet_info(state *,int);

void s_large_pop(state *s,int num_states);
void c_large_pop(state *s,int num_states);
void c_income_above(state *s,int num_states);
void avg_house_income(state *s,int num_states);
void s_sort_name(state *s, int num_states);
void s_sort_pop(state *s,int num_states);
void c_sort_pop(state *s,int num_states);
void c_sort_name(state *s,int num_states);

