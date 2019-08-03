#ifndef LIST_H
#define LIST_H
//Program:
//Author: Andrew Collins
//Date: 05/29/2016
//Description:this the list.h header file, this is where we have the struct(or linklist components)
//declared,and have the functunction to add a node, sort, and remove node function decllaratoins
//also other functoins to deal with the linked list,
//Input:none
//Output:none
#include <stdio.h>
#include <stdlib.h>
/////function are explained in .c file
struct node{
int val;//hold the pos interger value from the txt file
struct node *next;//point to the next node in our list, or to null if last node
struct node *prev;//points to the previous node in our list or to null if first node
};

struct list{
struct node *head;//points to the first node in our list, or to null if list is empty 
struct node *tail;//point to the last node in our list , or to null if list is empty
};


int length(struct list);//return number of nodes in the list
void print(struct list);//print the values in list

void push_front(struct list *, int);//push to front of list
void push_back(struct list * , int);//push to the end of list


void sort_ascending(struct list*); //sort list smalles to biggest
void sort_descending(struct list*);//sort list biggest to smallest

void remove_val(struct list *, int);//remove nodes with int as val
void insert(struct list *,int, int);//insert into a location in the list, start at 0 from the front
void clear(struct list *);//remove all nodes from the list

#endif
