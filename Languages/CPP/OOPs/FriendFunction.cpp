#include <iostream>

using namespace std;

// Either a class or a function be the friend of a class
// Friendship is neither inherited not mutual

class Test{
	int x;
	friend void func(Test&);
	public:
		Test(int x) : x{x} {};
		//friend void func(Test&);
		
};

void func(Test& obj){
	cout<< obj.x << endl;
	obj.x = 20;
	cout<< obj.x << endl;
}

int main(){
	Test t(10);
	func(t);
	
	return 0;
}