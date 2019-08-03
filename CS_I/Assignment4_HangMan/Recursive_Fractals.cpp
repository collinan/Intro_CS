//Program name:ecursive_Fractils()
//Author: Andrew Collins
//Date:8 Nov 2015
//Description: this is a program that print out a design using a recursive function call
//Input:none
//Out put: recursive design
#include<iostream>

using namespace std;
void pattern(int n, int i);
//Function name:main();
//Description: Main function of Recursice fractals
//Precondition: none
//Post condition : none
//return:  to end program
int main(){
   int n=8,i=0;
   pattern(n,i);


   return 0;
}
//Function name:pattern()
//Description: This function calls itsel recursively to print out a patters
//Pre conditions: n- is a power of 2 greater that 0,i- i+1is the colum where first start of patter ets printed
//post condition:  none, bot variables stay the same
//return:none
void pattern(int n,int i){

   if(n>0){//base case, to end recursive loop
      pattern(n/2,i++);//recursive call 1

      if(n>=1 && i>=1){//condiion to enter print loop
	 i=i%2!=0 ? i+1: i;//since i/2 can could be a decimale we add 1 to i so correct dimon is formed 
	 for(int k=0;k<((i/2));k++)//loop print out space
	    cout<<" ";
      }

      for(int x=0;x<n;x++)//loop to print out *
	 cout<<"* ";
      cout<<endl;

      pattern(n/2,i+n);//recursive call 2

   }
}


