#include<iostream>

using namespace std;

/*Used to take away the constness or volatility of a variable
  It works only on when the type of initial and final pointer is same
  	Eg: const int* a;
  		int* p = cosnt_cast<int*>(a);

  	This will not work
  		const char* c;
  		int* p = const_cast<int*>(c) 
*/	

int main(){

}