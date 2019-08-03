//Program: class_schedule.cpp
//Author: Andrew Collins
//Description:This program is a schedular to multiple students class schedules.For example is you want all the schedules of students in cs 161.
//the program will promt the user for how many student schedules they would like to enter.the for each student if will ask for the number of classes they 
//are taking and all info associated with the classes(names,days, time).The user will the be able to pick a student and view their schedule(by name, day, time, all).
//the program requirements and conditions are in the test plan.
//Input:
//Number of students/schedules you want to input.
//Each Student name, class names, class days and class times. 
//Output:
//User will choose how the want to view a sudents schedule(name, day, time, all). 
//Due:Sunday December 2th 2015
#include <iostream>
#include <string>
#include <cstdlib>
#include <locale>

using namespace std;

bool error(int e_num);
bool check_number(string num);



//Struct name:Student_info 
//Description:this struct has variable that will hold the student first name,student  last name, 
//and the numbers of classes the student is taking 
struct Student_info{
   string first_name, last_name;
   int num_class;
};
//Struct name:Course_info
//Description:
//struct that holds all the students class info: class name, number of days each class(ex:1 day a week,5 days a week)
//the actual days (ex:mon, wed ,fri),the days as an integer(1-Mon,2-Tue,3-Wed,4-Thu,5-Fri),the class start time in 24 hr time (ex:13:00, 09:00),
//and the class end time(ex:15:00,08:00).
struct Course_info{
string class_name;
int num_days;
string *days;//dynamic array of day for each class (ex mon, tue ,wed)
int *days_as_int;
string start_time;//,start_min;//holds the hr and min the class starts
string end_time;//,end_min;//holds the hr and the min the class ends
};

//Funtions Declarations: funtion descriptions are above the function defenition
void schedule_info(Course_info **&S_class_info,Student_info *&S_info);
int get_decision();
void dele(Course_info **&S_class_info,Student_info *S_info,int num_students);
int get_num_students();
void get_student_info(int num_students,Course_info **S_class_info,Student_info S_info[]);

void get_student_name(Student_info S_info[], int s_num );
void get_student_first_name(string &first_name,int s_num);
bool compare_s_name(Student_info *S_info,string new_f_name,string new_l_name,int s_num);
void get_student_last_name(string &last_name,int s_num);
bool name_check(string name);//checks any string type that can only have letters (ex:student name and day name)
string name_caps(string &name);
void get_student_num_classes(Student_info S_info[], int s_num );

void get_class_info(Course_info **S_class_info,Student_info S_info[],int student_num);
void get_class_name(Course_info **S_class_info,Student_info s_info[],int c_num,int s_num);
bool check_class_name(string c_name);
bool check_class_unique(int c_num,int s_num,Course_info **S_class_info);
void get_class_num_days(Course_info **S_class_info,Student_info s_info[],int c_num,int s_num);
void get_class_days(Course_info **S_class_info,Student_info s_info[],int c_num,int s_num,int num_days);
void get_one_day(string &day,int &day_int,int day_num);
bool check_day(string &day,int &day_int);
bool mon(string &day,int &day_int);
bool tue(string &day,int &day_int);
bool wed(string &day,int &day_int);
bool thu(string &day,int &day_int);
bool fri(string &day,int &day_int);

bool get_class_time(Course_info **S_class_info,Student_info S_info[],int c_num,int s_num);
void  get_start_time(string &start_time);
void  get_end_time(string &end_time);
int return_time(string t);
bool class_conflict(Course_info **S_class_info,int c_num,int s_num);
bool time_con(Course_info **S_class_info,int cnow_sTime,int cnow_eTime,int c,int s_num);
bool stime_etime(string stime, string etime);
bool check_valid_time(string time);
bool check_time_length(string time);
bool check_colon(string time);
bool  check_time_hrs(string time);
bool  check_time_mins(string time);

int print_functions(Course_info **S_class_info,Student_info *S_info,int num_students );
void p_students_info(Student_info *S_info,int num_students);
void get_student_num(int &student_numb,int num_students);
void how_print_info(int student_num,int &how_print_numb);
void  print_s_info(int student_num,int how_print_num,Course_info **S_class_info,Student_info *S_info);
void print_by_name(int student_num,Course_info **S_class_info,Student_info *S_info);
void print_by_day(int student_num,Course_info **S_class_info,Student_info *S_info);
void pget_student_class_days(string class_days[],int student_num,Course_info **S_class_info,Student_info *S_info);
void print_by_time(int student_num,Course_info **S_class_info,Student_info *S_info);
void p_get_by_time(string classes[], int student_num,Course_info **S_class_info,Student_info *S_info);
void print_by_all(int student_num,Course_info **S_class_info,Student_info *S_info);
void del(string **&t_times);
void print_class_and_time(string **&t_times,int day_classes,int d,int num_classes,Course_info **S_class_info,int student_num);
void classes_per_day_all(int *day,int student_num,Course_info **S_class_info,Student_info *S_info);
void put_classes_in_day(string **&t_time,int *day,int student_num,Course_info **S_class_info,Student_info *S_info);
void put_times_order(string **&t_times,int *day);
void replace(string *temp,string **&t_times,int *day,int d);
void print_f(Course_info **S_class_info,Student_info S_info[],int student_num);


//Function name:main()
//Description:This function is the main funtion of class_schedule.cpp, the function declares 2 points ,(1 2-d points,a dn 1 1-D), 
//that will hold the students info and each students clas info.
//Pre-conditoin:none
//Pos-conditions:none
//Return:returns 0 to end program
int main(){
   Course_info **S_class_info;//hold each students class info
   Student_info *S_info;//holds each students info

   schedule_info(S_class_info,S_info);



   return 0;
}

//Function name:error()
//Description:when this function is called it meat the user has bad input, the
//function prints the type or error and returns false always
//Precondition:
//int e_num: this folds a positive integer whole number that is asociated the users error
//Postcondition:none
//return:always returns false;
bool error(int e_num){
   switch(e_num){
      case 399: cout<<"Error: You did not enter anything!"<<endl;
		return false;
      case 400: cout<<"Error: Invalid Input!"<<endl;
		return false;
      case 200: cout<<"You did not enter the days in order"<<endl;
	       return false;	
   }
}
//Function name:check_number()
//Description:This function recieves an input from the user as a string then it check that 
//string to see if all values in the sting are a number.
//Precondition:
//string num: holds the users input to be check(good values are positive whole numbers)
//Postcondition:none
//return:return true if all values int the string are positive whole numbers, if not returns false 
bool check_number(string num){

   for(int i=0;i<num.length();i++)
     if(!(num.at(i)>='0' && num.at(i)<='9')){
	 //error(400);
	 return false;
      }
   return true;
}

//Function name:schedule_info()
//Description:This function is where the program gets all the information for the program 
//(number of students, each students info, and each students class info)
//it also will print this info and check to see if user want to continue with the program or end
//if the usere want to start over or exit it delets all the dyanimic arrays.
//Precondition:
//Course_info S_class_info: will holds each students class information 
//(string class name, pos int number of days,string class days,pos int class days, string class start time, string class end time) 
//Student S_info:will hold eash student info (string student first name, string student last name, pos int number of classes each student is taking) 
//Postcondition:
//Course_info S_class_info:  holds each students class information 
//(string class name, pos int number of days,string class days,pos int class days, string class start time, string class end time) 
//Student S_info:hold each student info (string student first name, string student last name, pos int number of classes each student is taking) 
//return:none
void schedule_info(Course_info **&S_class_info,Student_info *&S_info){
   int decision;   
   do{
   int  num_students=get_num_students();
  S_class_info=new Course_info*[num_students];
  S_info=new Student_info[num_students];
   get_student_info(num_students,S_class_info,S_info);
   system("clear");
 decision=print_functions(S_class_info,S_info,num_students);
if (decision==2 || decision==3){ dele(S_class_info,S_info,num_students);}
   }while(decision==2);
}
//
//Function name:
//Description:
//Pre-conditoin:
//Course_info S_class_info: holds each students class information 
//(string class name, pos int number of days,string class days,pos int class days, string class start time, string class end time) 
//Student S_info:hold eash student info (string student first name, string student last name, pos int number of classes each student is taking) 
//Pos-conditions:
//Course_info S_class_info: array delete memory freed
//Student S_info: array delete memory freed
//Return:none
void dele(Course_info **&S_class_info,Student_info *S_info,int num_students){
   for(int s=0;s<num_students;s++)
      for(int c=0;c<S_info[s].num_class;c++){
	 delete []S_class_info[s][c].days;
	 delete []S_class_info[s][c].days_as_int; 
      }
   for(int s=0;s<num_students;s++)
      //for(int c=0;c<S_info[s].num_class;c++)
	 delete []S_class_info[s];


   delete[]S_class_info;
   delete[]S_info;


}
//Function name:get number of students
//Description:this function gets the number of student in the classs that user will input info for.
//Precondition:none
//Postcondition:none
//return:pos inte holds number of student to input schedule for
int get_num_students(){
   string num_s;
   bool GoodNum;//true if good number else false
   do{
      cout<<"Enter the number of students in class(0 < number <= 200): ";
      getline(cin,num_s);
      GoodNum=num_s.length()>0? check_number(num_s):error(399);
      GoodNum=((GoodNum==true)&&(atoi(num_s.c_str())>0 && atoi(num_s.c_str())<=200)) ? true:error(400);
   }while(GoodNum==false);
   return atoi(num_s.c_str());
}

//Function name:get_stident_info()
//Description:this function will get each student first name, last name, and number of classes they are takeing
//Pre-conditoin:
//Course_info S_class_info: will holds each students class information 
//(string class name, pos int number of days,string class days,pos int class days, string class start time, string class end time) 
//Student S_info:will hold eash student info (string student first name, string student last name, pos int number of classes each student is taking) 
//Pos-conditions:
//Course_info S_class_info:holds each students class information 
//Student S_info:holds eash student info (string student first name, string student last name, pos int number of classes each student is taking) 
//Return:none
void get_student_info(int num_students,Course_info **S_class_info,Student_info S_info[]){

   for(int s=0;s<num_students;s++){
      get_student_name(S_info,s);
      get_student_num_classes(S_info,s);
      get_class_info(S_class_info,S_info,s);
   }
}
//
//Function name:get_student_name()
//Description:the function will get and check the students first and last name
//Pre-conditoin:
//Student S_info:will holds eah student info (string student first name, string student last name, pos int number of classes each student is taking) 
//int s_num:the sudent we are getting name for
//Pos-conditions:
//Student S_info:holds each student name info (string student first name, string student last name, pos int number of classes each student is taking) 
//Return:none
void get_student_name(Student_info S_info[], int s_num ){
   bool GoodName=true;
   do{
      get_student_first_name(S_info[s_num].first_name,s_num);
      get_student_last_name(S_info[s_num].last_name,s_num);
      if(s_num>0){
	 GoodName=compare_s_name( S_info,S_info[s_num].first_name,S_info[s_num].last_name,s_num);
      }
   }while(GoodName==false);
}
//
//Function name:compare _s_name
//Description:this function check to sees that you do not enter the same students name twice
//Pre-conditoin:
//Course_info S_class_info:holds each students class information 
//Student S_info:holds eash student info (string student first name, string student last name, pos int number of classes each student is taking) 
//Pos-conditions:none
//Return:returns false if you have entered a students name twice,else returns true
bool compare_s_name(Student_info *S_info,string new_f_name,string new_l_name,int s_num){
   for(int sn=0;sn<s_num;sn++){
      if(new_f_name.compare(S_info[sn].first_name)==0 ||new_f_name.compare(S_info[sn].first_name)==0){
	 cout<<"Student "<<s_num<<" cannot have the same last or first name as student "<<sn<<" ."<<endl;
	 return false;
      }
   }
   return true;
}
//
//Function name:get_student_first_name()
//Description:this function get the students first name
//Pre-conditoin:
//int s_num: pos int values that holds the number associated to a student
//string first_name:empty,will hold students first name
//Pos-conditions:
//string first_name:hold students first name
//int s_num:none pos int values that holds the number associated to a student
//Return:none
void get_student_first_name(string &first_name,int s_num){
   bool GoodNum;
   do{
      cout<<"Enter Student "<<s_num+1<<" first name: ";
      getline(cin,first_name);
      GoodNum=first_name.length()>0 ? name_check(first_name):error(400);
      if(GoodNum==true){name_caps(first_name);}

   }while(GoodNum==false);
}

//
//Function name:get_last_name()
//Description:this function gets the students last name
//Pre-conditoin:
//int s_num: pos int values that holds the number associated to a student
//string last_name:empty,will hold students last name
//Pos-conditions:
//string last_name:hold students last  name
//Return:none
void get_student_last_name(string &last_name,int s_num){
   bool GoodName;
   do{
      cout<<"Enter Student "<<s_num+1<<" last name: ";
      getline(cin,last_name);
      GoodName=last_name.length()>0 ? name_check(last_name):error(400);
      if(GoodName==true){last_name=name_caps(last_name);}

   }while(GoodName==false);

}

//Function name:name_caps()
//Description:this function will take any string passed to it and capatilize any alphabets and return that string
//Pre-conditoin:
//string name: and string with lower case letters or nums
//Pos-conditions:
//string name:all letters in string have been capatilized
//Return:returns capatilized string
string name_caps(string &name){
   locale loc;
   for(string::size_type i=0;i<name.length();i++){
      name[i]=toupper(name[i],loc);
   }

   return name;

}
//
//Function name:name_check()
//Description:this function checks any sting to make sure it only has letters in it
//Pre-conditoin:
//string name:any string to be checked
//Pos-conditions:none
//Return:true if string only has letter in it, else false
bool name_check(string name){
   for(int n=0;n<name.length();n++){
      if(!((name.at(n)>='A' && name.at(n)<='Z')||(name.at(n)>='a' && name.at(n)<='z'))){
	 return error(400);
      }

   }
   return true;
}
//
//Function name:get_student_num_classes()
//Description:this function get the number of classes each student i taking
//Pre-conditoin:
//Student S_info:will hold each students info (string student first name, string student last name, pos int number of classes each student is taking) 
//Pos-conditions:
//Student S_info:holds each students number of classes info (string student first name, string student last name, pos int number of classes each student is taking) 
//Return:none
void get_student_num_classes(Student_info S_info[], int s_num ){
   string num_classes;
   bool GoodNum;
   do{
      cout<<"Student "<<s_num+1<<" ("<<S_info[s_num].first_name<<") :"<<"how many classes do you need to schedule( 0<number<=8):";
      getline(cin,num_classes);

      GoodNum=num_classes.length()>0? check_number(num_classes):error(399);
      GoodNum=((GoodNum==true)&&(atoi(num_classes.c_str())>0 && atoi(num_classes.c_str())<=8)) ? true:error(400);
   }while(GoodNum==false);
   S_info[s_num].num_class=atoi(num_classes.c_str());
}


//Function name:get_class_info
//Description:this function will get the info for each class(class name, number of days,actual days, actual days as int, and class start and end times).
//Pre-conditoin:
//Course_info S_class_info: will holds each students class information 
//(string class name, pos int number of days,string class days,pos int class days, string class start time, string class end time) 
//Student S_info:holds each student info (string student first name, string student last name, pos int number of classes each student is taking) 
//int student_num:current student number 
//Pos-conditions:
//Course_info S_class_info: will holds each students class information 
//(string class name, pos int number of days,string class days,pos int class days, string class start time, string class end time) 
//Return:none
void get_class_info(Course_info **S_class_info,Student_info S_info[],int student_num){
   bool GoodClass;
   S_class_info[student_num]=new Course_info[S_info[student_num].num_class];

   for(int c=0;c<S_info[student_num].num_class;c++){
      do{
	 get_class_name(S_class_info,S_info,c,student_num);
	 get_class_num_days(S_class_info,S_info,c,student_num);
	 get_class_days(S_class_info,S_info,c,student_num,S_class_info[student_num][c].num_days);
	 GoodClass=get_class_time(S_class_info,S_info,c,student_num);
      }while(GoodClass==false);
   }


}

//Function name:get_class_name
//Description:this gets the class name
//Pre-conditoin:
//int s_num:current student number 
//int c_num:current class number 
//Course_info S_class_info: will holds each students class name  information 
//(string class name, pos int number of days,string class days,pos int class days, string class start time, string class end time) 
//Student S_info:holds each student info (string student first name, string student last name, pos int number of classes each student is taking) 
//Pos-conditions:
//Course_info S_class_info: holds each students class name  information 
//(string class name, pos int number of days,string class days,pos int class days, string class start time, string class end time) 
//Return:none
void get_class_name(Course_info **S_class_info,Student_info s_info[],int c_num,int s_num){
   bool GoodName;
   do{
      cout<<"Student "<<s_num+1<<"- Enter class "<<c_num+1<<" name:";
      getline(cin,S_class_info[s_num][c_num].class_name);
      GoodName = S_class_info[s_num][c_num].class_name.length()>0 ? check_class_name(name_caps(S_class_info[s_num][c_num].class_name)):error(359);
      GoodName = (GoodName==true && check_class_unique(c_num,s_num,S_class_info)==true)? true:false;
   }while(GoodName==false);
}

//Function name:check_class_unique() 
//Description:this function check to see if the user entered the same class twice for a student
//Pre-conditoin:
//int s_num:current student number 
//int c_num:current class number 
//Course_info S_class_info: holds each students class name  information 
//(string class name, pos int number of days,string class days,pos int class days, string class start time, string class end time) 
//Pos-conditions:none
//Return:true if class name is unique, else false if classname mathces previous classes
bool check_class_unique(int c_num,int s_num,Course_info **S_class_info){

   if(c_num>0)
      for(int c=0;c<c_num;c++){
	 if(S_class_info[s_num][c_num].class_name.compare(S_class_info[s_num][c].class_name) == 0){
	    cout<<"Error:You have already entered this class!"<<endl;
	    return false;
	 }
      }
   return true;

}

//
//Function name: check_class_name()
//Description:this functins check to see if the first char in the string (class name) is a alphabet
//Pre-conditoin:string c_name: hold a class name.
//Pos-conditions:none
//Return:ture is first char in string is a alphabet, else false
bool check_class_name(string c_name){

   if(((c_name.at(0)>='A' && c_name.at(0)<='Z')||(c_name.at(0)>='a' && c_name.at(0)<='z'))){
      for(int n=0;n<c_name.length();n++){
	 if(!((c_name.at(n)>='A' && c_name.at(n)<='Z')||(c_name.at(n)>='a' && c_name.at(n)<='z')||(c_name.at(n)>='0' && c_name.at(n)<='9'))){
	    return error(400);

	 }
      }
   }else{return error(400);}
   return true;
}
//Function name:get_class_number_days()
//Description:this function gets the number of day a week you have a class
//Pre-conditoin:
//int s_num:current student number 
//int c_num:current class number 
//Course_info S_class_info: holds each students class information 
//(string class name, pos int number of days,string class days,pos int class days, string class start time, string class end time) 
//Student S_info:holds each student info (string student first name, string student last name, pos int number of classes each student is taking) 
//Pos-conditions:
//Course_info S_class_info: holds each students each class number of day   information 
//(string class name, pos int number of days,string class days,pos int class days, string class start time, string class end time) 
//Return:none
void get_class_num_days(Course_info **S_class_info,Student_info s_info[],int c_num,int s_num){
   string c_num_days;
   bool GoodNum;
   do{
      cout<<S_class_info[s_num][c_num].class_name<<": How many days a week? (1-5)";
      getline(cin,c_num_days);
      GoodNum=c_num_days.length()>0? check_number(c_num_days):error(399);
      GoodNum=((GoodNum==true)&&(atoi(c_num_days.c_str())>0 && atoi(c_num_days.c_str())<=5)) ? true:error(400);
   }while(GoodNum==false);
   S_class_info[s_num][c_num].num_days=atoi(c_num_days.c_str());
}
///////////
//Function name:get_clas_days()
//Description:this function gets each day you have each class
//Pre-conditoin:
//int s_num:current student number 
//int c_num:current class number
//int num_days: hold how many days you have a class 
//Course_info S_class_info: holds each students class information 
//(string class name, pos int number of days,string class days,pos int class days, string class start time, string class end time) 
//Student S_info:holds each student info (string student first name, string student last name, pos int number of classes each student is taking) 
//Pos-conditions:
//Course_info S_class_info: holds the days you have each class (ex: mon,tue,wed,thu,fri) information 
//(string class name, pos int number of days,string class days,pos int class days, string class start time, string class end time) 
//Return:none
void get_class_days(Course_info **S_class_info,Student_info s_info[],int c_num,int s_num,int num_days){
   bool DayOrder=false;
   S_class_info[s_num][c_num].days=new string[num_days];
   S_class_info[s_num][c_num].days_as_int=new int[num_days];

   while(DayOrder==false){
      DayOrder=true;
      cout<<"Please enter the days in order"<<endl;
      for(int d=0;d<num_days && DayOrder==true ;d++){
	 get_one_day(S_class_info[s_num][c_num].days[d],S_class_info[s_num][c_num].days_as_int[d],d);
	 if(d>0)
	    DayOrder=(S_class_info[s_num][c_num].days_as_int[d-1] >= S_class_info[s_num][c_num].days_as_int[d]) ? error(200):true;
      }
   }
}

//Function name:get_one_day()
//Description:this fuction get usere input of each day you have a class
//User may enter 3 letter abbreviation of day, first letter of day (where thursday is R),or the whole name of day.
//Pre-conditoin:
//string day:empyt
//int day_int: empty
//int day_num:holds the location (o,1,2)where the day will go in an array
//Pos-conditions:
//string day:holds the day you have a class, as a string(ex: mon,tue,wed)
//int day_int: holds the day you have a class, as a pos int (ex: 1-mon,2-tue,3-wed,4-thu,5-fri)
//Return:none
void get_one_day(string &day,int &day_int,int day_num){
   bool GoodDay;
   do{

      cout<<"Enter Day "<<day_num+1<<":";
      getline(cin,day);
      GoodDay= ((day.length()>0) && name_check(name_caps(day))==true ) ? check_day(day,day_int) :error(359);
   }while(GoodDay==false);

}
//Function name:check_day()
//Description:this function check to see if the user entered a valid iput for day(ex:wed,w,Mon,M,Monday)
//Pre-conditoin:
//string day:holds user input for day
//int day:empty
//Pos-conditions:
//string day:holds user input for day as a full worda and all caps
//int day:holds day as an int (1-MON,2-tue)
//Return:if usere entered day in rigth format(3 letter abbrivation of day, day fully spelled out, or first letter of day(thu=R,r) return true else false
bool check_day(string &day,int &day_int){
   bool GoodDay;
   return (mon(day,day_int)==true ||  tue(day,day_int)==true|| wed(day,day_int)==true || thu(day,day_int)==true || fri(day,day_int)==true)? true: error(400);
}


//Function name:mon()
//Description:this fuction cheks if user entered mon
//Pre-conditoin:
//string day:holds user input for day 
//int day:empty
//Pos-conditions:
//string day:holds user input for "MONDAY" as a full worda and all caps
//int day:holds day as an int 1 for Monday
//Return:true if day is monday
bool mon(string &day,int &day_int){
   if(day.compare("MON") ==0 || day.compare("MONDAY")==0 ||  day.compare("M")==0){
      day="MONDAY"; 
      day_int=1;
      return true;
   }
}
//Function name:tue()
//Description:this fuction cheks if user entered tue
//Pre-conditoin:
//string day:holds user input for day 
//int day:empty
//Pos-conditions:
//string day:holds user input for "TUESDAY" as a full worda and all caps
//int day:holds day as an int 2 for Tuesday
//Return:true id day is tuesday,else false
bool tue(string &day,int &day_int){
   if(day.compare("TUE") ==0 || day.compare("TUESDAY")==0 ||  day.compare("T")==0){
      day="TUEDSDAY"; 
      day_int=2;
      return true;
   }
}
//Function name:wed()
//Description:this fuction cheks if user entered wed
//Pre-conditoin:
//string day:holds user input for day 
//int day:empty
//Pos-conditions:
//string day:holds user input for "WEDNESDAY" as a full worda and all caps
//int day:holds day as an int 3 for wednesday
//Return:ture if day is,wednesday,else false
bool wed(string &day,int &day_int){
   if(day.compare("WED") ==0 || day.compare("WEDNESDAY")==0 || day.compare("W")==0){
      day="WEDNESDAY"; 
      day_int=3;
      return true;
   }
}
//Function name:thu()
//Description:this fuction cheks if user entered thu
//Pre-conditoin:
//string day:holds user input for day 
//int day:empty
//Pos-conditions:
//string day:holds user input for "THURSDAY" as a full worda and all caps
//int day:holds day as an int 4 for thursday
//Return:true if day is thurday, else false
bool thu(string &day,int &day_int){
   if(day.compare("THU") ==0 || day.compare("THURSDAY")==0 || day.compare("R")==0){
      day="THURSDAY"; 
      day_int=4;
      return true;
   }
}
//Function name:fri()
//Description:this fuction cheks if user entered fri
//Pre-conditoin:
//string day:holds user input for day 
//int day:empty
//Pos-conditions:
//string day:holds user input for "Friday" as a full worda and all caps
//int day:holds day as an int 5 for Friday
//Return:true id day is friday,else false
bool fri(string &day,int &day_int){
   if(day.compare("FRI") ==0 || day.compare("FRIDAY")==0 || day.compare("F")==0){
      day="FRIDAY"; 
      day_int=5;
      return true;
   }
}

//Function name:get_class_time()
//Description:this function gets the start and end times of a class
//Pre-conditoin:
//int s_num:current student number 
//int c_num:current class number
//Course_info S_class_info: holds each students class information 
//(string class name, pos int number of days,string class days,pos int class days, string class start time, string class end time) 
//Student S_info:holds each student info (string student first name, string student last name, pos int number of classes each student is taking) 
//Pos-conditions:
//Course_info S_class_info: holds each students class start and end time information 
//(string class name, pos int number of days,string class days,pos int class days, string class start time, string class end time) 
//Return:true if the class start and end time is valid, else false
bool get_class_time(Course_info **S_class_info,Student_info S_info[],int c_num,int s_num){
   bool GoodTime=true,GoodClass;
   do{
      get_start_time(S_class_info[s_num][c_num].start_time);
      get_end_time(S_class_info[s_num][c_num].end_time);
      GoodTime=stime_etime(S_class_info[s_num][c_num].start_time,S_class_info[s_num][c_num].end_time);
      GoodClass=(GoodTime==true && c_num>0 )? class_conflict(S_class_info,c_num,s_num):GoodTime; 
   }while(GoodTime==false);

   return GoodClass;

}
//
//Function name:class_conflict()
//Description:this function check to see if a class time conflicts with a different class time
//Pre-conditoin:
//int s_num:current student number 
//int c_num:current class number
//Course_info S_class_info: holds each students class information 
//(string class name, pos int number of days,string class days,pos int class days, string class start time, string class end time) 
//Pos-conditions:none
//Return:true if no coflictin times, else false
bool class_conflict(Course_info **S_class_info,int c_num,int s_num){
   int pc_start,pc_end ,cnow_start,cnow_end;
   cnow_start=return_time(S_class_info[s_num][c_num].start_time);
   cnow_end=return_time(S_class_info[s_num][c_num].end_time);

   for(int c=0;c<c_num;c++){
      for(int ccd=0;ccd<S_class_info[s_num][c_num].num_days;ccd++){

	 for(int pcd=0;pcd<S_class_info[s_num][c].num_days;pcd++){
	    if(S_class_info[s_num][c_num].days_as_int[ccd]==S_class_info[s_num][c].days_as_int[pcd]){
	       if(time_con(S_class_info,cnow_start,cnow_end,c,s_num)==false){
		  return false;
	       }
	    }
	 }
      }
   }
   return true;
}


//Function name:time_conflict()
//Description:this is a sub function of the previous function class_conflict()
//Pre-conditoin:
//int cnow_sTime: holds the start time of the class currently being inputted by the user
//int cnow_eTime: holds the end time of the class currently being inputted by the user
//Course_info S_class_info: holds each students class information 
//(string class name, pos int number of days,string class days,pos int class days, string class start time, string class end time) 
//Pos-conditions:none
//Return:ture if no time conflict, else false
bool time_con(Course_info **S_class_info,int cnow_sTime,int cnow_eTime,int c, int s_num){
   int pc_start,pc_end;

   pc_start=return_time(S_class_info[s_num][c].start_time);
   pc_end=return_time(S_class_info[s_num][c].end_time);
   if((cnow_sTime>=pc_start && cnow_sTime<=pc_end)||(cnow_eTime>=pc_start && cnow_eTime<=pc_end)){
      cout<<"Erroe:This class has a conflicting time!"<<endl;
      return false;
   }
   return true;
}
//
//Function name:return_time()
//Description:this function extracts the number in a time(10:00->1000) and returns it as a whole number int 
//Pre-conditoin:
//string t:time value to extract
//Pos-conditions:none
//Return:returns the time value as a po whole number int
int return_time(string t){
   string time,hrs,mins;
   hrs.append(t,0,2);
   mins.append(t,3,2);
   time=hrs+mins;
   return atoi(time.c_str());

}
//Function name:stime_etime()
//Description:this function checks to see if the start time is greater of equal o the end time of a function
//Pre-conditoin:
//string stime:holds start time of a class as a string
//string etime:holdds end time of a class as a string
//Pos-conditions:none
//Return:false if class start time is greater that or equal to end time, else true
bool stime_etime(string stime, string etime){
   int start_time=return_time(stime);
   int end_time=return_time(etime);

   if(start_time >= end_time){
      cout<<"Error: Class start time (" << stime <<")"<<" greate or equal end time ("<<etime<<"). "<<endl;
      return false;

   }
   return true;

}

//
//Function name:get_start_time()
//Description:this function gets and checks the start time of a class
//Pre-conditoin:
//string start_time: empty
//Pos-conditions:
//string start_time: holds the valid start time of a class entered by user 
//Return:none
void get_start_time(string &start_time){
   bool Goodtime;
   string s_time;//rename
   do{
      cout<<"Enter Start hour and start minute (00:00 to 23:59):";
      getline( cin,s_time);//rename

      Goodtime=check_valid_time(s_time);
   }while(Goodtime==false);
   start_time=s_time;

}

//
//Function name:get_end_time()
//Description:this function gets the valid end time of a class entered by user
//Pre-conditoin:
//string end_time:empty
//Pos-conditions:
//string end_time: holds valid end time from user
//Return:none
void get_end_time(string &end_time){
   string e_time;
   bool Goodtime;
   do{
      cout<<"Enter end hour and end min (00:00 to 23:59):";
      getline(cin,e_time);
      Goodtime=check_valid_time(e_time);
   }while(Goodtime==0);
   end_time=e_time;
}
//Function name:check_valid_time()
//Description:this function checks to see if a user entered a valid start and end time
//time is entered as length=5 , 3 char =":", only single whole numbers in location 0,1,3,4, and 0000<=time<2400   
//Pre-conditoin:
//string time: holds the class end or start time
//Pos-conditions:
//none
//Return:true if time is valid, else false
bool check_valid_time(string time){
   bool bool_time=false;
   //length must equal 5
   bool_time= check_time_length(time);
   if(bool_time==true){//check location 3 of string must be":"
      bool_time=check_colon(time);
      if(bool_time==true){
	 bool_time=check_time_hrs(time);//==true;
	 if(bool_time==true){
	    bool_time=check_time_mins(time);//==true;
	 }
      }
   }

   return bool_time;

}

//Function name:check time length
//Description:this function check to see if the time inputted is of string length 5
//Pre-conditoin:
//string time: holds the start or end time of a class
//Pos-conditions:none
//Return:ture if string length is 5,else false
bool check_time_length(string time){
   if(time.length()==5){
      return true;
   }
   return error(400);
}
//
//Function name:check_colon() 
//Description:this function checks to see the the 2 location of the time string has a ":"
//Pre-conditoin:
//string time: holds the start or end time of a class
//Pos-conditions:
//Return:return true if the 2 loction of the time string is  a ":"
bool check_colon(string time){
   if(time.at(2)==':'){
      return true;
   }
   return error(400);
}
//
//Function name:check_time_hrs()
//Description:the first 2 char of the time string are the hrs this function checks to see that these characters are each numbers(0-9)and that the 00>hrs<24
//Pre-conditoin:
//string time: holds the start or end time of a class
//Pos-conditions:none
//Return:returns true if the first 2 chars of the time string are valid hrs.
bool check_time_hrs(string time){
   string hrs;
   hrs.append(time,0,2); 
   for(int h=0;h<hrs.length();h++){
      if(!(hrs[h]>='0'&& hrs[h]<='9')){
	 return error(400);
      }
   }
   if(!(atoi(hrs.c_str())>=0 && atoi(hrs.c_str())<24)){
      return error(400);
   }
   return true;
} 

//Function name: check_time_mins()
//Description:this function checks to see that the last 2 chars the mins, are each numbers(0-9) and that the 0<mins<60
//Pre-conditoin:
//string time: holds the start or end time of a class
//Pos-conditions:none
//Return:true if valid mins conditions are met, else false
bool check_time_mins(string time){
   string mins;
   mins.append(time,3,2);
   for(int m=0;m<mins.length();m++){
      if(!(mins[m]>='0'&& mins[m]<='9')){
	 return error(400);
      }
   }
   if(!(atoi(mins.c_str())>=0 && atoi(mins.c_str())<60)){
      return error(400);
   }
   return true;
}



////////////////////////////////////////////////////////////////////////////////////////////////
//Function name:print_functions()
//Description:this function takes care of all the view options the user can choose from
//Pre-conditoin:
//int num_student: this holds the total number of schedules/students inputted
//Course_info S_class_info: holds each students class information 
//(string class name, pos int number of days,string class days,pos int class days, string class start time, string class end time) 
//Student S_info:holds each student info (string student first name, string student last name, pos int number of classes each student is taking) 
//Pos-conditions:none
//Return:return 2 if users want to start over and enter new students/schedules, returns 3 if user want to exit the program
int print_functions(Course_info **S_class_info,Student_info *S_info,int num_students ){
   int student_num,how_print_num,decision;
   do{
      p_students_info(S_info,num_students);
      get_student_num(student_num,num_students);
      how_print_info(student_num,how_print_num);
      print_s_info(student_num,how_print_num,S_class_info,S_info);
      decision=get_decision();
   }while(decision==1);
   return decision;

}
//
//Function name:get_decision()
//Description:this function get the uses choice, if they want to exit the program(3), redo the whole program(2), or view another
//students schedule.
//Pre-conditoin:none
//Pos-conditions:none
//Return:the users choice 1,2,3
int get_decision(){
   bool GoodNum;
   string decision_num;
   do{
      cout<<"Do you want to 1-view another student classes,2-make a new set of schedules,or 3-exit:";
      getline(cin,decision_num);
      GoodNum=decision_num.length()>0? check_number(decision_num):error(399);
      GoodNum=((GoodNum==true)&&(atoi(decision_num.c_str())>0 && atoi(decision_num.c_str())<=3)) ? true:error(400);
   }while(GoodNum==false);
   return atoi(decision_num.c_str());

}
//Function name:p_students_info
//Description:this function prints each students number, first name ,and last name.
//Pre-conditoin:
//int num_students: holds the number of students/schedules user entered
//Student S_info:holds each student info (string student first name, string student last name, pos int number of classes each student is taking) 
//Pos-conditions:none
//Return:none
void p_students_info(Student_info *S_info,int num_students){
   for(int s=0;s<num_students;s++){

      cout<<"Student "<<s+1<<" : "<<S_info[s].first_name<<" "<<S_info[s].last_name<<endl;
   }
}
//
//Function name:get_student_num
//Description:this function get the users choice of which students schedule they would like view
//Pre-conditoin:
//int student_numb:empty
//int num_students: holds the total avaliabe students/schedules
//Pos-conditions:
//int student_numb:hold the useres choice of which students schedule they would like to view 0<student_numb<num_students
//Return:none
void get_student_num(int &student_numb,int num_students){
   bool GoodNum;
   string student_num;
   do{
      cout<<"Which students schedule would you like to see?(enter student number):";
      getline(cin,student_num);
      GoodNum=student_num.length()>0? check_number(student_num):error(399);
      GoodNum=((GoodNum==true)&&(atoi(student_num.c_str())>0 && atoi(student_num.c_str())<=num_students)) ? true:error(400);
   }while(GoodNum==false);
   student_numb=atoi(student_num.c_str())-1;
}

//Function name:how_print_info()
//Description:this function will get the users choice of how the want to view a student schedule(number:1-name,2-day,3-time,4-all)
//Pre-conditoin:
//int num_students: holds the total avaliabe students/schedules
//int how_print_numd:empty
//Pos-conditions:
//int how_print_numd:hold the users choice of how they would like to view a schedule
//Return:none
void how_print_info(int student_num,int &how_print_numb){
   string how_print_num;
   bool GoodNum;
   do{
      cout<<"How do you want to view student "<<student_num+1<<" classes?(number:1-name,2-day,3-time,4-all):";
      getline(cin,how_print_num);
      GoodNum=how_print_num.length()>0? check_number(how_print_num):error(399);
      GoodNum=((GoodNum==true)&&(atoi(how_print_num.c_str())>0 && atoi(how_print_num.c_str())<=4)) ? true:error(400);
   }while(GoodNum==false);
   how_print_numb=atoi(how_print_num.c_str());
}

//
//Function name:print_s_info()
//Description:this function takes the users choice of how to view a schedule and call the approiate function
//Pre-conditoin:
//int how_print_numd:hold the users choice of how they would like to view a schedule(1-name,2-days,3-time,4-all)
//int student_num: holds student/schedules number to view
//Course_info S_class_info: holds each students class information 
//(string class name, pos int number of days,string class days,pos int class days, string class start time, string class end time) 
//Student S_info:holds each student info (string student first name, string student last name, pos int number of classes each student is taking) 
//Pos-conditions:none
//Return:none
void  print_s_info(int student_num,int how_print_num,Course_info **S_class_info,Student_info *S_info){

   if(how_print_num==1){//by name
      print_by_name(student_num,S_class_info,S_info);
   }else if(how_print_num==2){//by day
      print_by_day(student_num,S_class_info,S_info);

   }else if(how_print_num==3){//by time
      print_by_time(student_num,S_class_info,S_info);

   }else if(how_print_num==4){//by all
      print_by_all(student_num,S_class_info,S_info);

   }
}
//print
//Function name:
//Description:prints the name of the classes the student is taking
//Pre-conditoin:
//int student_num: holds student/schedules number to view
//Course_info S_class_info: holds each students class information 
//(string class name, pos int number of days,string class days,pos int class days, string class start time, string class end time) 
//Student S_info:holds each student info (string student first name, string student last name, pos int number of classes each student is taking) 
//Pos-conditions:none
//Return:none
void print_by_name(int student_num,Course_info **S_class_info,Student_info *S_info){
   cout<<"Student "<<student_num+1<<" ("<<S_info[student_num].first_name<<" "<<S_info[student_num].last_name<<") "<<"classes are:"<<endl;
   for(int c=0;c<S_info[student_num].num_class;c++){
      cout<<S_class_info[student_num][c].class_name<<endl;
   }

}
//
//Function name:print_by_day()
//Description:this function print the days the student has classes
//Pre-conditoin:
//int student_num: holds student/schedules number to view
//Course_info S_class_info: holds each students class information 
//(string class name, pos int number of days,string class days,pos int class days, string class start time, string class end time) 
//Student S_info:holds each student info (string student first name, string student last name, pos int number of classes each student is taking) 
//Pos-conditions:none
//Return:none
void print_by_day(int student_num,Course_info **S_class_info,Student_info *S_info){
   string class_days[]={" "," "," "," "," "};

   pget_student_class_days(class_days,student_num,S_class_info,S_info);
   cout<<"Student "<<student_num+1<<" ("<<S_info[student_num].first_name<<" "<<S_info[student_num].last_name<<") "<<"has classes on:"<<endl;
   for(int d=0;d<5;d++){
      if(!(class_days[d].compare(" ")==0)){
	 cout<<class_days[d]<<endl;
      }
   }   

}

//Function name:pget_student_class_days()
//Description:this function figures out which days the student has classes
//Pre-conditoin:
//string class_days[]: this array has ' ' in each location.(empty)
//int student_num: holds student/schedules number to view
//Course_info S_class_info: holds each students class information 
//(string class name, pos int number of days,string class days,pos int class days, string class start time, string class end time) 
//Student S_info:holds each student info (string student first name, string student last name, pos int number of classes each student is taking) 
//Pos-conditions:
//string class_days[]:if the student has classes on a certion day of the week, then the corresponrion locatin on the array will get filled with the 
//day in question, (array: 0-mon,1-tue,3-wed,4-thu,5-fri
//Return:none
void pget_student_class_days(string class_days[],int student_num,Course_info **S_class_info,Student_info *S_info){
   for(int d_str=0;d_str<5;d_str++){
      for(int num_c=0;num_c<S_info[student_num].num_class;num_c++){
	 for(int num_d=0;num_d<S_class_info[student_num][num_c].num_days;num_d++){
	    if((S_class_info[student_num][num_c].days_as_int[num_d] - 1) == d_str){
	       class_days[d_str]=S_class_info[student_num][num_c].days[num_d];	
	    }
	 }

      }
   }
}
//Function name:print_by_time()
//Description:this function will print each class and the start and end time of that class
//Pre-conditoin:
//int student_num: holds student/schedules number to view
//Course_info S_class_info: holds each students class information 
//(string class name, pos int number of days,string class days,pos int class days, string class start time, string class end time) 
//Student S_info:holds each student info (string student first name, string student last name, pos int number of classes each student is taking) 
//Pos-conditions:none
//Return:none
void print_by_time(int student_num,Course_info **S_class_info,Student_info *S_info){
   string *classes;//will holds the class name and start time,end time, int oreder 
   classes=new string[S_info[student_num].num_class];//size is the numder of classes a student is taking

   p_get_by_time(classes,student_num,S_class_info,S_info);
   cout<<"Student "<<student_num+1<<"classes by time are: "<<endl;
   for(int c=0;c<S_info[student_num].num_class;c++){
      cout<<classes[c]<<endl;
   }

   delete []classes;

}

//Function name:p_get_by_time
//Description:this function arranger the classes by time, earliest class to lates class
//Pre-conditoin:
//int student_num: holds student/schedules number to view
//Course_info S_class_info: holds each students class information 
//(string class name, pos int number of days,string class days,pos int class days, string class start time, string class end time) 
//Student S_info:holds each student info (string student first name, string student last name, pos int number of classes each student is taking) 
//string classes:empty array
//Pos-conditions:
//string classes:array will hold the classes name, start time and end time in order from earliest clas to latest class 
//Return:none
void p_get_by_time(string classes[], int student_num,Course_info **S_class_info,Student_info *S_info){
   for(int cc=0;cc<S_info[student_num].num_class;cc++){
      int c_spot_A=0;
      for(int c_comp=0;c_comp<S_info[student_num].num_class;c_comp++){
	 if(return_time(S_class_info[student_num][cc].start_time) > (return_time(S_class_info[student_num][c_comp].start_time))){
	    c_spot_A++;
	 }
      }
      classes[c_spot_A]=S_class_info[student_num][cc].class_name + ": " + S_class_info[student_num][cc].start_time + "-" +S_class_info[student_num][cc].end_time;
   }
}

//Function name:print_by_all()
//Description:this functin print the schedule, with all the avalianle information(class name, class days, class times)
//Pre-conditoin:
//int student_num: holds student/schedules number to view
//Course_info S_class_info: holds each students class information 
//(string class name, pos int number of days,string class days,pos int class days, string class start time, string class end time) 
//Student S_info:holds each student info (string student first name, string student last name, pos int number of classes each student is taking) 
//Pos-conditions:none
//Return:none
void print_by_all(int student_num,Course_info **S_class_info,Student_info *S_info){
   int day[]={0,0,0,0,0};
   string **t_times ,s_day[]={"MONDAY","TUESDAY","WEDNESDAY","THURSDAY","FRIDAY"};
   t_times=new string*[5];
   classes_per_day_all(day,student_num,S_class_info,S_info);
   put_classes_in_day(t_times,day,student_num,S_class_info,S_info);
   for(int d=0;d<5;d++){//d= days mon tue
      cout<<s_day[d]<<": "<<day[d]<<" classes."<<endl;
      if(day[d]>0){//day[d]= num of classes that day
	 print_class_and_time(t_times,day[d],d,S_info[student_num].num_class,S_class_info,student_num);
      }
   }
   del(t_times);
}
//
//Function name:del()
//Description:this function delets the array we created to hold the class information by time
//Pre-conditoin:
//string t_times:array holds the classes information by earliest time to lastes time
//Pos-conditions:
//string t_times:point array id deleted and memory is freed
//Return:none
void del(string **&t_times){
   for(int i=0;i<5;i++){
      delete[]t_times[i];
   }
   delete[]t_times;

}

//Function name:print_class_and_time()
//Description:this function is a sub function for print_by_all()
//this print the classes name and times 
//Pre-conditoin:
//int day_classes:this holds the number of classes each day
//int d:this olds the day to print (0-mon,1-tue,2-wed,3-thu,4-fri)
//int student_num: holds student/schedules number to view
//Course_info S_class_info: holds each students class information 
//(string class name, pos int number of days,string class days,pos int class days, string class start time, string class end time) 
//Student S_info:holds each student info (string student first name, string student last name, pos int number of classes each student is taking) 
//Pos-conditions:none
//Return:none
void print_class_and_time(string **&times_t,int day_classes,int d,int num_classes,Course_info **S_class_info,int student_num){
   string temp_t;
   for(int t=0;t<day_classes;t++){
      for(int c=0;c<num_classes;c++){
	 temp_t=times_t[d][t];
	 if(temp_t.compare(S_class_info[student_num][c].start_time)==0){
	    cout<<S_class_info[student_num][c].class_name<<": "<<S_class_info[student_num][c].start_time<<"-"<<S_class_info[student_num][c].end_time<<endl;
	 }

      }
   }

}
//Function name:classes_per_day_all
//Description:this function will figure out the number of classes a student has per day
//Pre-conditoin:
//int day:empty array to hold the number of classses a student has on a day 
//int student_num: holds student/schedules number to view
//Course_info S_class_info: holds each students class information 
//(string class name, pos int number of days,string class days,pos int class days, string class start time, string class end time) 
//Student S_info:holds each student info (string student first name, string student last name, pos int number of classes each student is taking) 
//Pos-conditions:
//int day:array  holds the number of classses a student has on a day 
//Return:none
void classes_per_day_all(int *day,int student_num,Course_info **S_class_info,Student_info *S_info){
   int class_count;

   for(int d_str=0;d_str<5;d_str++){
      class_count=0;
      for(int num_c=0;num_c<S_info[student_num].num_class;num_c++){
	 for(int num_d=0;num_d<S_class_info[student_num][num_c].num_days;num_d++){
	    if((S_class_info[student_num][num_c].days_as_int[num_d] - 1) == d_str){
	       class_count++;
	    }
	 }
      }
      day[d_str]=class_count;
   }
}

//Function name:put_classes_in_day
//Description:this function get time for each class each day
//Pre-conditoin:
//string t_time:empty 2-d arry
//int day: hold the number of class each day(mon-fri)(0-8)
//int student_num: holds student/schedules number to view
//Course_info S_class_info: holds each students class information 
//(string class name, pos int number of days,string class days,pos int class days, string class start time, string class end time) 
//Student S_info:holds each student info (string student first name, string student last name, pos int number of classes each student is taking) 
//Pos-conditions:
//string t_time:holds the different classes per day in order of starting time
//Return:none
//gets times for classes each day
void put_classes_in_day(string **&t_times,int *day,int student_num,Course_info **S_class_info,Student_info *S_info){
   for(int d_str=0;d_str<5;d_str++){
      t_times[d_str]=new string[day[d_str]];
      int c=0;
      for(int num_c=0;num_c<S_info[student_num].num_class;num_c++){//class change
	 for(int num_d=0;num_d<S_class_info[student_num][num_c].num_days;num_d++){//day change
	    if((S_class_info[student_num][num_c].days_as_int[num_d] - 1) == d_str){
	       t_times[d_str][c].append(S_class_info[student_num][num_c].start_time);
	       c++;
	    }
	 }
      }
   }

   put_times_order(t_times,day);
}

//Function name:put_times_in_order()
//Description:this functin tates **time thas has start time of classes for each day and sorts the so the are in order of earliest to latesr
//Pre-conditoin:
//string times:2-d string array holds the time of ecch classes per day
//int day:array has the number of classes each day
//Pos-conditions:
//string times:2-d string array holds the time of each classes per day, in order from earliest to lates time
//Return:none
void put_times_order(string **&t_times,int *day){
   string *temp,time1,time2;

   for(int d=0;d<5;d++){//each day
      temp = new string [day[d]];

      for(int clas=0;clas<day[d];clas++){//each class on that day
	 int t_spot_A=0;//time locaion in array

	 for(int compare_time=0;compare_time<day[d];compare_time++){
	    time1=t_times[d][clas];
	    time2=t_times[d][compare_time];
	    if(return_time(time1) > return_time(time2)){
	       t_spot_A++;
	    }
	 }
	 temp[t_spot_A].append(t_times[d][clas]);
      }

      replace(temp,t_times,day,d);
      delete []temp;
   }
}
//Function name:replace()
//Description:this function takes the temp string with has the times in order and puts the in t_times
//Pre-conditoin:
//string temp:class time for a day in order
//string t_times:class time for a day not in order time
//int day:numer of classer per day
//int d: day in question
//Pos-conditions:
//string t_times:class time for a day in order of time
//Return:none
void replace(string *temp,string **&t_times,int *day,int d){

   for(int i=0;i<day[d];i++){
      t_times[d][i]=temp[i];
   }

}
/*
//
//Function name:
//Description:
//Pre-conditoin:
//Pos-conditions:
//Return:
void print_f(Course_info **S_class_info,Student_info S_info[],int student_num ){
   cout<<student_num<<endl;
   for(int s=0;s<student_num;s++){

      cout<<"Student name: "<<S_info[s].first_name<<" "<<S_info[s].last_name<<endl;
      cout<<"Number Of Classes: "<<S_info[s].num_class<<endl;
      for(int c=0;c<S_info[s].num_class;c++){
	 for(int d=0;d<S_class_info[s][c].num_days;d++){
	    cout<<S_class_info[s][c].days[d]<<endl;

	    cout<<S_class_info[s][c].class_name<<": "<<endl;

	 }
      }
   }
}
*/
