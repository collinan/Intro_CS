//Program: test_list.c
//Author: Andrew Collins
//Date: 05/29/2016
//Description:this is the test_file.c, in this file contains our main function 
//and is used to set up our linked list by calling all the required function
//Input:
//Output:
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

int main(){

   char filename[20];//will hold the filename inputted by the user, to be used to initilize our list
   struct list l;//our linked list
   FILE *fileptr;//point to the file name
   char num[3],num2[5];//we will read positive integers 0-99 our list values
   int input[2];//input[0] value entered by user to add to list,and input[1] location to add value in list
 // int lll;//will hold the location the user will add a value

   printf("Enter filename: ");
   scanf("%s",filename);
   fileptr =fopen(filename,"r");//r-read only

   //continue reading values from the file until we are at the end of the file
   while(fscanf(fileptr,"%s", num)!=EOF)
   {

      //push to the front of list
      push_front(&l,atoi(num));

      //push to back of list,need to fix issue
     push_back(&l,atoi(num));

   }


   //printf("number is: %d",atoi(num));

   //print length of the list
   printf("The length of the list is:%d \n",length(l));
   //print the contents of the list
   print(l);

   printf("The head is:%d \n",l.head->val);
   printf("The tail is:%d \n",l.tail->val);

   printf("\n \n");
   //sort in ascending order
   printf("List in asending order:\n");
   sort_ascending(&l);
   //print the contents of the list
   print(l);


   printf("\n \n");
   //sort in descending order
   printf("List in desending order:\n");
   sort_descending(&l);
   //print the contents of the list
   print(l);

   //prompt user for the value/integer to remove from list
   printf("The head is:%d \n",l.head->val);
   printf("The tail is:%d \n",l.tail->val);
   printf("Enter value you would like to remove:");
   scanf("%s",&num);

   remove_val(&l,atoi(num));

   print(l);



   //promt user for item/int to add and location in the list
   printf("Enter value you would like to add:");
   scanf("%s",num);
   input[0] = atoi(num);
//   printf("%d \n",input[0]);
   printf("Enter location to add(1-%d):",(length(l)+1));
   scanf("%s",num);
   input[1]= atoi(num);

   //insert int into a specific location
   insert(&l,input[0],input[1]);
   //print the contents of the list
   print(l);

   //clear list - no memory leaks
clear(&l);
//close the file we read from
   fclose(fileptr);

   return 0;
}



