#include <iostream>

using namespace std;

class Base {
public:
	Base(){
		cout<<"Base Constructor\n";
	}

	virtual ~Base() {
		cout<<"Base Destructor\n";
	}
};

class Derieved : public Base {
public:
	Derieved() {
		cout<<"Derieved Constructor\n";
	}

	~Derieved() {
		cout<<"Derieved Destructor\n";
	}
};

int main(){
	Base* bptr = new Derieved(); 
	delete bptr;

	return 0;
}