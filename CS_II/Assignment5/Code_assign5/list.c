//Program:doubly linked list
//Author: Andrew Collins
//Date: 05/29/2016
//Description:This is file contain all the function definitions, that are
//used to set up, sort and print our linked list.
//Input:the function declarations are in the list.h file
//Output:N/A
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

//Function Description:Computes the number of nodes in our linked list
//Pre-condition:our linked list
//Post-Condition:unchanged linked list
//return:the number of nodes in out list
int length(struct list l){
   struct node *temp=NULL;
   int list_length=0;
   temp=l.head;

   while(temp!=NULL){
      //  printf("Number is: %d \n", temp->val);
      temp=temp->next;
      list_length++;
   }

   return list_length++;
}


//Function Description: print the values in list
//Pre-condition:our linkd list
//Post-Condition:unchanged list
//return:none
void print(struct list l){
   struct node *temp=NULL;
   temp=l.head;
   int val_num=1;
   while(temp!=NULL){
      printf("%d Number is: %d \n",val_num, temp->val);
      temp=temp->next;
      val_num++;
   }

}


//Function Description:pushes a node to front of list and reassigns the head ptr
//Pre-condition:l-take our list, can be empty
//num-the value to input into our list
//Post-Condition:l-has a new node at the front, whose val is num
//return:none
void push_front(struct list *l, int num){

   struct node *temp=NULL;
   temp=(struct node *) malloc( sizeof(struct node ));
   temp->val=num;
   if(l->head == NULL){
      l->head=temp; 
      l->tail=temp;
      return;
   }

   l->head->prev=temp;
   temp->next=l->head;
   l->head=temp;
}


//Function Description:pushes a node to the end of the list
//Pre-condition:l-take our list, can be empty
//num-the value to input into our list
//Post-Condition:l-has a new node at the back, whose val is num
//return:none
void push_back(struct list * l, int num){

   struct node *temp=NULL;
   temp=(struct node *) malloc( sizeof(struct node ));
   temp->val=num;
   if(l->tail == NULL){
      l->head=temp;
      l->tail=temp;
      return;
   }
   l->tail->next=temp;
   temp->prev=l->tail;
   l->tail=temp;


}


//Function Description:sort list smallest to biggest
//Pre-condition:l-unsorted list
//Post-Condition:l-sorted list values from smallest to biggest
//return:none
void sort_ascending(struct list *l){
   struct node *temp1=NULL;
   struct node *temp2=NULL;
   int value;
   temp1=l->head;
   temp2= l->head;

   while(temp1!=NULL){

      while(temp2!=NULL){
	 if(temp1->val<temp2->val){
	    value=temp1->val;
	    temp1->val=temp2->val;
	    temp2->val=value;
	 }
	 temp2=temp2->next;
      }
      temp1=temp1->next;
      temp2=l->head;
   }
}


//Function Description:sort list biggest to smallest
//Pre-condition:l-smallest to biggest
//Post-Condition:l-sorted list biggest to smallest
//return:none
void sort_descending(struct list *l){
   struct node *temp1=NULL;
   struct node *temp2=NULL;
   int value;
   temp1=l->head;
   temp2= l->head;

   while(temp1!=NULL){

      while(temp2!=NULL){
	 if(temp1->val>temp2->val){
	    value=temp1->val;
	    temp1->val=temp2->val;
	    temp2->val=value;
	 }
	 temp2=temp2->next;
      }
      temp1=temp1->next;
      temp2=l->head;
   }
}

//Function Description:insert a new node into a location in the list, 
//start at 0 from the front to 1+ the number of nodes(add to the end);
//Pre-condition:l-our linked list
//n-the value to add to the list
//loca-the location in the list to add the new node
//Post-Condition:l-contains the new node in the desired location
//return:none
void insert(struct list *l,int n, int loca){
   struct node *temp=NULL;
   struct node *itt=NULL;
   int l_l;//length of t
   int i=1;
   temp=(struct node *) malloc( sizeof(struct node ));
   temp->val=n;

   l_l=length(*l);
//   printf("L is %d \n",l_l);

   if(loca==1){
  //    printf("in head");
      l->head->prev=temp;
      temp->next=l->head;
      l->head=temp;
      return;
   }
   printf("length is: %d\n",l_l);
   if(loca == (l_l+1)){

      printf("in tail");
      l->tail->next=temp;
      temp->prev=l->tail;
      l->tail=temp;
      temp->next=NULL;
      return;
   }
   itt=l->head;
   while(itt!=NULL){
      if((loca)==i){
	 temp->prev=itt->prev;
	 temp->next=itt;
	 itt->prev->next=temp;
	 itt->prev=temp;
	 return;
      }
      itt=itt->next;
      i++;

   }


}

//Function Description:remove a desired node 
//Pre-condition:l-our linked list
//num- the value of the node that we want to remove
//Post-Condition:l-our linked list with one less node
//return:none
void remove_val(struct list *l, int num){
   struct node *temp=NULL;//to hold head or tail temperarly
   struct node *temploop=NULL;//to go through list
   int x;
   x=1;
   //check to see number delete is head
   while(l->head->val==num){
      if(l->head->val==num){
	 temp=l->head->next;
	 free(l->head);
	 l->head=temp;
	 l->head->prev=NULL;
      }
   }

   //check to see number delete is tail
   while(l->tail->val==num){
      if(l->tail->val==num){
	 temp=l->tail->prev;
	 free(l->tail);
	 l->tail=temp;
	 l->tail->next=NULL;
      }
   }

   //deleted number in the middle of list
   temploop=l->head;
   while(temploop!=NULL){
      if(temploop->val==num){
	 temp=temploop->next;
	 temploop->prev->next=temploop->next;
	 temploop->next->prev=temploop->prev;
	 free(temploop);
	 temploop=NULL;//delete maybe
	 temploop=temp;
      }else{
	 temploop=temploop->next;
      }
   }

}




//Function Description:remove all nodes from the list,and free any dynamic memory used
//to so there is no memory leaks
//Pre-condition:l-our linked list
//Post-Condition:l-empty list
//return:none
void clear(struct list *l){
   struct node *temp = NULL;

   temp=l->head;
   while(temp != NULL){

      l->head=temp->next;
      free(temp);

      temp=l->head;

   }

}

