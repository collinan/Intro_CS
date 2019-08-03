/*
Program filename:my_math.cpp
Author: Andrew Collins
Date: 14 October 2015

Description: Program defines 5 math functions and calculates the summation or integration
of the given functions on an interval [a,b]. 
In the intergration part of the program you will use two ways to calculate integration
 rectangle vs trapezoid method, and be asked how many of each. 

Program input: 
Function being evaluated
Summation or intergration
rectangle or Trapezoid method to find area under function
Number of rectangles or trapezoids
Starting and ending points for integral or summation.
Function/ procedures for calculation the area
Number of rectangels and or trapezoids to use

Program output:
The function being evaluated
Starting and ending points of integral or summation
For integration: number of rectangles or/and trapezoids used
The area or summation calculated. 
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <iomanip>//used for seprecision();
using namespace std;


//utility functions
void print_functions(double x);
void print_q(string s);
void bad();
double ab(string d, string s);
double get_input(string i, string s);
bool check_input(string di, string s);
bool check_inputneg(string s);
void quit(string q);
bool anything(string s);


//Math functions
double integrate_trapezoid(double f, double a, double b, double num_traps);
double functions(double fun_num,double v );
double summations(double a, double b,double fun_num);
double integrate_rectangles(double fun_num, double a, double b, double num_rec);


/*
Function:int main()
Description: Main function of my_math.cpp, used to controll or call other functions,
		to get summation or integrations of functions
Pre-condition (parameters): none
Post-condition(paramaters being changed): none
Return: 0 to end program
*/
int main(){
   cout<<setprecision(10)<<endl;//set print values to 10 places after with it starts to round

do{
   string user_choice;//string holds all users function choice
   bool loop = false;//used for every loop, true loop ends/false bad input loop contunues

   double f_choice11 =0;//int holds users function choice, answer to first question
   double f_choice22 =0;//int holds users summation-1 or integration-2,answer to second question
   double f_choice33 =0;//int holds users rectangle-1 trapezoid-2 or both-3
   double f_choice332 =0;//holds number of trapezoids
   double f_choice331 =0;//holds number of rectangles
   double a=0;//holds starting point for summation and integration(rec or trap)
   double b=0;// holds ending point for summation and integration(rec or trap)
   double x=0;//hold function number to print(f1-f5)
   print_functions(x);//prints the function(f1-f5),if x is 0 it prints all functions

//This loop asks the users which function they want-----------------------------------------------
   while(loop == false){
      f_choice11 = get_input("i", "Choose a function (1-f1, 2-f2, 3-f3, 4-f4,5-f5: ");//asks ? -> calls check_input()-> returns-> any whole number positive  integer 
      if(f_choice11 >= 1 && f_choice11 <=5 ){//checks values entered is between 1-5, cause we only have functions 1-5
	 loop=true;//if values is 1-5 loop condition is true loop ends
      }else{bad();}//if not 0-5 loop continues and question is asked again
   }

//this loop ask what operation to do summation or integration---------------------------------------
   loop=false;//set loop condition to false, to enter loop
   while(loop == false){
      f_choice22 =get_input("i", "Which operation do you want (summation-1 or integration-2): ");//asks ? -> calls check_input()-> returns-> any whole number positive  integer 
      if(f_choice22 == 1 || f_choice22 == 2){//checks values entered is 1 or 2, cause we only have 2 operations
	 loop = true;//if values is 1-5 loop condition is true loop ends
      }else{bad();}//if not 1 or 2 loop continues and question is asked again
   }

//this loop ask what integration you want to do, rectangel or trapezoid--------------------------------
   loop=false;//set loop condition to false, to enter loop
   if(f_choice22 == 2)//if user chooses integration enter loop
      while (loop == false){
	 f_choice33 = get_input("i", "Would you like to caculate the area using the rectangle-1, trapezoid-2, or both-3: ");//asks ? -> calls check_input()-> returns-> any whole number positive  integer 
	 if(f_choice33 == 1 || f_choice33 == 2 || f_choice33 == 3){//checks value entered is 1 2 3 
	    loop = true;//if 1 2 3 loop condition is true, loop ends
	 }else{bad();}//if not 1 2 3 loop continues and question is asked again

      }

//this loop ask how may tapezoids?---------------------------------------------------------------
   if(f_choice33 ==2 || f_choice33 == 3){
      loop=false;//set false to enter loop
      while(loop==false){
	 f_choice332 = get_input("i","How many trapezoids do you want?(enter whole number integer greater than 0): ");
	 loop = true;// assume good intger value greater than= 0  loop set to true
	 if(f_choice332 <= 0){//check if # is greater than 0
	    bad();//print error
	    loop = false;// if #<=0 loop condtion is set to false questoin is asked again
	 }
      }

   }

//this loop asks how many rectangles-------------------------------------
   if(f_choice33 == 1 || f_choice33 == 3){
      loop=false;//set false to enter loop
      while(loop==false){
	 f_choice331 = get_input("i", "How many rectangles do you want?(enter whole number integer greater than 0): ");//asks ? -> calls check_input()-> returns-> any whole number positive  integer
	 loop = true;//assumes good interger greater than equal to 0 loop set to true
	 if(f_choice331 <= 0){//chesk # is greater that 0
	    bad();//print error
	    loop = false;//if #<=0 loop condition is set to false question is asked again
	 }
      }
   }
//this loop asks start and end values
   loop=false;//set to false to enter loop
   while (loop == false){
      string num_type;
	if(f_choice22==1){
	   num_type="i";
	}else{num_type="d";}
      a = get_input(num_type, "Please enter a starting point number, a = ");
      b = get_input(num_type, "Please enter a ending point number, b= ");
      loop = true;
      if(a == b){
	 bad();
	 cout<<" A cannot equal B."<<endl;
	 loop = false;
      }else if(a > b){
	 bad();
	 cout<<"A cannot be greater than B."<<endl;
	 loop = false;
      }
   }	

   if(f_choice22==1){

      cout<<"The summation of ";
      print_functions(f_choice11);//prints choosen functions(f1-f5)
      cout<<"between "<<a<<" and "<<b<<" is "<<summations(a,b,f_choice11)<<endl;
   }
   if(f_choice33 == 1 || f_choice33 == 3){
      cout<<"Rectangel: The area under";
      print_functions(f_choice11);
      cout<<"between "<<a<<" and "<<b<<" is "<< integrate_rectangles(f_choice11, a, b, f_choice331)<<endl;
   }


   if(f_choice33 == 2 || f_choice33 == 3){
      cout<<"Trapezoid: The area under";
      print_functions(f_choice11);
      cout<<"between "<<a<<" and "<<b<<" is "<<integrate_trapezoid(f_choice11, a, b,f_choice332)<<endl;
   }
}while(1>0);
   return 0;
}//end main------------------------------------------------------------------------------------



/*
Function:print_function(double);
Description: prints all the functions to screen at start of pogram, also prints the function used at the end
Pre-condition: double x-> holds the funcion being used (0-5), default prints all the function 
Post-condition:none
Return:nothing
*/

void print_functions(double x){
   switch(int(x)){//switch gets passed the function number user inputted and the prints out choosen function, default prints all functions
      case 1: cout<<" f1(x)=(2x^5)+(x^3)-(10x)+2 ";
	      break;
      case 2:	cout<<" f2(x)=(6x^2)-(x)+10 ";
		break;
      case 3:	cout<<" f3(x)=(5x)+3 ";
		break;
      case 4:	cout<<" f4(x)=(2x^3)+120 ";
		break;
      case 5:	cout<<" f5(x)=2x^2 ";
		break;
      default:
		cout<<"----------------------------------------------------"<<endl;
		cout<<" Function1: f1(x)=(2x^5)+(x^3)-(10x)+2 "<<endl;
		cout<<" Function2: f2(x)=(6x^2)-(x)+10 "<<endl;
		cout<<" Function3: f3(x)=(5x)+3 "<<endl;
		cout<<" Function4: f4(x)=(2x^3)+120 "<<endl;
		cout<<" Function5: f5(x)=2x^2 "<<endl;
		cout<<"----------------------------------------------------"<<endl;
		cout<<endl;
		cout<<"Enter quit at any time to quit the program"<<endl;
   }

}

/*
Function:bad()
Description:this function print an error message if user enters a invalid input when called by other functions
Pre-condition: none
Post-condition: none
Return:nothing
*/
void bad(){cout<<"Error: Bad input."<<endl;}//prints error message

/*
Function:anything(string);
Description:function is called to check if user inputted anyhting
Pre-condition: function gets passed a string that holds any input
Post-condition: none
Return:return true if user input something, if string is empty return false
*/
bool anything(string s){
   if(s.length()==0){
      cout<<"You did not enter anything."<<endl;
      return false;
   }

   return true;
}  

/*
Function: quit(string)
Description:functoin is called to check if user wants to quit program
Pre-condition: any string value inputted by user
Post-condition: none
Return:if user inputted "Quit" program ends (exit(0)), else nothing
*/
void quit(string q){

   if(q == "quit"){//check if values entered by user is quit
      cout<<"Goodbye."<<endl;//good bye message before program ends
      exit(0);//if user enters "quit", exit(0) is executed an program ends
   }

}
/*
Function:get_input(string, string)
Description:Used to get an input from user, also uses function check_input()
Pre-condition:  string s holds Question to ask, and string i holds the answer condition
("i"->value entered should be a whole number integer, "d"-> value entered can be a negative, decimal or negative decimal number)
Post-condition: none
Return: converts the string entered, if valid, to a number of type double passed back to main function
*/
double get_input(string i, string s){
   string input;//holds user input
   bool check =false;//loop condition false if bad input, true if good input
   while(check == false){
      print_q(s);//asks question
      getline(cin,input);//save user input in variable input
      
      check=anything(input);//calls anything() to check if user entered anything
      quit(input);//checks to see if user want to quits program
      if(check==true){//if user enters anything enters this if statement
	 check = check_input( i, input);//checks if user input is a valid number negative, decimal, or whole 
      }
   }

   return atof(input.c_str());//returns user input as a number negative, decimal or whole number
}

/*
Function:print_q(string)
Description: This function prints out questions that are passed to it as a string
Pre-condition: sting s that holds a questions. Ex: "Please enter a starting point a"
Post-condition:none, string n dosnt change
Return: nothing
*/ 
void print_q(string s){
   cout<<s;//prints question
   return;
}



/*
Function:check_input(string, string)
Description: This function is called by get input and is used to checked the users input, it check if user entered 
		a decimal, whole number integer, negative number, negative whole or decimal number.
Pre-condition: string s holeds the input of user, string di holds input condition, if"d"-decimal whole number, negative number , 
and negative decimal number,"i"- only positive whole number
Post-condition: none
Return:returns true if good input else returns false
*/
bool check_input(string di, string s){
   int x = 0;//counter for "for loop"
   int d=0;//counter that increment if possibe decimal number
   if(s.at(x)== '-' &&( di == "d" || di == "i")){//if first charcter is a negative symbal
      x++;//increment count to check other characters
   }//in first character of string is'-' add 1 to couter

   for( x ;x<s.length();x++){//loop checks the values of the string the make sure it is a # or 1 decimal point
      if(s.at(x) == '.' && di == "d" ){//checks if position is a decimal if value type (d) is decimal number
	 x++;//increment count to next character in string
	 d++;//sets decimal to cout to 1 so user never enter if statement again
	 if(d>1){//if sting has two decimal points enters, 
	    bad();//calls bad() and prints error
	    return false;//returns false  cause input is bad
	 }
      }
      if(!(s.at(x) >= '0' && s.at(x) <= '9')  ){//checks if charaters in string are not number (0-9)
	 bad();//if character is not a number prints error
	 return false;//returns false to where it was called cause bad input
      }
   }

   return true;//all conditions met sting is a good number(negative, or decimal, or whole number>0)

}


/*
Function:functions(double,doulbe);
Description: this function holds the 5 function in mathemitical form, to be evaluate when called on
Pre-condition: double fun_num-> holds function to evaluate. double v-> holds the value to be computed in f(x)
Post-condition: none
Return:number type double-> any positive or negative decimal number, computed in the function
*/
double functions(double fun_num,double v ){
   switch(int(fun_num)){//switch get passed function numerb to evaluate

      case 1:	 return 2*pow(v,5)+pow(v,3)-10*pow(v,1)+2*pow(v,0);//1st function
		 break;
      case 2: return 6*pow(v,2)-pow(v,1)+10*pow(v,0);//2nd function
	      break;
      case 3: return 5*pow(v,1)+3*pow(v,0);//3rd function
	      break;
      case 4: return 2*pow(v,3)+120*pow(v,0);//4th function
	      break;
      case 5: return 2*pow(v,2);//5th function
   }
}




/*
Function:summations(double,double,double)
Description: this function takes the sum of one of the f(X) on an interval,summation=f(a)+f(a+dx)...+f(a...+dx)
Pre-condition: double a-> starting value of summation interval whole positive number, 
double b-> ending value of summation interval whole positive number. double fun_num-> holds function to evaluate
Post-condition: none
Return:returns number, negative or decimal, or whole number
*/
double summations(double a, double b,double fun_num){
   double temp=0;//hold sumation value
   for(a;a<=b;a++)//loop to take sum of function on interval a-b
   {
      temp=functions(fun_num,a)+temp;//calls function evaluates it and add to total in temp
   }	
   return temp;//returns summation value
}


/*
Function:integrate_rectangles(double,double,double,double)
Description: functions gets area under a f(x) using rectangle method, area=dx*sum(f(a)+f(a+dx)..+f(d-dx))
Pre-condition: double fun_num-> whole positive number the functoin to evaluate, double a->frirst number in the interval ,
double b-> last number on the interval, double num_rec-> holds number of rectangles to use to divide interval
Post-condition:none
Return:double -> negative whole decimal number that holds the area under a f(x), computed using the rectangle method
*/

double integrate_rectangles(double fun_num, double a, double b, double num_rec){

   double temp=0;//stroes sum of all lengths of rectangles, f(x)+f(x+dx)..
   double dx =(b-a)/num_rec;//width of rectangles (delta x)


   int i = 0;//counter for while loop
   int n_rec=int(num_rec);//holds # of rectangle 
   while(i < n_rec){  //loop to get area under f(x)
      temp=temp+functions(fun_num,a);//calls funcions to get area under f(x)
//	temp=abs(temp);//deals with issue of adding negative number, so the area come out right
      a += dx;//being passed to functions() increment x by dx(width of rec) to go to nest rectangle
      i++;//loop counter increment
   }
   return dx*temp;//width * length( sum of all rectangles)
}

/*
Function:intergrate_trapezoid(double, double,double,double)
Description:  function get area under a f(X) using trapezoid method.area=dxsum(f(a)+f(a+dx)/2)+...f(a..+dx)+f(b)/2)
Pre-condition:  double fun_num-> whole positive number the functoin to evaluate, double a->frirst number in the interval ,
double b-> last number on the interval, double num_rec-> holds number of trapezoids to use to divide interval
Post-condition:none
Return:double -> negative whole decimal number that holds the area under a f(x), computed using the trapezoid method
*/
double integrate_trapezoid(double fun_num, double a, double b,double num_traps){
   double temp=0;//stores average length of all trapezoids, (f(x)+f(x+dx)/2)+((f(x+dx)+f(x+dx+dx))/2)+....
   double dx =( b-a)/num_traps;//width of trapezoids (delta x)	
   double y=b;//
	int i=0;//loop condition counter
   while(i<int(num_traps)){//loops till counter is less than number of trapezoids
      temp=temp + ((functions(fun_num,a)+functions(fun_num,(a+dx)))/2);//calls functions to get area under f(x)
     // temp=abs(temp);//deals with issue of addding negative numbers, so the area come out right
      i++;//loop condition incremented
      a += dx;//being passed to functions() increment x by dx(width of rec) to go to nest rectangle
   }
   return (dx)*temp;//width * length( sum of all trapezoid)
}


