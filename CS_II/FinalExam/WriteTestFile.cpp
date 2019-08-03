#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
using namespace std;

int main(){


   ofstream outfile;
   string filename;
   int num=1;
   //cout<<"Enter number of values:";
   //cin>> num;
   //cout<<"Enter file name:";
   //cin>>filename;

   cout<<endl;
   srand(time(NULL));

   for(int f=0;f<15;f++){
   stringstream ss;
      ss<<num;
      filename =ss.str()+".txt";
      cout<<filename<<endl;
      outfile.open(filename.c_str());
      for(int i=0;i<num;i++){


	 outfile<<rand()%10000;
	 outfile<<"\n";


      }

      outfile.close();
      num=num*2;
   }


   return 0;
}
