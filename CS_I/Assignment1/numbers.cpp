/*
 **Program: numbers.cpp
 **Author: Andrew Collins
 **Date:28 September 2015
 **Description: In this program the user will input a number in decimal format,
		the program will output the given number as an octal, hexadecimal,
		and binary number. The program will also output the maximum and minimum
		values for signed and unsigned numbers of types of int.
 **Input: Decimal number.
 **OutPut: Octal, hexadecimal, and binary number.
	  Also maximum and minimum values of signed and unsigned numbers.
 */

#include <iostream>
#include <climits> //header defines limits of integral types.
using namespace std;

int main(){

	/* Printing out the max and min values for signed and unsigned numbers using the macros 		for each from climts library*/
	cout<< "Minimum value for objest type signed int: " << INT_MIN << endl;
	cout<< "Maximum value for object type signed int: " << INT_MAX << endl;
	cout<< "Maximum value for object type unsigned int: " << UINT_MAX << endl;
	cout<< "Minimum value for Object type signed short int: "<< SHRT_MIN << endl;
	cout<< "Maximum value for object type signed short int: "<< SHRT_MAX << endl;
	cout<< "Maximum value for object type unsigned short int: "<< USHRT_MAX << endl;
	cout<< "Minimum value for object type signed long int: "<< LONG_MIN << endl;
	cout<< "Maximum value for object type signed long int: "<< LONG_MAX << endl;
	cout<< "Maximum value for object type unsigned long int: "<< ULONG_MAX << endl;

	int num; //variable used to store inputted number from user.
	
	/* b1 b2 b3 b4 are variables used to hold binary conversion of 
 	 decimal number, values in variables will be 0 or 1*/
	int b1, b2, b3, b4;

	
	cout << "Please enter a number between 0 and 15: " ;
	cin >> num; //takes value entered from user and stores in num.
	
	/* Using oct and hex arguments lets up print the inputted number as 
 	an Octal and hexadecimale number. */
	cout<<"Inputted value as Octal number: "<< oct  << num << endl;
	cout<<"Inputted value as hexadecimal number:"<< hex << num << endl;
	cout<< dec <<endl;// changes cout argument back to decimal	
	
	/* To convert to binary the original number is divide by 2, 
 	the remainder (got by using the remainder operation %) which is 
	1 or 0 is saved in the b4 , the answer is divided again by 2 the 
	remainder is saved in b3, these steps are repeated again for 
	b2 and b1. Then the binary conversion of the user inputed number is
	printed out: b1 b2 b3 b4.   */
	
	b4 = num % 2;
	num = num / 2;
	b3 = num % 2;
	num = num / 2;
	b2 = num % 2;
	num = num / 2;
	b1 = num % 2;

	cout<< "Inputted value in binary: "<< b1 << b2 << b3 << b4 << endl;
	
	
	return 0;
}
