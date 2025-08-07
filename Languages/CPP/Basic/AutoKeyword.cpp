#include <iostream>
#include <typeinfo>

using namespace std;

// auto keyword is basically used for type deduction

class Base {
	public:
		Base() {};
		void func(){
			cout<< "Hello\n";
		}
};

int main(){
	int i = 4;
	float f = 10.9;
	Base* b = new Base();
	b->func();
	
	auto i1 = 6;
	auto f1 = 2.9;
	auto b1 = new Base();
	
	cout<< typeid(i).name() << endl;
	cout<< typeid(f).name() << endl;
	cout<< typeid(b).name() << endl;
	
	cout<< typeid(i1).name() << endl;
	cout<< typeid(f1).name() << endl;
	cout<< typeid(b1).name() << endl;
	
	return 0;
}