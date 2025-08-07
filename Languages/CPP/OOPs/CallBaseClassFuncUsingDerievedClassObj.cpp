#include<iostream>

using namespace std;

/* This program helps us call methods from base class using objects of Derieved class.
   NOTE: This is done without the use of Polymorphism. */

class Base{
	int _x;
public:
	void func(){
		cout<<"from Base: "<<endl;
	}
};

class Derieved : public Base{
	int _y;
public:
	void func(){
		cout<<"from Derieved: "<<endl;
	}
};

int main(){
	Base b;
	Derieved d;

	//Method 1
	d.Base::func();

	//Method 2
	Base b1 = static_cast<Base>(d);
	b1.func();

	

	return 0;
}