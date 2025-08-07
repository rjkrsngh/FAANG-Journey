#include <iostream>

using namespace std;

class Parent{
public:
	int _a=0;
};

class Child1: public virtual Parent{
public:
	int _b=0;
};

class Child2: public virtual Parent{
public:
	int _c=0;
};

class GrandChild: public Child1, public Child2{
public:
	int _d=0;
};

int main(){
	GrandChild gd;
	gd._a = 5;
	return 0;
}