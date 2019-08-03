/*
 **Program: Assignmnet #2  numbers.cpp
 **Author: Andrew Collins
 **Date: 05 October 2015
 **Description:  Assignment #2 is a continuation of assignment #1.
		 The program will still ask for a 
		base 10 number from 0-15 and output it in hexadecimal, octal, and binary; But 
		this time the program will check the users input and makes sure it is a good
		base 10 number between greater than 0, 
		and if not it will spit out an error and ask the user
		for another number.
 **Input: Decimal number greater than 0.
 **OutPut: Octal, hexadecimal, and binary number. Or error message if input value does 
	   not meet conditions
 */

#include <iostream>
#include <climits> //header defines limits of integral types.
#include <string>//library for object type string
#include <cstdlib>//library that has atoi(); function used to convert string to int 

using namespace std;

int main(){


	bool master_loop = false;
	//loop until user input 0 then master_loop = true and program ends
	while(master_loop == false){
		string s;//will hold users input for base 10 number

		bool loop1 = false;//variable condition for first loop that gets user input base 10
		// good input loop1 = true bad input loop1 = false 

		//loop asks user for base 10 number greater than 0, if good input loop1 == true loop ends, 
		// if bad input loop1 == false Error and user is aske for another correct input		 
		while( loop1 == false){
			cout<<"--------------------------------------------------------------------------"<<endl;
			cout << "Please enter a base 10 whole number greater than 0: " ;
			getline(cin , s); //takes everything user enters, a line of text. 
			cout<<endl;
			loop1 = true;//setting loop1 to true for good input loop ends, will change to false during test, if bad input


			/*Start: Test for bad values entered by user:------------------------------------------------------------------- */

			//If/else checks to see if user entered anything.
			if(s.length()<1){	
				cout<<"You did not enter anything."<<endl;
				cout<<endl;
				loop1 = false;//bad input loop continues
			}
			else{
				//loops through each char of string and check to see if it is a number 0-9
				//loop ends when reaches end of string 
				//used s.length()-1 because length() dosnt start at 0
				for(int x=0;x <= s.length()-1;x++){  
					if(!(s.at(x) >= '0' && s.at(x) <= '9')){
						cout<<"Error:Bad input, You did not enter a number greater than 0."<< endl;
						cout<<endl;
						loop1 = false;//bad input loop continues
					}

				}  	
			}	
			/*End: Test for bad values if loop1= false loop continues-------------------------------------------------------*/
		}//end while loop1

		string t;//will store input for conversion number. 2(binary),8(octal), or 16(hexadecimal)

		bool loop2= false;//if user input is bad, loop2 =false else loop2 = true
		int boh;//will hold 2,8,or 16; binary,octal or hexadecimal choices
		//loop2 asks user to enter 2(binary),8(octal), or 16(hexadecimal)
		//If bad input loop continues.
		while( loop2 == false){
			cout<<"Would you like to convert to binary, octal, or hexadecimal ?"<<endl;
			cout<<"Enter the number 2 for binary, 8 for octal, or 16 for hexadeciml: ";
			getline(cin,t);//takes everything user enter saves to t
			cout<<endl;

			loop2=true;//setting loop2 to true, for good input loop ends, will change to false during test, if bad input

			/*Start test for bad values entered by user:--------------------------------------------------------------------*/

			//IF/ElSE checks to see if user entered anything
			if(t.length()<1){
				cout<<"You did not enter anything."<<endl;
				cout<<endl;
				loop2 = false;
			}
			else{
				//loops though char of string to check and see if input is a number 0-9
				//then checks if input is 2, 8 or 16.
				//loop ends when reaches end of string
				//used s.length()-1 because length() dosnt start at 0
				for(int y=0;y <= t.length()-1;y++){
					if(!(t.at(y) >= '0' && t.at(y) <= '9')){
						cout<< "Error: Bad input, you did not enter a number 2, 8, or 16."<<endl;
						cout<<endl;
						loop2=false;
					}
				}
			}	

			//part two of test checks if number enterd is 2, 8, 0r 16.
			if(loop2 != false){
				boh = atoi(t.c_str());//converts string to int, stored in boh

				if(boh == 2 || boh == 8 || boh == 16 ){//checks if input value is 2, 8, or 16
					loop2 = true;//if number 2, 8, or 16
				}		
				else{ 
					loop2 = false;//if number not 2,8, or 16
					cout<<"Error:--- Please enter only 2, 8, or 16."<<endl;
					cout<<endl;
				}
			}
			/*End test for bad values-------------------------------------------------------------------------------------*/
		}//end while loop2



		int num = atoi( s.c_str());//convert inputted value base 10 number to convert, from string to int

		//converting to octal boh(value entered by user) is 8
		if(boh == 8){
			cout<<"Inputted value "<< num <<" as Octal number: "<< oct  << num << endl;//using oct argument we can print inputted value as octal
			
		}
		else if( boh == 16){
			cout<<"Inputted value "<< num <<" as hexadecimal number:"<< hex << num << endl;//using hex argument we can print inputted as hexidecaiml
		}	
		else if( boh == 2){
			/* To convert to binary the original number is divide by 2, 
			   the remainder (got by using the remainder operation %) which is 
			   1 or 0 is saved in the b4 , the answer is divided again by 2 the 
			   remainder is saved in b3, these steps are repeated again for 
			   b2 and b1. Then the binary conversion of the user inputed number is
			   printed out: b1 b2 b3 b4.  -------------------------------------------------------------------------------------- */

			int array_size = 0;//variable to store array size of binary array
			int con = num;//temp variable holds base 10 number inputted by user.

			//loop finds the 2^x power of base ten number by dividing by 2 until we get 0
			//, this x is the array size or number of bits used
			while( con >= 1){	
				con=con/2;
				array_size++;
			}		
				
			//check that the array size is in intrvals of 4
			//so when we print out binary value it is easy to read (0001) instead of 1
			if(array_size%4 >= 0){	
				//adds to the array size till it is divisible by 4
				while((array_size+1)%4 >0){
					array_size++;
				}
			}

			int binary[array_size];//declares an array to hold binary digits
			int d = num;//saves base 10 number inputted by user to d
			int c = 0;//counter condition for while loop

			//loop takes base ten number and divides by 2 remainder is pushed into array,
			//answer is divided by 2 again and remainder is put in array again. this is done till answer is 0.
			while( c <= array_size){
				binary[c]=d%2;//remainder pushed in array
				d = d / 2;//base ten number divide by 2
				c++;//add 1 to counter
			}

			//printing out binary value loop
			//prints out values from the array.
			cout<<"Inputted value "<< num <<" as binary is: "<< endl;
			for(int z =0; z <= array_size; z++)
			{
				cout<< binary[array_size - z];
				if(((array_size-z)%4 == 0))//puts a space after every 4 binary values printed
				{cout<<" ";}

			}
			cout<<endl;

		}
		cout<<dec<<endl;//changes cout argument back to decimal
		cout<<endl;
			
		string u;//used to save users input
		bool loop3= false;//if user input is bad, loop3 =false else loop3 = true
		int prg_loop;//will hold 0 or 1, 1 repeat program 0 no
		//loop3 asks user if they want to enter another number. 
		//If bad input loop continues.
		while( loop3 == false){
			cout<<"Would you like to enter another number? Enter 0 for no and 1 for yes: ";
			getline(cin,u);//takes everything user enter saves to u
			cout<<endl;

			loop3=true;//setting loop3 to true, for good input loop ends, will change to false during test, if bad input

			/*Start test for bad values entered by user:--------------------------------------------------------------------*/

			//IF/ElSE checks to see if user entered anything
			if(u.length()<1){
				cout<<"You did not enter anything."<<endl;
				loop3 = false;
			}
			else{
				//loops though char of string to check and see if input is a number 0-9
				//then checks if input is 0 or 1.
				//loop ends when reaches end of string
				//used u.length()-1 because length() dosnt start at 0
				for(int q=0;q <= u.length()-1;q++){
					if(!(u.at(q) >= '0' && u.at(q) <= '9')){
						cout<< "Error: Bad input, you did not enter a number 0 or 1."<<endl;
						loop3=false;
					}
				}
			}	

			//part two of test checks if number enterd is 0 or 1.
			if(loop3 != false){
				prg_loop= atoi(u.c_str());//converts string to int, stored in prg_loop

				if(prg_loop== 0 || prg_loop == 1 ){//checks if input value is 0 or 1
					loop3 = true;//if number 0 or 1
				}		
				else{ 
					loop3 = false;//if number not 0 or 1
					cout<<"Error:--- Please enter only 0 or 1."<<endl;
					cout<<endl;
				}
			}
			/*End test for bad values-------------------------------------------------------------------------------------*/
		}//end while loop3

		//IF/Else if 1 user wants to enter another number start program back at top. else end.
		if(prg_loop == 1){
			master_loop = false;
		}
		else{
			master_loop = true;
		}

	}//end master loop.
	return 0;
}
