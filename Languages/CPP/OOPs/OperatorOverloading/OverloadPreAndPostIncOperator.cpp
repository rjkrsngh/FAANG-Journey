#include <iostream>

using namespace std;

//The compiler differenciates between pre and post increment operation using the argument it receives

class Int{
	int elem;

public:
	Int(int val) : elem{val} {}

	Int operator ++(){
		std::cout<<"PreIncrement invoked\n";
		++elem;
		return *this;
	}

	Int operator ++(int oldVal){
		std::cout<<"PostIncrement invoked\n";
		Int obj = *this;
		++(*this);
		return obj;
	}

	void PrintVal(){
		cout<<"Elem: "<<elem<<endl;
		return;
	}
};

int main(){
	Int val{10};
	cout<<"Using PreIncrement Operator\n";
	++val;
	val.PrintVal();

	cout<<"Using PostIncrement Operator\n";
	val++;
	val.PrintVal();

	return 0;
}