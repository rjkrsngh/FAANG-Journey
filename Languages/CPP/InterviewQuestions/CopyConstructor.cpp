#include <iostream>

using namespace std;

class Test { 
	int x;
public:
	Test(): x{0} {
		std::cout<<"Non parameterized constructor called\n";
	}
	Test(int x) : x{x} {
		std::cout<<"Parameterized constructor called\n";
	}
	Test(const Test& obj){
		std::cout<<"Inside copy constructor\n";
		x = obj.x;
	}

	void operator=(const Test& obj){
		std::cout<<"Assignment operator called\n";
	}

	void PrintVal(){
		std::cout<<"x is: "<<x<<std::endl;

		return;
	}
};

int main(){
	Test obj1;

	Test obj2 = obj1;
	Test obj3(5);
	Test obj4 = obj3;

	return 0;
}